#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(int val) {
    struct Node* newNode = createNode(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf("->");
        temp = temp->next;
    }
    printf("\n");
}

void countAndDeleteOccurrences(int key) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    int count = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            count++;
            if (prev == NULL) {
                head = temp->next;
                free(temp);
                temp = head;
            } else {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
    printf("Count: %d\nUpdated Linked List: ", count);
    display();
}
int main() {
    int n, val, key;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(val);
    }
    printf("Enter key to count and delete: ");
    scanf("%d", &key);
    countAndDeleteOccurrences(key);
    printf("Finding middle element:\n");
    return 0;
}
