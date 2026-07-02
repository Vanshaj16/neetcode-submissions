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
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> st;
        ListNode* curr=head;
        while(curr){
            if(st.find(curr) != st.end()){
                return true;
            }
            st.insert(curr);
            curr=curr->next;
        }
        return false;
    }
};
