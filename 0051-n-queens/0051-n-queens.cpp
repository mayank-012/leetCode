class Solution {
public:
    bool isPos(int row, int col, vector<string> &board, int n)
    {
        int tRow=row;
        int tCol=col;

        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q')
            {
                return 0;
            }
            else{
                row--;
                col--;
            }
        }

        row = tRow;
        col = tCol;
        while(col>=0)
        {
            if(board[row][col]=='Q')
            {
                return 0;
            }
            else{
                col--;
            }
        }
        row = tRow;
        col = tCol;
        while(row<n && col>=0)
        {
            if(board[row][col]=='Q')
            {
                return 0;
            }
            else{
                row++;
                col--;
            }
        }
        return 1;
    }


    void solve(int col, vector<string> &board,int n, vector<vector<string>> &ans )
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }

        for(int row =0; row<n;row++)
        {
            if(isPos(row,col, board,n))
            {
                board[row][col]='Q';
                solve(col+1,board,n,ans);
                board[row][col]='.';
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i =0; i< n; i++)
        {
            board[i]=s;
        }
        solve(0,board,n,ans);
         return ans;


    }
};