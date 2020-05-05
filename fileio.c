#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char buf[] = "abcdefg";
char buf2[8];

int main(void)
{
    int fd;
    fd = open("file.txt", O_RDWR | O_APPEND | O_CREAT);
    if (fd < 0) {
        printf("open filed\n");
        exit(-1);
    }

    if (write(fd, buf, sizeof(buf)) != sizeof(buf)) {
        printf("write failed\n");
        exit(-1);
    }
    printf("write successful\n");
    lseek(fd, 0, SEEK_SET);
    if (read(fd, buf2, 8) == -1) {
        printf("read failed\n");
    }

    printf("read successful, %s\n", buf2);

    close(fd);

    return 0;
}