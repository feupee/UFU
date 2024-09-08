#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro na alocacao de memoria\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

Node* insertNode(Node* list, int value) {
    Node* newNode = createNode(value);
    newNode->next = list;
    return newNode;
}

void freeList(Node* list) {
    while (list != NULL) {
        Node* temp = list;
        list = list->next;
        free(temp);
    }
}

void printList(Node* list) {
    Node* current = list;
    while (current != NULL) {
        printf("%d", current->value);
        current = current->next;
    }
    printf("\n");
}

Node* binaryToList(const char* binaryStr) {
    Node* binaryList = NULL;
    int length = strlen(binaryStr);

    for (int i = 0; i < length; i++) {
        if (binaryStr[i] == '0' || binaryStr[i] == '1') {
            int bit = binaryStr[i] - '0';
            binaryList = insertNode(binaryList, bit);
        } else {
            printf("Entrada invalida. Use apenas 0s e 1s.\n");
            freeList(binaryList);
            return NULL;
        }
    }

    return binaryList;
}

int listToBinary(Node* list) {
    int decimal = 0;
    Node* current = list;

    while (current != NULL) {
        decimal = decimal * 2 + current->value;
        current = current->next;
    }

    return decimal;
}

Node* addIntToBinary(Node* binaryList, int numToAdd) {
    Node* result = NULL;

    while (numToAdd > 0 || binaryList != NULL) {
        int sum = numToAdd;

        if (binaryList != NULL) {
            sum += binaryList->value;
            binaryList = binaryList->next;
        }

        result = insertNode(result, sum % 2);
        numToAdd = sum / 2;
    }

    return result;
}

int main() {
    char binaryStr[100];
    int numToAdd;

    printf("Digite um numero binario: ");
    scanf("%s", binaryStr);
    Node* binaryList = binaryToList(binaryStr);

    if (binaryList == NULL) {
        return 1;
    }

    printf("Digite um numero inteiro para adicionar: ");
    scanf("%d", &numToAdd);

    Node* result = addIntToBinary(binaryList, numToAdd);

    printf("Resultado em binario: ");
    printList(result);

    int decimalResult = listToBinary(result);
    printf("Resultado em decimal: %d\n", decimalResult);

    freeList(binaryList);
    freeList(result);

    return 0;
}