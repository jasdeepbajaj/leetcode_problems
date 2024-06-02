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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, int> dict;
        ListNode* current = head;

        while (current!=NULL){
            if (dict.find(current) != dict.end()) return true;
            
            dict[current]++;
            current = current->next;
        }
        return false;
    }
};