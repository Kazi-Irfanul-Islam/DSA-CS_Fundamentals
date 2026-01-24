#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* back;

    Node(int x, Node* nxt = nullptr, Node* bck = nullptr) {
        data = x;
        next = nxt;
        back = bck;
    }
};


void print(Node* head) {
    while(head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

// Free entire list (important in CP & real apps)

Node* convertAraayToDLL(vector<int> v) {
    Node* head = new Node(v[0]);
    Node* prev = head;
    
    for(int i = 1; i < v.size(); i++) {
        Node* newNode = new Node(v[i]);
        prev->next = newNode;
        newNode->back = prev;
        prev = prev->next;
    }
    
    return head;
}


void freeList(Node* head) {
    while(head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    Node* head = convertAraayToDLL(v);
    print(head);
    // freeList(head);
}
