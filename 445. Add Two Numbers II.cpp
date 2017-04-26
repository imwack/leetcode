/**
Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        ListNode *p1=l1,*p2=l2;
        while(p1!=NULL){
            s1.push(p1->val);
            p1 = p1->next;
        }
        while(p2!=NULL){
            s2.push(p2->val);
            p2 = p2->next;
        }
        int c=0,v;
        ListNode *head = new ListNode(0);
        ListNode *tail = new ListNode(0)；
        while(!s1.empty() && !s2.empty()){
            v = s1.top()+s2.top()+c;
            c = v/10;
            v = v%10;

            ListNode temp(v);
        }
    }
};