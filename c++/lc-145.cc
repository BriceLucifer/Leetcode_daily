#include <vector>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 using namespace std;

// 后序排列：
//  left - right - root
class Solution {
public:
    void dfs(vector<int>& result, TreeNode* root){
        if (root != nullptr){
            dfs(result, root->left);
            dfs(result, root->right);
            result.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(result, root);
        return result;
    }
};
