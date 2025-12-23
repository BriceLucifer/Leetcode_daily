struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


#include <vector>

using namespace std;
// 前序遍历 root = left - right

class Solution {
public:
    void dfs(vector<int>& r, TreeNode* root){
        if (root != nullptr){
            r.push_back(root->val);
            dfs(r, root->left);
            dfs(r, root->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(result, root);
        return result;
    }
};
