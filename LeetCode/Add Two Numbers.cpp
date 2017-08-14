/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef long long ll;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr = new ListNode(0);ListNode* temp = ptr;  
        int carry = 0;
        while(l1 && l2){
            int t1 = (l1 -> val) + (l2 -> val) + carry;
            temp -> next = new ListNode(t1 % 10);
            temp = temp -> next;
            carry = t1 / 10;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1){
            int t1 = (l1 -> val) + carry;
            temp -> next = new ListNode(t1 % 10);
            temp = temp -> next;
            carry = t1 / 10;
            l1 = l1 -> next;
        }
        while(l2){
            int t1 = (l2 -> val) + carry;
            temp -> next = new ListNode(t1 % 10);
            temp = temp -> next;
            carry = t1 / 10;
            l2 = l2 -> next;
        }
        if(carry != 0){
            temp -> next = new ListNode(carry);
        }
        return ptr -> next;        
    }
    
};
