#include <climits>
#include <cstddef>
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
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) return 0;

        int max_value = INT_MIN;
        int level = 1;
        int idx = 1;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto size = q.size();
            auto sum = 0;
            for(int i = 0; i < size; i++){
                auto value = q.front(); q.pop();
                sum += value->val;
                if (value->left != nullptr) q.push(value->left);
                if (value->right != nullptr) q.push(value->right);
            }
            if (sum > max_value){
                max_value = sum;
                level = idx;
            }
            idx++;
        }

        return level;
    }
};
