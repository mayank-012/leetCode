class Solution {
public:

    vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    s.push(n);
    vector<int> ans(n);

    for(int i = n-1; i>=0; i--){
        int curr = arr[i];

        while(s.top()!= n && (arr[s.top()] >= curr))
        {
            s.pop();
        }

        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = 0; i<=n-1; i++){
        int curr = arr[i];

        while(s.top()!= -1 && (arr[s.top()] >= curr))
        {
            s.pop();
        }

        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}

 
 int largestRectangle(vector < int > & heights) {
   // Write your code here.
   int n = heights.size();

   vector <int> prev(n);
   prev = prevSmallerElement(heights, n);

   vector <int> next(n);
   next = nextSmallerElement(heights, n);

   int area = INT_MIN;
   for(int i =0; i< n; i++)
   {
     area = max(area, heights[i]*(next[i]-prev[i]-1));
   }
   return area;
 }


    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int > row(m) ;
        for(int i = 0; i< m ; i++)
        {
            row[i] = int(mat[0][i]-'0');
        }

	int area = largestRectangle(row);

	for(int i = 1; i< n;i++)
	{
		for (int j = 0; j<m; j++)
		{
			if(mat[i][j]!='0')
			{
				row[j] = row[j]+int(mat[i][j]-'0');
			}
			else{
				row[j]=0;
			}
		}
		area = max(area,largestRectangle(row));
	}
	return area;
    }
};