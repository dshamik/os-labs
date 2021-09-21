#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int N = 10; 
int count = 0;
int consumerWork = 0;
int producerWork = 0;

void Producer()
{
    while(1)
    {
        if (count == N)
        {
            producerWork = 0;
            while(!producerWork) {}
        } 
        else
        {
            count++;
            if (count == 1)
            {
                printf("1");
                consumerWork = 1;
            }
        }
    }
}
void Consumer()
{
    while(1){
        if (count == 0)
        {
            consumerWork = 0;
            while(!consumerWork) {}
        }
        else
        {
            count--;
            if (count == N - 1)
            {
                printf("0");
                producerWork = 1;
            }
        }
    }
}

int main()
{
    pthread_t *producer, *consumer;
    pthread_create(&producer, NULL, &Producer, NULL);
    pthread_create(&consumer, NULL, &Consumer, NULL);
    pthread_join(&consumer, 0);
    pthread_join(&producer, 0);
}