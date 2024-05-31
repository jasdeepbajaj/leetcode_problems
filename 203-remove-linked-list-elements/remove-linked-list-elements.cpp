class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Handle the case where head itself needs to be removed
        while (head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        ListNode* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->next->val == val) {
                ListNode* temp = current->next;
                current->next = temp->next;
                delete temp;
            } else {
                current = current->next;
            }
        }

        return head;
    }
};
