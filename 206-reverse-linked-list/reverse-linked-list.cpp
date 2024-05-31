/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case: if the list is empty or contains only one node
        if (head == nullptr || head->next == nullptr) return head;

        // Initialize three pointers
        ListNode* previous = nullptr;  // Initially points to null
        ListNode* current = head;      // Initially points to the head of the list
        ListNode* nextNode = nullptr;  // Used to store the next node

        // Iterate through the list
        while (current != nullptr) {
            nextNode = current->next;  // Store the next node
            current->next = previous;  // Reverse the current node's pointer
            previous = current;        // Move the previous pointer to the current node
            current = nextNode;        // Move the current pointer to the next node
        }

        // At the end of the loop, previous points to the new head of the reversed list
        return previous;
    }
};
