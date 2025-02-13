class Solution {
public:
ListNode* reverseList(ListNode* head) {
    auto newhead=new ListNode(0,head);
    auto p=head;
    ListNode* q;
    newhead->next=NULL;//断开
    while(p!=NULL)
        {
            q=p->next;
            p->next=newhead->next;
            newhead->next=p;
            p=q;
        }
    return newhead->next;
}
};
