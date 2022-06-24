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
    ListNode* reverseList(ListNode* head) {
       if(!head)
           return head;
        
        ListNode*temp;
        ListNode*cur=head;
        ListNode*start=NULL;
        
        while(cur){
            temp=cur->next;
            cur->next=start;
            start=cur;
            cur=temp;
        }
        return start;
    }
    
};