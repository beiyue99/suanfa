

//翻转链表，翻转 m,n之间的节点。首先找到m前驱节点pre，然后让cur位m节点
//循环m-n次，每次让tmp=cur的next,然后执行三个语句：
// 1.   cur->next=tmp->next    2.  tmp->next=pre->next  3.pre->next=tmp
//

class Solution {
public:
  // 反转链表从第 m 个节点到第 n 个节点之间的部分
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (!head || m == n)
      return head; // 如果 m 等于 n，则不需要反转
    ListNode *dummy = new ListNode(-1); // 创建一个虚拟节点
    dummy->next = head;
    ListNode *pre = dummy;

    for (int i = 0; i < m - 1; i++) {
      pre = pre->next; // 将 pre 移动到第 m 个节点的前一个节点
    }

    ListNode *cur = pre->next; // cur 指向第 m 个节点
    ListNode *temp = nullptr;

    for (int i = 0; i < n - m; i++) {
      temp = cur->next;       // temp 指向 cur 的下一个节点
      cur->next = temp->next; // 从链表中移除 temp
      temp->next = pre->next; // 将 temp 插入到 pre 之后
      pre->next = temp;       // 将 pre 连接到 temp
    }

    head = dummy->next;
    delete dummy;
    return head;
  }
};
//这是测试代码
