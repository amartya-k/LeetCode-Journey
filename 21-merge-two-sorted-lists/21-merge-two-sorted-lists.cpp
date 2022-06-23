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
    ListNode* mergeTwoLists(ListNode* p1, ListNode* p2) {
        if(!p1 && p2)
            return p2;
        if(p1 && !p2)
            return p1;
        ListNode*cur1=p1;
        ListNode*cur2=p2;
        ListNode*res= new ListNode(0);
        ListNode*temp=res;
        
        while(cur1&&cur2){
            if(cur1->val<cur2->val){
                res->next = cur1;
                res=res->next;
                cur1=cur1->next;
            }
            else{
                res->next = cur2;
                res=res->next;
                cur2=cur2->next;
            }
        }
        
        if(cur1){
            res->next=cur1;
        }
        else{
            res->next=cur2;
        }
        
        return temp->next;
        
    }
};

/*
1,7,9

1,2,3,4,8,10




*/