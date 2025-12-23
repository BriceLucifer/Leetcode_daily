#include <cstddef>
#include <functional>
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

// 中序遍历
// left - root - right
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr){
            return {};
        }

        vector<int> result;
        function<void(TreeNode*)> dfs = [&](TreeNode *r){
            if (r != nullptr){
                dfs(r->left);
                result.push_back(r->val);
                dfs(r->right);
            }
        };

        dfs(root);
        return result;
    }
};
