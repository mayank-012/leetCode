class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
    
    int i =0;
    string ans;
    if(num.size()-k  ==0){
        
        return "0";
    }
    while(i<num.size())
    {
        if(s.empty())
        {
            s.push(num[i]);
            i++;
        }
        
        else if(s.top()>num[i] && k>0 )
        {
            s.pop();
            k--;
        }
        else if((s.top()<=num[i] || k==0))
        {
            s.push(num[i]);
            i++;
        }
        
    }
   

    while(k!=0)
    {
        s.pop();
        k--;
    }
    int n = s.size();

    for(int j =0; j< n;j++)
    {
        ans+=s.top();
        s.pop();
    }
    reverse(ans.begin(),ans.end());
    
    ans.erase(0, min(ans.find_first_not_of('0'), ans.size()-1));
    return ans;
    }
};