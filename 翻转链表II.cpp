class Solution {
public:
ListNode* reverseBetween(ListNode* head, int left, int right) {
    auto newhead=new ListNode(0,head);
    auto p0=newhead;
    //1.找到左边界的前驱
    for(int i=0;i<left-1;i++){
        p0=p0->next;
    }
    //2.局部反转
    auto cur=p0->next;
    ListNode* pre=NULL;
    for(int i=0;i<right-left+1;i++){
        auto nxt=cur->next;
        cur->next=pre;//往后倒
        pre=cur;//往后倒腾
        cur=nxt;//往后倒腾
    }
    //3.连接
    p0->next->next=cur;
    p0->next=pre;

    return newhead->next;
}
};
