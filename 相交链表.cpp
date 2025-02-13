class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;  // 初始化链表A的长度为0
        int len2 = 0;  // 初始化链表B的长度为0
        
        // 计算链表A的长度
        for(auto p = headA; p != NULL; p = p->next) {
            len1++;
        }
        
        // 计算链表B的长度
        for(auto p = headB; p != NULL; p = p->next) {
            len2++;
        }
        
        auto r = headA;  // 将指针r指向链表A的头节点
        auto s = headB;  // 将指针s指向链表B的头节点
        
        // 如果链表A比链表B长，则将指针r向后移动，使得两个链表从相同长度的位置开始比较
        while(len1 > len2) {
            len1--;
            r = r->next;
        }
        
        // 如果链表B比链表A长，则将指针s向后移动，使得两个链表从相同长度的位置开始比较
        while(len2 > len1) {
            len2--;
            s = s->next;
        }
        
        // 同时遍历两个链表，直到找到交点或遍历结束
        while(s && r) {
            if(r == s)  // 如果r和s指向同一个节点，说明找到了交点
                return r;
            r = r->next;  // 否则，继续向后遍历
            s = s->next;
        }
        
        return NULL;  // 如果没有找到交点，返回NULL
    }
};
