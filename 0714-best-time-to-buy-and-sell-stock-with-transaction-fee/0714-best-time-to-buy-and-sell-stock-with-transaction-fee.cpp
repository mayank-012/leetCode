class Solution {
public:
    int dp[50000][3];
    int helper(vector<int>& prices, int fee,int i,int b){
            if(i == prices.size())
            {
                return 0;
            }
            if(dp[i][b]!=-1)return dp[i][b];
            if(b==0)
            {
                return dp[i][b] = max(-prices[i]+helper(prices,fee,i+1,1),helper(prices,fee,i+1,0));
            }
            else{
                return dp[i][b] = max(prices[i]-fee+helper(prices,fee,i+1,0),helper(prices,fee,i+1,1));
            }
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        return helper(prices,fee,0,0);
    }
};