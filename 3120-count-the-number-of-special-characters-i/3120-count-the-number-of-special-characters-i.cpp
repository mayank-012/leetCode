class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt=0;
        map<char,int> mpp;
        for(int i = 0;i< word.size();i++)
        {
            mpp[word[i]]++;
        }
        for(auto it :mpp)
        {
            if(it.first>='a' && it.first<='z')
            {
                break;
            }
            else{
                if(mpp.find(it.first+32)!=mpp.end())
                    cnt++;
            }
        }
        return cnt;
    }
};