#include <iostream>

using namespace std;

/**
 * ✧･ﾟ: *✧･ﾟ:* NODE STRUCTURE  *:･ﾟ✧*:･ﾟ✧
 * Represents a single element in the linked list.
 */
class Node {
public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/**
 * ｡･:*:･ﾟ★  SOLUTION CLASS  ☆ﾟ･:*:･｡
 * Contains logic to detect and measure loops.
 */
class Solution {
public:
    /**
     * Measures the number of nodes within the detected loop.
     * @param slow The pointer where the meeting occurred.
     * @param fast The pointer used to traverse the cycle.
     */
    int findLength(Node* slow, Node* fast) {
        int cnt = 1;
        fast = fast->next; // Move fast forward once to start the count
        
        while (fast != slow) {
            fast = fast->next;
            ++cnt;
        }
        return cnt;
    }

    /**
     * Detects if a loop exists using Floyd's Cycle-Finding Algorithm.
     * Returns the length of the loop, or 0 if no loop is found.
     */
    int lengthOfLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;
        
        // Move fast twice as fast as slow
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            // If pointers meet, a cycle exists
            if (slow == fast) {
                return findLength(slow, fast);
            }
        }
        
        return 0; // No loop detected
    }
};

/**
 * ✧˚ · .  MAIN EXECUTION  . · ˚✧
 */
int main() {
    // 1. Create nodes: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // 2. Create a loop: Connect 5 back to 2
    head->next->next->next->next->next = head->next; 
    // Loop nodes: 2 -> 3 -> 4 -> 5 (Length should be 4)

    Solution sol;
    int length = sol.lengthOfLoop(head);

    if (length > 0) {
        cout << "Cycle detected! Loop length: " << length << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    return 0;
}