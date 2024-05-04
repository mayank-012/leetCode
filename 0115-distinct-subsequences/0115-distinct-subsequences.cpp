class Solution {
public:
int dp[1000][1000];
    int helper(string &s, string &t,int i, int j)
    {
        if(i==s.size())
        {
            if(j==t.size())return 1;
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(s[i]==t[j])
        {
            ans += helper(s,t,i+1,j+1);
            ans+=helper(s,t,i+1,j);
        }
        else{
            ans += helper(s,t,i+1,j);
        }
        return dp[i][j]=ans;
    }
    int numDistinct(string s, string t) {
        
        memset(dp,-1,sizeof(dp));
        return helper(s,t,0,0);

    }
};