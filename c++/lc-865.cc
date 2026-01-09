#include <utility>

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
    pair<int, TreeNode*> dfs(TreeNode* node){
        if (!node) return {0,nullptr};

        auto [ld, ln] = dfs(node->left);
        auto [rd, rn] = dfs(node->right);

        if (ld == rd) {
            return {ld + 1, node};
        } else if (ld > rd) {
            return {ld + 1, ln};
        } else {
            return {rd + 1, rn};
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};
