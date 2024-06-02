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
    bool isPalindrome(ListNode* head) {
        if (head==NULL || head->next==NULL) {
            return true;
        }
        
        // Step 1: Find the midpoint using Tortoise and Hare approach
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next!=NULL && fast->next->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse the second half of the list
        ListNode* secondHalf = reverseList(slow->next);
        ListNode* firstHalf = head;
        
        // Step 3: Compare the first half and the reversed second half
        ListNode* secondHalfCopy = secondHalf;
        bool isPalin = true;
        
        while (secondHalf) {
            if (firstHalf->val != secondHalf->val) {
                isPalin = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        // Step 4: Restore the list (optional)
        reverseList(secondHalfCopy);
        
        return isPalin;
    }
    
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        
        return prev;
    }
};