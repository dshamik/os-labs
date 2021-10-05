#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("Enter array size\n");
    int n = 0;
	scanf("%d", &n);
    int* a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    free(a);
}