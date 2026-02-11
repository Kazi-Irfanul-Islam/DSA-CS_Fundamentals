#include <iostream>

/**
 * Node structure for the linked list
 */
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

/**
 * Solution class with fancy style pointers
 */
class Solution {
public:
    Node* segregate(Node* head) {
        if (!head || !head->next) return head;

        // Using stack-allocated dummies to prevent memory leaks
        Node zeroDummy(-1);
        Node oneDummy(-1);
        Node twoDummy(-1);

        Node* zeroTail = &zeroDummy;
        Node* oneTail  = &oneDummy;
        Node* twoTail  = &twoDummy;

        Node* curr = head;
        while (curr != nullptr) {
            if (curr->data == 0) {
                zeroTail->next = curr;
                zeroTail = zeroTail->next;
            } else if (curr->data == 1) {
                oneTail->next = curr;
                oneTail = oneTail->next;
            } else {
                twoTail->next = curr;
                twoTail = twoTail->next;
            }
            curr = curr->next;
        }

        // Connect the lists: 0s -> 1s -> 2s
        // If 1s don't exist, connect 0s directly to 2s
        zeroTail->next = (oneDummy.next) ? oneDummy.next : twoDummy.next;
        oneTail->next  = twoDummy.next;
        twoTail->next  = nullptr;

        return zeroDummy.next;
    }
};

/**
 * Utility function to print the linked list
 */
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

/**
 * Main function to execute the program
 */
int main() {
    // Creating a linked list: 1 -> 2 -> 0 -> 1 -> 0
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);

    std::cout << "Original list: ";
    printList(head);

    Solution sol;
    head = sol.segregate(head);

    std::cout << "Segregated list: ";
    printList(head);

    return 0;
}