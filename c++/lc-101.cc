struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void compare(TreeNode* node1, TreeNode* node2, bool &flag){
        if (node1 == nullptr && node2 == nullptr){
            flag = true;
            return;
        }

        if (node1 == nullptr && node2 != nullptr || node1 != nullptr && node2 == nullptr){
            flag = false;
            return;
        }

        if (node1->val == node2->val){
            flag = true;
        }else{
            flag = false;
            return;
        }

        compare(node1->left, node2->right, flag);
        if (flag == false) {
            return;
        }
        compare(node1->right, node2->left, flag);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr){
            return true;
        }
        auto flag = true;
        compare(root->left, root->right, flag);
        return flag;
    }
};
