#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
class SLL {
    Node* head;
public:
    SLL() { 
      head = nullptr; 
    }
    void insertBeg(int x) {
        Node* n = new Node{x, head};
        head = n;
    }
    void insertEnd(int x) {
        Node* n = new Node{x, nullptr};
        if (!head) { 
          head = n;
          return; 
        }
        Node* t = head;
        while (t->next) 
        t = t->next;
        t->next = n;
    }
    void insertBefore(int val, int key) {
        if (!head)
        return;
        if (head->data == key) {
          insertBeg(val);
          return;
        }
        Node* p = head;
        while (p->next && p->next->data != key) 
          p = p->next;
        if (p->next) {
            Node* n = new Node{val, p->next};
            p->next = n;
        }
    }
    void insertAfter(int val, int key) {
        Node* p = head;
        while (p && p->data != key) 
          p = p->next;
        if (p) {
            Node* n = new Node{val, p->next};
            p->next = n;
        }
    }
    void delBeg() {
        if (!head) return;
        Node* t = head;
        head = head->next;
        delete t;
    }
    void delEnd() {
        if (!head) return;
        if (!head->next) {
          delete head; 
            head = nullptr; 
          return;
        }
        Node* t = head;
        while (t->next->next)
        t = t->next;
        delete t->next;
        t->next = nullptr;
    }
    void delKey(int key) {
        if (!head) return;
        if (head->data == key) { 
          delBeg();
          return;
        }
        Node* t = head;
        while (t->next && t->next->data != key) 
          t = t->next;
        if (t->next) {
            Node* del = t->next;
            t->next = del->next;
            delete del;
        }
    }
    void search(int key) {
        Node* t = head;
      int pos = 1;
        while (t) {
            if (t->data == key) { 
              cout << pos << "\n"; 
              return; }
            t = t->next;
          pos++;
        }
        cout << "Not found\n";
    }
    void display() {
        Node* t = head;
        while (t) { 
          cout << t->data << " "; t = t->next;
        }
        cout << "\n";
    }
};
int main() {
    SLL l; int ch, x, y;
    do {
        cin >> ch;
        switch (ch) {
        case 1: cin >> x; l.insertBeg(x); break;
        case 2: cin >> x; l.insertEnd(x); break;
        case 3: cin >> x >> y; l.insertBefore(x, y); break;
        case 4: cin >> x >> y; l.insertAfter(x, y); break;
        case 5: l.delBeg(); break;
        case 6: l.delEnd(); break;
        case 7: cin >> x; l.delKey(x); break;
        case 8: cin >> x; l.search(x); break;
        case 9: l.display(); break;
        }
    } while (ch != 0);
  return 0;
}
