#include <iostream>
#include <vector>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Fast pointer to create a gap of 'n'
        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast pointer n steps ahead
        for (int i = 0; i < n; i++) {
            if (fast == nullptr) return head; // Safety check
            fast = fast->next;
        }

        // If fast is NULL, it means we need to remove the head
        if (fast == nullptr) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Move both until fast reaches the last node
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Relink and delete
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;

        return head;
    }
};

// --- Helper Functions for Testing ---

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    std::cout << std::endl;
}

ListNode* createList(const std::vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    Solution sol;
    
    // Test Case: List = [1, 2, 3, 4, 5], n = 2
    std::vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createList(values);

    std::cout << "Original List: ";
    printList(head);

    int n = 2;
    head = sol.removeNthFromEnd(head, n);

    std::cout << "After removing " << n << "-th from end: ";
    printList(head);

    // Clean up remaining nodes
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}