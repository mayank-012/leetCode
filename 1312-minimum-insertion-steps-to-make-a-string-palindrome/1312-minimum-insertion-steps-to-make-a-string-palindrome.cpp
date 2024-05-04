class Solution {
public:
int dp[500][500];
    int helper(int i, int j, string &s)
    {
        if(j<i)return 0;
        int ans=0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j])
        {
            ans += helper(i+1,j-1,s);
        }
        else{
            ans+=min(1+helper(i+1,j,s),1+helper(i,j-1,s));
        }
        return dp[i][j]=ans;
    }
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
        return helper(0,s.size()-1,s);
    }
};