class Solution {
public:
int dp[201][201];
    int helper(int i,int j, vector<vector<int>>& matrix)
    {
        if( i >= matrix.size() || j>=matrix[0].size() || j<0)
        {
            return 100000000;
        }

        if(i == matrix.size()-1)return matrix[i][j];
        if(dp[i][j]!=INT_MIN)return dp[i][j];
        int ans=INT_MAX;
        for(int m =0; m<matrix[0].size();m++)
        {
            if(m==j)continue;
            else
            ans = min(ans,matrix[i][j]+helper(i+1,m,matrix));
        }
     
        return dp[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for(int i =0; i< 201;i++)
        {
            for (int j =0; j< 201;j++)
            {
                dp[i][j]= INT_MIN;
            }
        }
        int ans=INT_MAX;
        
        for(int k =0;k<matrix[0].size();k++){
        ans = min(ans,helper(0,k,matrix));
        }
        return ans;
    }
};