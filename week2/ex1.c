#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    int intMax = INT_MAX;
    float floatMax = FLT_MAX;
    double doubleMax = DBL_MAX;
    printf("int size: %lu and value: %d\n", sizeof(intMax), intMax);
    printf("float size: %lu and value: %f\n", sizeof(floatMax), floatMax);
    printf("double size: %lu and value: %f\n", sizeof(doubleMax), doubleMax);
}