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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
//         if(!head || left==right) return head;
//         ListNode* front=NULL,*cur=head,*ptr=NULL,*prev=NULL,*temp;
//         int count=1;
//         while(cur){
//             if(left==count){
//                 front=prev;
//                 break;
//             }
//             prev=cur;
//             cur=cur->next;
//             count++;
//         }
        
//         //front->next has tail of the new list
//         ptr=cur->next;
//         while(count<=right){
//             cur->next=prev;
//             prev=cur;
//             cur=ptr;
//             ptr=cur->next;
//             count++;
//         }
//         if(cur){
//             // cur->next=prev;
//             // prev=cur;
//             temp=front->next;
//             front->next=cur;
//             temp->next=cur;
//         }
//         head=prev;
//         // if(front){
//         // temp= front->next;
//         // front->next=prev;
//         // temp->next=ptr;
//         // }
//         // else{
//         //     head=prev;
//         // }

//         return head;
        
        ListNode *dummy = new ListNode(0), *pre = dummy, *cur;
            dummy->next = head;
            for (int i = 0; i < left - 1; i++){
                pre = pre->next;
            }
            cur = pre->next;
            for (int i = 0; i < right - left; i++){
                ListNode *temp = pre->next;
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = temp;
            }
            return dummy->next;

    }
};