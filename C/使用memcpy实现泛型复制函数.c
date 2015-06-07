#include <stdio.h>
#include <string.h>

void swap(void *a, void *b, int size)
{
    char buffer[size];
    memcpy(buffer, a, size);
    memcpy(a, b, size);
    memcpy(b, buffer, size);
}

int main()
{
    char a = 'a', b = 'b';
    swap(&a, &b, sizeof(char));
    printf("a = %c b = %c\n", a , b);

    int x = 11, y = 99;
    swap(&x, &y, sizeof(int));
    printf("x = %d y = %d\n", x , y);
    return 0;
}
