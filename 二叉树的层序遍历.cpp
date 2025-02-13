class Solution {
public:
vector<vector<int>> levelOrder(TreeNode* root) {
    if(root==NULL)  
        return {};//特判
    vector<vector<int>>ans;//返回的结果
    queue<TreeNode*>q;//创建辅助队列
    q.push(root);//根节点入队
    while(!q.empty()){
        int size=q.size();
        vector<int>tmp;//用于记录每一层的数字
        for(int i=0;i<size;i++){
            auto x=q.front();
            q.pop();
            tmp.push_back(x->val);//弹出x
            if(x->left)q.push(x->left);//有左加左
            if(x->right)q.push(x->right);//有右加右
        }
        ans.push_back(tmp);
    }
    return ans;

}
};
