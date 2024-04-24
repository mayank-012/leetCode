class Solution {
public:
int dp[100000][3][3];
    int helper(int i,int c,vector<int>& prices,int b)
    {
        if(i==prices.size())
        return 0;
        if(dp[i][c][b]!=-1)return dp[i][c][b];
        if(c==0 && b==0)
        {
            return dp[i][c][b]=max(-prices[i]+helper(i+1,1,prices,1),helper(i+1,0,prices,0));
        }
        else if(c==1 && b==0)
        {
            return dp[i][c][b]=max(-prices[i]+helper(i+1,2,prices,1),helper(i+1,1,prices,0));
        }
        else if(c==1 && b==1)
        {
            return dp[i][c][b]=max(prices[i]+helper(i+1,1,prices,0),helper(i+1,1,prices,1));
        }
        else 
        { 
            return dp[i][c][b]=max(prices[i],helper(i+1,2,prices,1));
        }
        
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,prices,0);
    }
};