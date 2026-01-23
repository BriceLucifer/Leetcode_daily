 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


 class Solution {
 public:
     ListNode* reverse(ListNode* head, ListNode* prev) {
         if (!head) return prev;
         auto next = head->next;
         head->next = prev;
         return reverse(next, head);
     }

     ListNode* reverseBetween(ListNode* head, int left, int right) {
         if (!head || left == right) return head;

         ListNode dummy(0);
         dummy.next = head;
         ListNode* pre = &dummy;

         // 1. 找到 left-1
         for (int i = 1; i < left; i++) {
             pre = pre->next;
         }

         ListNode* leftNode = pre->next;
         ListNode* rightNode = leftNode;

         // 2. 找到 right
         for (int i = left; i < right; i++) {
             rightNode = rightNode->next;
         }

         ListNode* rightNext = rightNode->next;

         // 3. 断链
         rightNode->next = nullptr;

         // 4. 反转
         ListNode* newHead = reverse(leftNode, nullptr);

         // 5. 接回
         pre->next = newHead;
         leftNode->next = rightNext;

         return dummy.next;
     }
 };
