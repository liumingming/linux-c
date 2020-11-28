#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void thread_run(void *ch);

int main() {
    pthread_t tid1;
    pthread_t tid2;

    if (pthread_create(&tid1, NULL, (void *)thread_run, "A") != 0) {
        printf("create pthread error");
        exit(1);
    }
    if (pthread_create(&tid2, NULL, (void *)thread_run, "B") != 0) {
        printf("create pthread error");
        exit(1);
    }
    char *rev1, *rev2;
    pthread_join(tid1, (void *)&rev1);
    pthread_join(tid2, (void *)&rev2);
    
    // printf("the program is close %s and %s", rev1, rev2);
}

void thread_run(void * ch)
{   
    for (int i=0; i<10; i++) {
        printf("%s frorm thread id %d\n", (char *)ch, (unsigned int)pthread_self());
        sleep(1);
    }
   
}