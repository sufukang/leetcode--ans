class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //额外创建一个二维数组，用于存储0的位置信息
        int m=matrix.size();//行
        int n=matrix[0].size();//列
        vector<vector<int>>flg(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                    flg[i][j]=1;//有1的地方代表有0
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(flg[i][j]==1)
                {
                    for(int p=0;p<n;p++)
                        matrix[i][p]=0;
                    for(int q=0;q<m;q++)
                        matrix[q][j]=0;
                }
            }
        }
    }
};
