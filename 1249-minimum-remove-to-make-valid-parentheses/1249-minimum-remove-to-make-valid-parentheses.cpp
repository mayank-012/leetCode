class Solution {
public:
    string minRemoveToMakeValid(string s) {
       
        stack <int> st;
        set <int> sett;
        for(int i =0; i< s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')' && st.size()>0)
            {
                if(s[st.top()]=='(')
                {
                    st.pop();
                }
                else{
                    st.push(i);
                }
            }
            else if(s[i]==')' && st.size()==0)
            {
                st.push(i);
            }  
        }
        while(st.size()>0)
        {
            sett.insert(st.top());
            st.pop();
        }
        string ans;
        for(int i =0; i< s.size();i++)
        {
            if(sett.find(i)!=sett.end())
            {
                continue;
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};