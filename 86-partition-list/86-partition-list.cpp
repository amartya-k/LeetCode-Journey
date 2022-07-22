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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy=new ListNode(-201);
        dummy->next=head;
        
        ListNode *cur=head,*prev=dummy,*temp,*start,*end;
        
        // get the first position
        while(cur){
            if(cur->val>=x){
                break;
            }
            prev=cur;
            cur=cur->next;
        }
        start=prev;
        end=prev->next;
        
        while(cur){
            if(cur->val<x){
                //connect that node to start
                start->next=cur;
                start=start->next;
                //delete that node from current traversal
                prev->next=cur->next;
                cur=cur->next;
            }
            else{
                prev=cur;
                cur=cur->next;
                
            }
        }
        //connecting the first half with the rest
        start->next=end;
        return dummy->next;
        
    }
};