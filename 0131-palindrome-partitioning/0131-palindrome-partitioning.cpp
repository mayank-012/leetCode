class Solution {
public:
bool isP(string S)
{
    // Iterate over the range [0, N/2]
    for (int i = 0; i < S.length() / 2; i++) {
 
        // If S[i] is not equal to
        // the S[N-i-1]
        if (S[i] != S[S.length() - i - 1]) {
            // Return No
            return 0;
        }
    }
    // Return "Yes"
    return 1;
}
    void helper(vector<vector<string>> &ans,vector<string> &temp,string &s,int i)
    {
        if(i == s.size()){
            ans.push_back(temp);
            return;
        }
        string st;
        for(int j =i; j<s.size();j++)
        {
            st.push_back(s[j]);
            if(isP(st))
            {
                temp.push_back(st);
                helper(ans,temp,s,j+1);
                temp.pop_back();
            }
        }
        return;

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        helper(ans,temp,s,0);
        return ans;
    }
};