class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        map<string,int> mpp;
        
        for(int i =0; i< word.size();i+=k)
        {
            mpp[word.substr(i,k)]++;
        }
        
        int temp=0;
        for(auto it :mpp)
        {
            temp = max(temp,it.second);
                    

        }
        return word.size()/k - temp;
    }
};