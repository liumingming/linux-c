#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

pthread_t ntid;

//打印进程id，线程id
void printids(const char * s)
{
    pid_t pid;
    pthread_t tid;
    pid = getpid();
    tid = pthread_self();
    printf("%s pid %lu tid %lu (0x%lx)\n", s, (unsigned long)pid, (unsigned long)tid, (unsigned long)tid);
}

void * th_fn(void *arg)
{
    printids("new thread: ");
    return ((void *)0);
}

int main(void)
{
    int err;
    err = pthread_create(&ntid, NULL, th_fn, NULL);
    if (err != 0)
    {
        printf("can't creat thread\n");
    }
    printids("main thread");
    sleep(1);
    exit(0);
}