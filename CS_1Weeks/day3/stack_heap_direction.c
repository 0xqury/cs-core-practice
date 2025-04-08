#include <stdio.h>
#include <stdlib.h>

void check_stack_growth(int *prev) {
    int current;
    printf("[STACK] current: %p, previous: %p\n", &current, prev);
    if (prev != NULL) {
        printf("→ Stack grows %s\n\n", &current < prev ? "downward" : "upward");
    }
    if (&current > (int *)0x1000) check_stack_growth(&current); // 재귀 호출
}

int main() {
    // Heap 확인
    int *heap1 = (int *)malloc(sizeof(int));
    int *heap2 = (int *)malloc(sizeof(int));
    printf("[HEAP] heap1: %p, heap2: %p\n", heap1, heap2);
    printf("→ Heap grows %s\n\n", heap2 > heap1 ? "upward" : "downward");

    // Stack 확인
    check_stack_growth(NULL);

    free(heap1);
    free(heap2);
    return 0;
}
