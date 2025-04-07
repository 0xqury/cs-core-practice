#include <stdio.h>

void foo(int x) {
    int y = x + 5;
    printf("In foo(): x = %d, y = %d\n", x, y);
}

int main() {
    int a = 10;
    foo(a);
    return 0;
}
