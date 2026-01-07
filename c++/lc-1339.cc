#include <algorithm>

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
    long long MOD = 1e9 + 7;

    void sum_total (TreeNode* Node, long long& sum){
        if (Node == nullptr) {
            return ;
        }
        sum += Node->val;
        if (Node->left != nullptr) sum_total(Node->left, sum);
        if (Node->right != nullptr) sum_total(Node->right, sum);
    }

    long long sub_sum(TreeNode* Node, long long& total, long long& ans) {
        if (Node == nullptr){
            return 0;
        }

        auto left_sum = sub_sum(Node->left, total, ans);
        auto right_sum = sub_sum(Node->right, total, ans);

        auto current_sub_sum = Node->val + left_sum + right_sum;

        if (current_sub_sum < total){
            auto product = current_sub_sum * (total - current_sub_sum);
            ans = max(ans, product);
        }

        return current_sub_sum;
    }

    int maxProduct(TreeNode* root) {
        long long total_sum {0};
        long long ans {0};

        sum_total(root, total_sum);
        sub_sum(root, total_sum, ans);

        return ans % MOD;
    }
};
