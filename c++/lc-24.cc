struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        auto result = new ListNode(0, head);
        auto x = result;

        while (x->next && x->next->next) {
            auto a = x->next;
            auto b = a->next;
            // element 2 -> 4
            a->next = b->next;
            x->next = b;
            b->next = a;

            x = a;
        }

        return result->next;
    }
};
