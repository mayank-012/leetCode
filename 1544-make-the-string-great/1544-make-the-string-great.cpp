class Solution {
public:
    string makeGood(string s) {
        stack<char>  st;
        // st.push(s[0]);
        for(int i=0; i<s.size();i++)
        {
           
           if(st.size()!=0){
            if(abs(st.top()-s[i])!=32)
            {
                st.push(s[i]);
            }
            else{
                st.pop();
            }
           }
           else{
            st.push(s[i]);
           }
        }
        string ans;

        while(st.size()!=0)
        {
            char temp = st.top();
            ans.push_back(temp);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
    return ans;
    }
};