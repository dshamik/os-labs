#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void f(int n)
{
    int len = n * 2 - 1;
    char *ans = malloc(len * sizeof(char));
    int l = len / 2, r = len / 2;
    for (int i = 0; i < len; i++)
    {
        ans[i] = ' ';
    }
    for (int i = 0; i < n; i++)
    {
        ans[l] = '*';
        ans[r] = '*';
        l--;
        r++;
        printf("%s\n", ans);
    }
}

int main()
{
    int n;
    char *str = malloc(256 * sizeof(char));
    fgets(str, 256, stdin);
    n = atoi(str);
    f(n);
}