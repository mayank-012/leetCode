class Solution {
public:
int dp[1000][3][100];
    int helper(int i,vector<int>& prices,int b,int k,int c)
    {
        if(i==prices.size() || c==k)
        return 0;
        if(dp[i][b][c]!=-1)return dp[i][b][c];
        if(b==0)
        {
            return dp[i][b][c]=max(-prices[i]+helper(i+1,prices,1,k,c),helper(i+1,prices,0,k,c));
        }
        else{
            return dp[i][b][c]=max(prices[i]+helper(i+1,prices,0,k,c+1),helper(i+1,prices,1,k,c));
        }
        
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return helper(0,prices,0,k,0);
    }
};