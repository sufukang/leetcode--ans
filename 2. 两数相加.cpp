class Solution {
public:
    ListNode* addTwoNumbers(ListNode* headA, ListNode* headB) {
        ListNode* ans=NULL;
        ListNode* cur=NULL;
        int val=0;
        int sum=0;
        int carry=0;
        for(;headA!=NULL||headB!=NULL;
        headA=headA==NULL?NULL:headA->next,
        headB=headB==NULL?NULL:headB->next){
            sum=(headA==NULL?0:headA->val)+
            (headB==NULL?0:headB->val)+carry;
            val=sum%10;
            carry=sum/10;
            if(ans==NULL){
                ans=new ListNode(val);
                cur=ans;
            }else{
                cur->next=new ListNode(val);
                cur=cur->next;
            }
        }
        if(carry==1)cur->next=new ListNode(1);
        return ans;
    }
};
