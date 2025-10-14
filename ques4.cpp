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
Node* reverse(Node* head) {
    Node* prev = nullptr;
  Node* cur = head;
  Node* next = nullptr;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
int main() {
    Node* head = nullptr;
  int n, x;
    cin >> n;
    for (int i = n - 1; i >= 0; i--) {
      cin >> x; push(head, x);
    }
    head = reverse(head);
    while (head) {
      cout << head->data;
      if (head->next)
        cout << "->"; 
      head = head->next;
    }
    cout << "\n";
  return 0;
}
