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
void removeKey(Node*& head, int key) {
    int count = 0;
    while (head && head->data == key) { 
      Node* t = head; head = head->next; 
      delete t;
      count++; 
    }
    Node* cur = head;
    while (cur && cur->next) {
        if (cur->next->data == key) {
            Node* t = cur->next;
            cur->next = t->next;
            delete t;
            count++;
        } else cur = cur->next;
    }
    cout << "Count: " << count << "\n";
    Node* p = head;
    while (p) { cout << p->data;
               if (p->next) 
      cout << "->"; p = p->next; }
    cout << "\n";
}
int main() {
    Node* head = nullptr;
    int n, x, key;
    cin >> n;
    for (int i = 0; i < n; i++) { 
      cin >> x; push(head, x);
    }
    cin >> key;
    removeKey(head, key);
  return 0;
}
