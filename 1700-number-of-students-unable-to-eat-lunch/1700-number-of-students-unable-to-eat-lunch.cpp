class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue <int> q;

        stack <int> st;

        for(int i =0; i<students.size();i++)
        {
            q.push(students[i]);
        }
        for(int j=sandwiches.size()-1;j>=0;j--)
        {
            st.push(sandwiches[j]);
        }
        int cnt=0;
        while(q.size()!=0 && cnt<=q.size())
        {
            if(q.front()==st.top())
            {
                q.pop();
                st.pop();
                cnt=0;
            }
            else{
                int t = q.front();
                q.pop();
                q.push(t);
                cnt++;
            } 
        }
        return q.size();
    }
};