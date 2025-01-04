[返回目录](../readme.md)

# 链表
链表是一种线性数据结构，但它与数组不同的是它在物理上不连续，但逻辑上是连续的。


## 分类

链表有两种：单链表和双链表。

* 单链表：链表中的每个节点只有一个指向下一个节点的指针。
* 双链表：链表中的每个节点有两个指针，一个指向下一个节点，另一个指向前一个节点。

## 单链表

> 注：C++ 语言实现

### 构造

链表一般包含两个部分：节点和指针。

```cpp
struct Node {
    int val;  // 链表节点值
    Node *next;  // 指向下一个节点的指针

    // 构造函数
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *n) : val(x), next(n) {}
};
```
### 插入

流程：
1. 创建临时节点
2. 将pre节点的下一个节点赋值给新节点的next
3. 将新节点插入到 pre 之后

```cpp
void insertNode(Node *pre, int val) {
    
    // 创建临时节点
    Node *newNode = new Node(val);

    // 将pre节点的下一个节点赋值给新节点的next
    newNode->next = pre->next;

    // 将新节点插入到 pre 之后
    pre->next = newNode;
}
```

### 删除

删除节点我们可以采用哨兵节点的方式，避免出现删除头节点的特殊情况。

**哨兵节点**
我们在链表的头节点之前插入一个哨兵节点，方便对头节点进行操作。
1. 创建哨兵节点
2. 将哨兵节点的下一个节点赋值给头节点
3. 删除指定节点
4. 返回哨兵节点的下一个节点并释放哨兵节点

```cpp
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
```

### 查找

```cpp
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
```

### 参考代码
[LinkedList.cpp](./ListNode.cpp)

## 进阶用法

### 反转链表

[跳转](../../../leetcode/Linked_List/reverse-linked-list.md)



