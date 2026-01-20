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
    void check(TreeNode* root, TreeNode* parent, int value,
               int& depth, bool& find, TreeNode*& parOut) {
        if (!root) return;
        if (root->val == value) {
            find = true;
            parOut = parent;
            return;
        }

        int temp = depth;
        depth = temp + 1;
        check(root->left, root, value, depth, find, parOut);
        if (find) return;

        depth = temp + 1;
        check(root->right, root, value, depth, find, parOut);
        if (find) return;

        depth = temp; // 回到当前层（可有可无，因为上层也会设置）
    }

    bool isCousins(TreeNode* root, int x, int y) {
        int dx = 0, dy = 0;
        bool fx = false, fy = false;
        TreeNode* px = nullptr;
        TreeNode* py = nullptr;

        check(root, nullptr, x, dx, fx, px);
        check(root, nullptr, y, dy, fy, py);

        return fx && fy && dx == dy && px != py;
    }
};
