#include <queue>
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

class Solution {
public:
    int countNodes(TreeNode* root) {
        queue<TreeNode*> r;
        if (!root){
            return r.size();
        }

        r.push(root);
        int i = 1;
        while (!r.empty()) {
            int size = r.size();
            for(int j = 0; j < size; j++){
                auto element = r.front(); r.pop();
                if (element->left != nullptr){
                    i++;
                    r.push(element->left);
                }
                if (element->right != nullptr){
                    i++;
                    r.push(element->right);
                }
            }
        }

        return i;
    }
};
