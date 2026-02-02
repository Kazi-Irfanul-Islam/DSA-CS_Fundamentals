#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x, Node* nxt = nullptr) {
        data = x;
        next = nxt;
    }
};

/* ------------------ INSERT ------------------ */

// Insert at head
Node* insertHead(Node* head, int val) {
    return new Node(val, head);
}

// Insert at tail
Node* insertTail(Node* head, int val) {
    Node* newNode = new Node(val);

    if(head == nullptr) return newNode;

    Node* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

// Insert at K-th position (1-indexed)
Node* insertPosition(Node* head, int el, int k) {
    if(head == NULL) {
        if(k == 1) return new Node(el);
        else return head;
    }

    if(k == 1) return new Node(el, head);

    int cnt = 0;
    Node* temp = head;
    while(temp != NULL) {
        cnt++;
        if(cnt == k - 1) {
            Node* newNode = new Node(el, temp->next);
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }

    return head;
}

// Insert Before specific value
Node* insertBeforeValue(Node* head, int el, int val) {
    if(head == NULL) return NULL;
    if(head->data == val) return new Node(el, head);

    Node* temp = head;
    while(temp->next != NULL) {
        if(temp->next->data == val) {
            Node* newNode = new Node(el, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

// Insert After specific value
Node* insertAfterValue(Node* head, int el, int val) {
    if(head == NULL) return NULL;
    if(head->data == val) return new Node(el, head->next);

    Node* temp = head;
    while(temp->next != NULL) {
        if(temp->data == val) {
            Node* newNode = new Node(el, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}
/* ------------------ DELETE ------------------ */

// Remove head
Node* removeHead(Node* head) {
    if(head == nullptr) return nullptr;

    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Remove tail
Node* removeTail(Node* head) {
    if(head == nullptr) return nullptr;

    if(head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* temp = head;
    while(temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    return head;
}

// Remove K-th node (1-indexed)
Node* removeKth(Node* head, int k) {
    if(head == nullptr || k <= 0) return head;

    if(k == 1) {
        return removeHead(head);
    }

    Node* prev = head;
    Node* curr = head->next;
    int pos = 2;

    while(curr != nullptr) {
        if(pos == k) {
            prev->next = curr->next;
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
        pos++;
    }

    return head;
}

// Remove first occurrence of value
Node* removeValue(Node* head, int val) {
    if(head == nullptr) return nullptr;

    if(head->data == val) {
        return removeHead(head);
    }

    Node* prev = head;
    Node* curr = head->next;

    while(curr != nullptr) {
        if(curr->data == val) {
            prev->next = curr->next;
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    return head;
}

/* ------------------ UTILITY ------------------ */

void print(Node* head) {
    while(head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

// Free entire list (important in CP & real apps)
void freeList(Node* head) {
    while(head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}


int main() {
    Node* head = new Node(1);
    head->next = new Node(2); 
    head->next->next = new Node(3); 
    head->next->next->next = new Node(4); 
    head->next->next->next->next = new Node(5);
    
    // Insertion 
    // head = insertHead(head, 100); 
    // head = insertTail(head, 100); 
    // head = insertPosition(head, 100, 3); 
    // head = insertBeforeValue(head, 100, 3); 
    head = insertAfterValue(head, 100, 3);

    // Deletion 
    // head = removeHead(head);
    // head = removeTail(head); 
    // head = removeKthElement(head, 3); 
    // head = removeElement(head, 1); 
    print(head);

    freeList(head);
}
