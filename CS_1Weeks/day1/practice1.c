#include <stdio.h>
#include <stdlib.h>

int global_initialized = 10;                // 데이터 영역
int global_uninitialized;                   // BSS 영역

int main() {
    int local = 5;                          // 스택 영역
    int *heap = (int *)malloc(sizeof(int)); // 힙 영역
    *heap = 20;

    printf("코드(Text) 주소:        %p\n", (void *)main);
    printf("초기화 전역변수(Data):   %p\n", (void *)&global_initialized);
    printf("비초기화 전역변수(BSS):  %p\n", (void *)&global_uninitialized);
    printf("지역변수(Stack):        %p\n", (void *)&local);
    printf("동적할당(Heap):         %p\n", (void *)heap);

    free(heap);
    return 0;
}
