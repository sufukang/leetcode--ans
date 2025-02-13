class Node {
public:
    Node* prev;  // 指向前一个节点的指针
    Node* next;  // 指向下一个节点的指针
    int key;     // 节点的键
    int val;     // 节点的值

    // 构造函数，初始化节点的键和值，默认值为0
    Node(int k = 0, int v = 0) : key(k), val(v) {}
};

class LRUCache {
    unordered_map<int, Node*> m;  // 哈希表，用于快速查找节点
    Node* newhead;                // 头节点，用于维护双向链表的头部
    int capacity;                 // 缓存的容量

public:
    // 构造函数，初始化缓存的容量，并创建一个循环双向链表的头节点
    LRUCache(int capacity) : capacity(capacity), newhead(new Node()) {
        newhead->prev = newhead;  // 头节点的prev指针指向自己，形成循环
        newhead->next = newhead;  // 头节点的next指针指向自己，形成循环
    }

    // 从双向链表中移除指定的节点
    void remove(Node* x) {
        x->next->prev = x->prev;  // 将x的下一个节点的prev指针指向x的上一个节点
        x->prev->next = x->next;  // 将x的上一个节点的next指针指向x的下一个节点
    }

    // 将指定的节点插入到双向链表的头部
    void push_front(Node* x) {
        x->next = newhead->next;  // 将x的next指针指向当前头节点的下一个节点
        newhead->next = x;        // 将头节点的next指针指向x
        x->prev = newhead;        // 将x的prev指针指向头节点
        x->next->prev = x;        // 将x的下一个节点的prev指针指向x
    }

    // 获取指定键对应的节点，并将其移动到双向链表的头部
    Node* get_node(int key) {
        auto it = m.find(key);    // 在哈希表中查找键对应的节点
        if (it == m.end())        // 如果找不到对应的节点
            return nullptr;       // 返回空指针
        auto node = it->second;   // 获取节点指针
        remove(node);             // 从双向链表中移除该节点
        push_front(node);         // 将该节点插入到双向链表的头部
        return node;              // 返回节点指针
    }

    // 获取指定键对应的值，如果不存在则返回-1
    int get(int key) {
        auto node = get_node(key);  // 获取节点
        return node ? node->val : -1;  // 如果节点存在则返回节点的值，否则返回-1
    }

    // 插入或更新指定键的值
    void put(int key, int value) {
        auto node = get_node(key);  // 获取节点
        if (node != nullptr) {      // 如果节点已经存在
            node->val = value;      // 更新节点的值
            return;                 // 直接返回
        }
        // 如果节点不存在，创建一个新的节点
        node = new Node(key, value);
        m[key] = node;              // 将新节点插入哈希表
        push_front(node);           // 将新节点插入双向链表的头部

        // 如果缓存容量超过限制
        if (m.size() > capacity) {
            auto back_node = newhead->prev;  // 获取双向链表的尾部节点
            remove(back_node);               // 从双向链表中移除尾部节点
            m.erase(back_node->key);         // 从哈希表中移除尾部节点的键
            delete back_node;                // 释放尾部节点的内存
        }
    }
};
