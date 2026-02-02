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

// insertion before head
Node* insertBeforeHead(Node* head, int x) {
    Node* newHead = new Node(x, head, nullptr);
    head->back = newHead;
    return newHead;    
}

// insertion before tail
Node* insertBeforeTail(Node* head, int x) {
    if(head->next == NULL) return insertBeforeHead(head, x);

    Node* tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }

    Node* prev = tail->back;
    Node* newNode = new Node(x, tail, prev);    
    prev->next = newNode;
    tail->back = newNode;
    return head;
}

// insert before kth element
Node* insertBeforeKth(Node* head, int x, int k) {
    if(k == 1) return insertBeforeHead(head, x);
    
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL) {
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* newNode = new Node(x, temp, prev);

    prev->next = newNode;
    temp->back = newNode;
    return head;
}

// delete head of the DLL
Node* deleteHead(Node* head) {
    if(head == nullptr or head->next == nullptr) {
        return nullptr;
    }
    else {
        Node* prev = head;
        head = head->next;
        head->back = nullptr;
        prev->next = nullptr;
        delete prev;
        return head;
    }
}

// delete tail of the DLL
Node* deleteTail(Node* head) {
    if(head == nullptr or head->next == nullptr) return nullptr;
    
    Node* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }

    Node* newTail = temp->back;
    newTail->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;

}

// Delete Kth element of the DLL 
Node* removeKthElement(Node* head, int pos) {
    if(head == NULL) return NULL;

    int cnt = 0;
    Node* kthNode = head;
    while(kthNode != NULL) {
        cnt++;
        if(cnt == pos) break;
        kthNode = kthNode->next;
    }

    Node* prev = kthNode->back;
    Node* front = kthNode->next;

    if(prev == NULL and front == NULL) {
        delete kthNode;
        return NULL;
    }

    if(prev == NULL) return deleteHead(head);

    if(front == NULL) return deleteTail(head);

    prev->next = front;
    front->back = prev;

    kthNode->next = NULL;
    kthNode->back = NULL;

    delete kthNode;
    return head;
} 

// Delete Node of a DLL
void deleteNode(Node* node) {
    Node* prev = node->back;
    Node* front = node->next;

    if(front == NULL) {
        prev->next = nullptr;
        node->back = nullptr;
        delete node;
        return;
    }

    prev->next = front;
    front->back = prev;
    
    node->next = nullptr;
    node->back = nullptr;
    delete node;
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


void print(Node* head) {
    while(head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}


void freeList(Node* head) {
    while(head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}


int main() {
    vector<int> v = {69, 1, 2, 3, 4, 5, 6, 7};
    Node* head = convertAraayToDLL(v);
    // Insertion
    // head = insertBeforeHead(head, 100);
    // head = insertBeforeTail(head, 47);
    head = insertBeforeKth(head, 100, 3);

    // Deletion
    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = removeKthElement(head, 1);
    // deleteNode(head->next);
    print(head);
    // freeList(head);
}
