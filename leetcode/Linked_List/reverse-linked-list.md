# 反转链表

[力扣题目链接](https://leetcode-cn.com/problems/reverse-linked-list/)

## 题目

给你单链表的头节点`head`，请你反转链表，并返回反转后的链表。

示例：
```
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
```

提示：

* 链表中节点的数目范围是 `[0, 5000]`
* `-5000 <= Node.val <= 5000`

## 解题思路
### 迭代
1. 创建3个指针
* `pre`：指向当前节点
* `cur`：暂存当前节点的下一个节点
* `t`: 反转后的链表头节点
2. 遍历链表:
* `cur`指向`pre`的下一个节点
* `pre`的下一个节点指向`t`
* `t`指向`pre`,更新反转后头节点
* `pre`指向`cur`
3. 返回反转后的头节点`t`

```cpp
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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = head;
        ListNode* cur;
        ListNode* t = nullptr;
        while (pre != nullptr) {
            cur = pre->next;
            pre->next = t;
            t = pre;
            pre = cur;
        }
        return t;
    }
};
```

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur = head
        t = None
        while cur:
            pre = cur.next
            cur.next = t
            t = cur
            cur = pre
        return t
```

### 递归
1. 递归结束条件：当前节点为空，返回当前节点
2. 递归调用：递归调用当前节点的下一个节点，并将当前节点的下一个节点指向当前节点
3. 返回递归结果

```cpp
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // 递归调用
        ListNode* newhead = reverseList(head->next);

        // 反转
        head->next->next = head;
        head->next = nullptr;

        // 返回反转后的头节点
        return newhead;
    }
};
```
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        newhead = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return newhead
```