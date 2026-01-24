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
    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = removeKthElement(head, 1);
    deleteNode(head->next);
    print(head);
    // freeList(head);
}
