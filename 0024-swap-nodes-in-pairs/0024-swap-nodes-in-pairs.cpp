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
    ListNode* swap(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode dummy(-1,head->next);
        head->next = head->next->next;
        dummy.next->next = head;
        ListNode* ptr = &dummy;
        while (ptr) {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
        return dummy.next;
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0,head);
        ListNode* curr = &dummy;
        ListNode* ptr = head;
        bool first = true;
        while (ptr && ptr->next) {
            curr->next = swap(ptr);
            if (!curr->next || !curr->next->next) break;
            curr = curr->next->next;
            ptr = curr->next;
        }
        return dummy.next;
    }
};