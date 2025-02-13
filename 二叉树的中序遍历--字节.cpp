include <vector>
#include <stack>
using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans; // 用于存储遍历结果的向量
        stack<TreeNode*> s; // 用于辅助遍历的栈

        // 循环条件：当前节点不为空，或者栈不为空
        while (root != NULL || !s.empty()) {
            // 把左子树的所有节点压入栈中
            while (root != NULL) {
                s.push(root); // 将当前节点压入栈
                root = root->left; // 移动到当前节点的左子节点
            }

            // 当前节点为空时，从栈中弹出一个节点
            root = s.top(); // 获取栈顶节点
            s.pop(); // 弹出栈顶节点
            ans.push_back(root->val); // 将弹出节点的值加入结果向量
            root = root->right; // 移动到当前节点的右子节点
        }

        return ans; // 返回遍历结果
    }
};
