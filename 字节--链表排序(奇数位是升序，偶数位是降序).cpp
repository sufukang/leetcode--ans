#include <iostream>
using namespace std;

// 定义链表节点结构
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 分离链表为奇数位和偶数位
pair<ListNode*, ListNode*> splitList(ListNode* head) {
    ListNode* oddHead = nullptr; // 奇数位链表的头节点
    ListNode* evenHead = nullptr; // 偶数位链表的头节点
    ListNode* oddTail = nullptr; // 奇数位链表的尾节点
    ListNode* evenTail = nullptr; // 偶数位链表的尾节点
    int index = 1; // 当前节点的位置索引

    while (head) {
        if (index % 2 == 1) { // 奇数位
            if (!oddHead) { // 如果奇数位链表为空
                oddHead = head; // 设置头节点
                oddTail = head; // 设置尾节点
            }
            else {
                oddTail->next = head; // 将当前节点连接到奇数位链表的尾部
                oddTail = oddTail->next; // 更新尾节点
            }
        }
        else { // 偶数位
            if (!evenHead) { // 如果偶数位链表为空
                evenHead = head; // 设置头节点
                evenTail = head; // 设置尾节点
            }
            else {
                evenTail->next = head; // 将当前节点连接到偶数位链表的尾部
                evenTail = evenTail->next; // 更新尾节点
            }
        }
        head = head->next; // 移动到下一个节点
        index++; // 更新索引
    }

    if (oddTail) oddTail->next = nullptr; // 确保奇数位链表的尾节点指向null
    if (evenTail) evenTail->next = nullptr; // 确保偶数位链表的尾节点指向null

    return { oddHead, evenHead }; // 返回分离后的奇数位和偶数位链表
}
// 反转链表
ListNode* reverseList(ListNode* head) {
    auto newhead = new ListNode(0);
    auto p = head;
    while (p) {
        auto q = p->next;
        p->next = newhead->next;
        newhead->next = p;
        p = q;
    }
    return newhead->next;
}

// 合并两个升序链表
ListNode* mergeLists(ListNode* l1, ListNode* l2) {
    auto newhead = new ListNode(0);
    auto tail = newhead;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        }
        else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = l1 ? l1 : l2;

    return newhead->next;
}

// 主函数：对链表进行排序
ListNode* sortLinkedList(ListNode* head) {
    if (!head || !head->next) return head;

    // 保存 splitList 的结果
    pair<ListNode*, ListNode*> splitResult = splitList(head);
    ListNode* oddHead = splitResult.first;   // 提取奇数位链表
    ListNode* evenHead = splitResult.second; // 提取偶数位链表
   

    // 反转偶数位链表
    evenHead = reverseList(evenHead);

    // 合并两个升序链表
    return mergeLists(oddHead, evenHead);
}

// 打印链表
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

// 测试代码
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(8);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(6);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(4);

    cout << "Original List: ";
    printList(head);

    ListNode* sortedHead = sortLinkedList(head);

    cout << "Sorted List: ";
    printList(sortedHead);

    return 0;
}
