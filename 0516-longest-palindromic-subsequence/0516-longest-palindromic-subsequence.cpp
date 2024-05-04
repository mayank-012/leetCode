class Solution {
public:
    int dp[1000][1000];
    int helper(string &s, int i,int j)
    {
        if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
        int ans;
       if(s[i]==s[j] && i!=j)
       {
            ans = 2+helper(s,i+1,j-1);
       }
       else if(s[i]==s[j] && i==j)
       {
            ans = 1+helper(s,i+1,j-1);
       }
       else{
         ans = max(helper(s,i+1,j), helper(s,i,j-1));
       }
       return dp[i][j]=ans;
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        return helper(s,0,s.size()-1);
    }
};