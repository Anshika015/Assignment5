#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void push(Node*& head, int x) {
    Node* n = new Node{x, head};
    head = n;
}
void findMid(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data << "\n";
}
int main() {
    Node* head = nullptr; int n, x;
    cin >> n;
    for (int i = n - 1; i >= 0; i--) {
      cin >> x; push(head, x);
    }
    findMid(head);
  return 0;
}
