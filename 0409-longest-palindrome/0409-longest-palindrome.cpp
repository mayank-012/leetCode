class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size()==1)return 1;
        sort(s.begin(),s.end());
        int odd = 0;
        int cnt = 1;
        int ans = 0;
        for(int i =0; i< s.size()-1;i++)
        {
            if(s[i]==s[i+1])
            {
                cnt++;
            }
            else{
                if(cnt%2==0)
                {
                    ans +=cnt;
                    cnt = 1;
                }
                else{
                    odd++;
                    ans += cnt-1;
                    cnt = 1;
                }
            }
        }
        if(cnt%2==0)
                {
                    ans +=cnt;
                    cnt = 1;
                }
                else{
                    if(odd==0)
                    ans += cnt;
                    else
                    ans +=cnt-1;
                    cnt = 1;
                }
        if(odd>0)ans+=1;

        return ans;
    }
};