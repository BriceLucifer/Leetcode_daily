struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        while(head && head->val == val) head = head->next;   //排除第一个节点就相等的情况

        if(!head) return head;  //这里有两层意义，第一是本来就是空的([])，第二种是全部删光了的([7,7,7,7]) 注意：一定写在上一步while之后

        ListNode* slow = head;     //定义快慢指针，也要写在上一步之后
        ListNode* fast = head->next;

        while(fast) {
            if(fast->val==val) {        //遇到相等就删除
                slow->next = fast->next;
                fast = slow->next;
            }  else {                   //否则快慢指针依次后移
                slow = slow->next;
                fast = fast->next;
            }
        }
        return head;
    }
};
