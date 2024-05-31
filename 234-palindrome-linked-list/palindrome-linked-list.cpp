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

        while(current!=nullptr){
            count++;
            current = current->next;
        }
        return count;
    }
    bool isPalindrome(ListNode* head) {
        int l = get_length(head);
        cout<<l<<endl;
        if (l == 1) return true;
        stack<int> st;
        bool isOdd = false;
        if (l%2 !=0) isOdd = true;
        cout<<isOdd<<endl;
        int mid = l/2;
        cout<<mid<<endl;
        ListNode* current  = head;
        int count = 0;
        while (current!=nullptr){
            count++;
            if (count<=mid){
                st.push(current->val);
                current = current->next;
            }

            else{
                if (isOdd){
                    current = current->next;
                    isOdd = false;
                }
                else{
                    if(st.top() == current->val){
                        st.pop();
                        current = current->next;
                    }
                    else{
                        return false;
                    }
                }
            }
            
        }

        return true;
    }
};