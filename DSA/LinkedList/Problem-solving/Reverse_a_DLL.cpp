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

// reverse a DLL
Node* reverseDLL(Node* head) {
    if(head == nullptr or head->next == nullptr) return head;

    Node* curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;

    while(curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        curr->back = next;
        prev = curr;
        curr = next;
    }

    return prev;
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

// Problem Link : https://www.naukri.com/code360/problems/reverse-a-doubly-linked-list_1116098?leftPanelTabValue=SUBMISSION

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    Node* head = convertAraayToDLL(v);
    head = reverseDLL(head);
    print(head);
    // freeList(head);
}
