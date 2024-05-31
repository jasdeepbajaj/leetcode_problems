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
        stack<int> st;

        if (head == nullptr || head->next == nullptr) return head;

        ListNode* temp = head;

        while(temp!=nullptr){
            st.push(temp->val);
            temp = temp->next;
        }

        ListNode* newHead = new ListNode(st.top());
        st.pop();
        ListNode* current = newHead;
        while(!st.empty()){
            ListNode* temp1 = new ListNode(st.top());
            st.pop();
            current->next = temp1;
            current = current->next;
        }

        return newHead;
    }
};