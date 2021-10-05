#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *my_realloc(void *ptr, size_t size)
{
    if(!size)
    {
        free(ptr);
        return NULL;
    }
    else if(!ptr)
    {
        return malloc(size);
    }
    void *new = malloc(size);
    memcpy(new, ptr, size);
    free(ptr);
    return new;
}

int main()
{
	srand(time(NULL));
	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);
	int* a1 = malloc(n1 * sizeof(int));
	int i;
	for(i=0; i<n1; i++){
		a1[i]=100;
		printf("%d ", a1[i]);
	}
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);
	a1 = my_realloc(a1, n2*sizeof(int));
	if (n2 > n1)
    {
        for(i = n1; i < n2; i++)
        {
            a1[i] = 0;
        }
    }
	for(i=0; i<n2;i++){
		printf("%d ",a1[i]);
	}
	printf("\n");	
	return 0;
}
