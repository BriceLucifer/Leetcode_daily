struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };


 // 快慢指针大法
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head->next == nullptr && head == nullptr) {
            return false;
        }

        auto slow = head;
        auto fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }

        return false;
    }
};
