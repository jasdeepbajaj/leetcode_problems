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
        // stack<int> st;

        if (head == nullptr || head->next == nullptr) return head;

        ListNode* last = nullptr;
        ListNode* current = head;

        while(current!=nullptr){
            ListNode* nextNode = current->next;
            current->next = last;
            last = current;
            current = nextNode;
        }

        return last;

              
    }
};