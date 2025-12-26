#include <queue>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

class Solution {
public:
    void dfs(TreeNode* node, int targetSum, int sum, bool& flag){
        if (node == nullptr){
            return;
        }

        sum += node->val;
        if (node->left == nullptr && node->right == nullptr && sum == targetSum){
            flag = true;
        }

        dfs(node->left, targetSum, sum, flag);
        dfs(node->right, targetSum, sum, flag);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool flag = false;
        dfs(root, targetSum, 0, flag);
        return flag;
    }
};
