#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	printf("program starting\n");
	
	pid_t pid;
	pid = fork();
	if (pid == -1) {
		printf("fork error");
		exit(1);
	}
	if (pid != 0) {
		printf("i am parent, my pid is %d, my parent pid is %d\n", getpid(), getppid());
	} else {
		printf("i am child, my pid is %d, my parent pid is %d\n", getpid(), getppid());
	}
	sleep(2);
	return 0;
}
