#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *str = malloc(256 * sizeof(char)), s = "";
    fgets(str, 256, stdin);
    int l = strlen(str);
    for (int i = 0; i < l / 2; i++) 
    {
        s = str[i];
        str[i] = str[l - 1 - i];
        str[l - 1 - i] = s;
    }
    printf("%s", str);
}