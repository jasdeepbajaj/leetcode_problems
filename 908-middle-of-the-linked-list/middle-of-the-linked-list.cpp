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

    int get_length(ListNode* head){
        int count = 0;
        ListNode* current = head;
        while (current != nullptr){
            current = current->next;
            count++;
        }
        return count;
    }
    ListNode* middleNode(ListNode* head) {
        int l = get_length(head);
        cout<<l<<endl;
        int mid = l/2 + 1;
        int i = 1; 
        ListNode* current = head;
        while (i<mid){
            current = current->next;
            i++;
        }
        return current;
    }
};