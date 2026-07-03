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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> arr;
        ListNode* node=head;
        while(node){
            arr.push_back(node);
            node=node->next;
        }
        int removeIdx=arr.size()-n;
        if(removeIdx==0) return head->next;
        arr[removeIdx-1]->next=arr[removeIdx]->next;
        return head;
    }
};
