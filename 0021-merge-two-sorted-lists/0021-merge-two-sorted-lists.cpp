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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* ptr = head;
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        while (ptr1 && ptr2) {
            ListNode* curr = nullptr;
            if (ptr1->val < ptr2->val) {
                cout << "val1 :" << ptr1->val << " is smaller" << endl;
                curr = ptr1;
                ptr1 = ptr1->next;
            }
            else {
                cout << "val2 :" << ptr2->val << " is greater" << endl;
                curr = ptr2;
                ptr2 = ptr2->next;
            }
            if (!head) {
                head = curr;
                ptr = head;
            }
            else {
                ptr->next = curr;
                ptr = ptr->next;
            }
        }
        while (ptr1) {
            // cout << "only val1 :" << ptr1->val << " is left" << endl;
            if (!head) {
                head = ptr1;
                ptr = head;
            }
            else {
                ptr->next = ptr1;
                ptr = ptr->next;
            }

            ptr1 = ptr1->next;
        }
        while (ptr2) {
            if (!head) {
                head = ptr2;
                ptr = head;
            }
            else {
                ptr->next = ptr2;
                ptr = ptr->next;
            } 

            ptr2 = ptr2->next;
        }
        return head;
    }
};