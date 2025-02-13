class Solution {
public:
ListNode* mergeNodes(ListNode* head) {
    auto tail = head;
    for (auto cur = head->next; cur->next; cur = cur->next) {
        if (cur->val) {
            tail->val += cur->val;
        } else {
            tail = tail->next;
            tail->val = 0;
        }
    }
    // 注：这里没有 delete 剩余节点，可以自行补充
    tail->next = nullptr;
    return head;
}
};
