#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void storeSolution(vector<vector<char>> &board, int n, vector<vector<string>> &ans){

        vector<string> temp;

        for (int i = 0; i < n; i++)
        {   
            string s = "";
            for (int j = 0; j < n; j++)
            {
                s.push_back(board[i][j]);
            }
            temp.push_back(s);
        }
        
        ans.push_back(temp);


    }

    void solve(vector<vector<char>> &board, int row, int n, vector<vector<string>> &ans){

        if (row>=n)
        {
            storeSolution(board, n, ans);
        }

        for (int col = 0; col < n; col++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';

                solve(board, row + 1, n, ans);

                board[row][col] = '.';
            }
            

        }
        
        

    }

    bool isSafe(int row, int col, vector<vector<char>> &board, int n){
        
        for (int i = 0; i < row; i++)
        {
            if (board[i][col] == 'Q')
            {
                return false;
            }
            
        }

        int i = row;
        int j = col;

        while (i>=0 && j>=0)
        {
            if (board[i][j]=='Q')
            {
                return false;
            }
            i--;
            j--;
        }

        i = row;
        j = col;

        while (i>=0 && j<n)
        {
            if (board[i][j]=='Q')
            {
                return false;
            }
            i--;
            j++;
        }

        return true;
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;

        int row = 0;
        solve(board, row, n, ans);
        return ans;
        
    }
};