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
    ListNode* reverse_ll(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* forward=NULL;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //reverse the linklist
        // l1=reverse_ll(l1);
        // l2=reverse_ll(l2);

        //add the two linklist
        ListNode* anshead=NULL;
        ListNode* anstail=NULL;
        int carry=0;
        int sum=0;
        int digit=0;
        while(l1 !=NULL && l2 !=NULL){
            sum=carry+l1->val + l2->val;
            digit=sum%10;
            carry=sum/10;

            ListNode* digitNode = new ListNode(digit);

            //if first node
            if(anshead==NULL){
                anshead=digitNode;
                anstail=digitNode;
            }

            else{
                anstail->next=digitNode;
                anstail=digitNode;
            }
            l1=l1->next;
            l2=l2->next;
        }

        while(l1 !=NULL){
            sum=carry+l1->val;
            digit=sum%10;
            carry=sum/10;

            ListNode* digitNode = new ListNode(digit);
            anstail->next=digitNode;
            anstail=digitNode;
            l1=l1->next;

        }

        while(l2 !=NULL){
            sum=carry+l2->val;
            digit=sum%10;
            carry=sum/10;

            ListNode* digitNode = new ListNode(digit);
            anstail->next=digitNode;
            anstail=digitNode;
            l2=l2->next;
        }

        //handle carry
        while(carry!=0){
            sum=carry;
            digit=sum%10;
            carry=sum/10;

            ListNode* digitNode = new ListNode(digit);
            anstail->next=digitNode;
            anstail=digitNode;
        }
        return anshead;
    }
};