class Solution {
public:
    bool helper(vector<vector<char>>& board, string &word,int i, int j,int k)
    {
        if(k==word.size())return 1;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size())return 0;
        
        if(board[i][j]==word[k])
        {
            char temp = board[i][j];
            board[i][j]='0';
            bool res= helper(board,word,i-1,j,k+1)||
            helper(board,word,i+1,j,k+1)||
            helper(board,word,i,j-1,k+1)||
            helper(board,word,i,j+1,k+1);
            board[i][j]=temp;
            return res;
        }
        else{
            return 0;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
       bool ans =0;
       for(int i =0; i< board.size();i++)
       {
        for(int j =0; j< board[0].size();j++)
        {
            ans = ans||helper(board,word,i,j,0);
        }
       }
        return ans;
       
    }
};