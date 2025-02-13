class Solution {
public:
TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
    //key是数组的值，value是下标
    unordered_map<int,int>m;
    for(int i=0;i<in.size();i++)
        m[in[i]]=i;
    //只关心有哪些参数，返回值是
    return f(pre,0,pre.size()-1,in,0,in.size()-1,m);
}
TreeNode* f(vector<int>&pre,int l1,int r1,vector<int>&in,int l2,int r2,unordered_map<int,int>&m){
    if(l1>r1)//base case
        return NULL;
    TreeNode*head=new TreeNode(pre[l1]);
    int k=m[pre[l1]];//找k
    head->left=f(pre,l1+1,l1+k-l2,in,l2,k-1,m);
    head->right=f(pre,l1+k-l2+1,r1,in,k+1,r2,m);
    return head;
}
};
