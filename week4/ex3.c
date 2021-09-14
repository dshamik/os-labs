#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include <unistd.h>

int main()
{
    char a[9999];
    scanf("%s", a);
    system(a);
    return 0;
}