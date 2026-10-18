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
        ListNode dummy(0);
        ListNode* merged = &dummy;
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        while(curr1 != nullptr && curr2 != nullptr) {
            if (curr1->val <= curr2->val) {
                merged->next = curr1;
                curr1 = curr1->next;
            } else {
                merged->next = curr2;
                curr2 = curr2->next;
            }
            merged = merged->next;
        }
        merged->next = (curr1 != nullptr) ? curr1 : curr2;
        return dummy.next;
    }
};
