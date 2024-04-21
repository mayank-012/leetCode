class Solution {
public:
    int numberOfSpecialChars(string word) {
        map <char,int> mpp;
        int cnt=0;
        for(int i =0; i< word.size();i++)
        {
            if(word[i]>='a' && word[i]<='z')
            {
                if(mpp.find(word[i]-32)!=mpp.end())
                {
                    mpp[word[i]]=0;
                }
                else{
                    mpp[word[i]]++;
                }
            }
            else{
                 mpp[word[i]]++;
            }
        }
        for(auto it :mpp)
        {
            if(it.first>='a' && it.first<='z')
            {
                break;
            }
            else{
                if(mpp.find(it.first+32)!=mpp.end() && mpp[it.first+32]>0)
                    cnt++;
            }
        }
        return cnt;
    }
};