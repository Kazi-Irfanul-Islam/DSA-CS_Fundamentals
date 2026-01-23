#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* removeHead(Node* head) {
    if(head == nullptr) {
        return nullptr;
    }

    Node* temp = head;
    head = head -> next;
    delete temp;

    return head;
} 

Node* removeTail(Node* head) {
    if(head == nullptr or head->next == nullptr) return nullptr;
    
    Node* temp = head;
    while(temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    return head;
}

Node* removeKthElement(Node* head, int pos) {
    if(head == NULL) return NULL;
    
    if(pos == 1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL) {
        cnt++;
        if(cnt == pos) {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;
    }

    return head;
}

Node* removeElement(Node* head, int val) {
    if(head == NULL) return NULL;
    if(head -> data == val) {
        Node* temp = head;
        head = head -> next;
        free(temp);
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL) {
        if(temp -> data == val) {
            prev -> next = prev -> next -> next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;

    }

    return head;
}

void print(Node* head) {
    while(head != NULL) {
        cout << head -> data << endl;
        head = head -> next;
    }
    cout << endl;
} 

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    // head = removeHead(head);
    // head = removeTail(head);
    // head = removeKthElement(head, 3);
    // head = removeElement(head, 1);
    print(head);
}