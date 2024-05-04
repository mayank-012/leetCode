class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n=version1.size();
        int m=version2.size();
        int v1=0,v2=0;

        while(v1<n || v2<m){
            int n1=0,n2=0;

            while(v1<n && version1[v1]!='.'){
                n1=n1*10+(version1[v1]-'0');
                v1++;
            }
            
            while(v2<m && version2[v2]!='.'){
                n2=n2*10+(version2[v2]-'0');
                v2++;
            }

            if(n1>n2){
                return 1;
            }
            else if(n1<n2){
                return -1;
            }
            v1++;
            v2++;
        }
        return 0;
        
    }
};