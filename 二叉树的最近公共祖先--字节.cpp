class Solution {
public:
    // 深度优先遍历
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 递归终止条件
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        // 递归检查左右子树
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // 判断最近公共祖先
        if (left != nullptr && right != nullptr) {
            return root; // p 和 q 分别位于左右子树中，当前节点是 LCA
        }
        return left != nullptr ? left : right; // 返回非空的子树结果
    }
/*
如果当前节点为空，返回 nullptr。
如果当前节点是 p 或 q，返回当前节点。
递归检查左右子树：

递归地在左子树中查找 p 和 q。
递归地在右子树中查找 p 和 q。
判断最近公共祖先：

如果 p 和 q 分别位于当前节点的左右子树中，那么当前节点就是它们的最近公共祖先。
如果 p 和 q 都位于左子树中，则最近公共祖先在左子树中。
如果 p 和 q 都位于右子树中，则最近公共祖先在右子树中。
*/
    }
};
