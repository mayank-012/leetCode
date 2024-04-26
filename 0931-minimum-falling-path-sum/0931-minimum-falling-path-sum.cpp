class Solution {
public:
    int dp[101][101];
    int helper(int i,int j, vector<vector<int>>& matrix)
    {
        if( i >= matrix.size() || j>=matrix[0].size() || j<0)
        {
            return 100000000;
        }

        if(i == matrix.size()-1)return matrix[i][j];
        if(dp[i][j]!=-101)return dp[i][j];
        int l,r,t;
        l = matrix[i][j]+helper(i+1,j,matrix);
        r = matrix[i][j]+helper(i+1,j-1,matrix);
        t = matrix[i][j]+helper(i+1,j+1,matrix);
        return dp[i][j] = min(l,min(r,t));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for(int i =0; i< 101;i++)
        {
            for (int j =0; j< 101;j++)
            {
                dp[i][j]=-101;
            }
        }
        int ans=INT_MAX;
        
        for(int k =0;k<matrix[0].size();k++){
        ans = min(ans,helper(0,k,matrix));
        }
        return ans;

    }
};
