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
        ListNode* curr = head;

        while(curr!=nullptr){
            if(dict.find(curr) != dict.end()) return true;
            dict[curr]++;
            curr = curr->next;
        }

        return false;
    }
};