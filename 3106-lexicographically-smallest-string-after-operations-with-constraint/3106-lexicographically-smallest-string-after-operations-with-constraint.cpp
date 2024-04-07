class Solution {
public:
    string getSmallestString(string s, int k) {
        string ans =s;
        
        for(int i=0; i< s.size();i++)
        {
            while(k>0 && ans[i]!='a')
            {
                if(ans[i]!='z' && ans[i]!='a'){
                    if('z'-ans[i]+1<=ans[i]-'a'){
                    if('z'-ans[i]+1<=k)
                    {
                        k=k-('z'-ans[i]+1);
                                                ans[i]='a';

                    }
                    else{
                        if(ans[i]-k>='a')
                        {
                             ans[i]=ans[i]-k;
                                k=0;
                        }
                        else{
                            k = k- (ans[i]-'a');
                            ans[i]='a';

                        }
                       
                    }
                    }
                    else{
                        
                    if(~('z'-ans[i]+1<=k)){
                        if(ans[i]-k>='a')
                        {
                             ans[i]=ans[i]-k;
                                k=0;
                        }
                        else{
                            k = k- (ans[i]-'a');
                            ans[i]='a';

                        }
                       
                    }
                       else
                    {
                        k=k-('z'-ans[i]+1);
                        ans[i]='a';

                    }
                    }
                
                }
                
                else if(ans[i]=='z'){
                    ans[i]='a';
                    k--;
                }
            }
            if(k==0)
                break;
        }
        return ans;
        
    }
};