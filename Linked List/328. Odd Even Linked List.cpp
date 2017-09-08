/*
Given a singly linked list, group all odd nodes together followed by the even nodes. 
Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...
*/

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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr) return head;
        ListNode *even = head;      //point to the last even
        ListNode *odd = head->next; //point to the last odd
        ListNode *temp,*temp1,*oddFront;
        //123456
        //13 
        while(odd!=nullptr && odd->next!=nullptr){
            temp = odd->next;
            temp1 = temp->next;
            even->next = temp;
            even = temp;
            even->next = oddFront;
            odd->next = temp1;
            odd = temp1;                     
        }
        return head;
    }
};