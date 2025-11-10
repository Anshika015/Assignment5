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

void insertBeginning(int val) {
    struct Node* newNode = createNode(val);
    newNode->next = head;
    head = newNode;
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

void insertBefore(int key, int val) {
    if (head == NULL) return;
    if (head->data == key) {
        insertBeginning(val);
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;
    if (temp->next == NULL) return;
    struct Node* newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAfter(int key, int val) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) return;
    struct Node* newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteBeginning() {
    if (head == NULL) return;
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteEnd() {
    if (head == NULL) return;
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void deleteSpecific(int key) {
    if (head == NULL) return;
    if (head->data == key) {
        deleteBeginning();
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;
    if (temp->next == NULL) return;
    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
}

void searchNode(int key) {
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Node found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Node not found\n");
}

void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, val, key;
    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertBeginning(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertEnd(val);
                break;
            case 3:
                printf("Enter key and value: ");
                scanf("%d %d", &key, &val);
                insertBefore(key, val);
                break;
            case 4:
                printf("Enter key and value: ");
                scanf("%d %d", &key, &val);
                insertAfter(key, val);
                break;
            case 5:
                deleteBeginning();
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                printf("Enter key: ");
                scanf("%d", &key);
                deleteSpecific(key);
                break;
            case 8:
                printf("Enter key: ");
                scanf("%d", &key);
                searchNode(key);
                break;
            case 9:
                display();
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
