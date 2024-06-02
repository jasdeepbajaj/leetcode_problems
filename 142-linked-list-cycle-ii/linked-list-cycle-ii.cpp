/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> dict;
        ListNode* current = head;

        while (current!=NULL){
            if (dict.find(current) != dict.end()) return current;
            
            dict[current]++;
            current = current->next;
        }
        return NULL;
    }
};