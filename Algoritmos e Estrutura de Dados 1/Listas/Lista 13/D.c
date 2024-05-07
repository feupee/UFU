#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int value) {
    if (!isFull(stack)) {
        stack->items[++stack->top] = value;
    } else {
        printf("A pilha esta cheia.\n");
    }
}

int pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top--];
    } else {
        printf("A pilha esta vazia.\n");
        return -1; 
    }
}

void decimalParaBinario(int decimal) {
    Stack pilha;
    initialize(&pilha);

    if (decimal == 0) {
        push(&pilha, 0);
    }

    while (decimal > 0) {
        int resto = decimal % 2;
        push(&pilha, resto);
        decimal /= 2;
    }

    printf("Numero binario: ");
    while (!isEmpty(&pilha)) {
        printf("%d", pop(&pilha));
    }
    printf("\n");
}

int main() {
    int numeroDecimal;
    
    printf("Digite um numero decimal: ");
    scanf("%d", &numeroDecimal);

    decimalParaBinario(numeroDecimal);

    return 0;
}