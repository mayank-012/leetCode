class Solution {
public:
int dp[100000][3];
    int ansrbatao(vector<int>& prices, int pos, int b) {
        if (pos == prices.size())
            return 0;
        if(dp[pos][b]!=-1)return dp[pos][b];
        if (b == 0) {
            return dp[pos][b]=max(-prices[pos] + ansrbatao(prices, pos + 1, 1), ansrbatao(prices, pos + 1, 0));
        } 
        else {
            return dp[pos][b]=max(prices[pos], ansrbatao(prices, pos + 1, 1));
        }
    }
    int maxProfit(vector<int>& prices) { 
        memset(dp,-1,sizeof(dp));
        return ansrbatao(prices, 0, 0);
         }
};