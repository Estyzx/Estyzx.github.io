struct Node {
    int val;  // 链表节点值
    Node *next;  // 指向下一个节点的指针

    // 构造函数
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *n) : val(x), next(n) {}
};

void insertNode(Node *pre, int val) {

    // 创建临时节点
    Node *newNode = new Node(val);

    // 将pre节点的下一个节点赋值给新节点的next
    newNode->next = pre->next;

    // 将新节点插入到 pre 之后
    pre->next = newNode;
}

void deleteNode(Node *&head , int val) {

    // 判断链表是否为空
    if (head == nullptr) {
        return;
    }

    // 创建哨兵节点
    Node * newhead = new Node(0, head);

    // 创建前驱节点
    Node * pre = newhead;

    // 遍历链表，寻找要删除的节点的前驱节点
    while (pre->next != nullptr) {
        if (pre->next->val == val) {
            break;
        }
        pre = pre->next;
    }

    // 删除节点
    if (pre->next != nullptr) {
        Node * tmp = pre->next;
        pre->next = pre->next->next;
        delete tmp;
    }

    // 更新头节点
    head = newhead->next;

    // 释放哨兵节点
    delete newhead;
}

int findNode(Node *head,int val) {

    // 定义索引
    int  index = 1;

    // 遍历链表，寻找节点
    while (head) {
        if (head->val == val) {
            return index;
        }
        index++;
        head = head->next;
    }

    // 找不到节点，返回-1
    return -1;
}
