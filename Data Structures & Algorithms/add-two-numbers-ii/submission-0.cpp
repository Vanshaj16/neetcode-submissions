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
private:
    ListNode* reverseList(ListNode* head){
        ListNode* curr=head, *prev=nullptr;
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r1=reverseList(l1);
        ListNode* r2=reverseList(l2);
        
        ListNode* dummy=new ListNode();
        ListNode* res=dummy;
        
        int total=0, carry=0;
        while(r1 || r2 || carry){
            total=carry;
            if(r1){
                total+=r1->val;
                r1=r1->next;
            }
            if(r2){
                total+=r2->val;
                r2=r2->next;
            }
            int num=total%10;
            carry=total/10;
            dummy->next=new ListNode(num);
            dummy=dummy->next;
        }
        return reverseList(res->next);
    }
};