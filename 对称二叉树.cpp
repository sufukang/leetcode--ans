class Solution {
public:
    bool check(TreeNode* root1, TreeNode* root2) {
        // base case
        // 1.如果两个节点都为空
        // 2.如果两个节点有一个为空，
        // 3.如果两个节点的值不相等，返回false
        if (root1 == NULL && root2 == NULL)
            return true;

        if (root1 == NULL || root2 == NULL)
            return false;
        if (root1->val != root2->val)
            return false;
        return check(root1->right, root2->left) &&
       check(root1->left, root2->right) && (root1->val == root2->val);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return check(root->right, root->left);
    }
};
