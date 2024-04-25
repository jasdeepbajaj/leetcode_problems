#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // Ye function jo hai board ki current state ko vector of strings me convert karega
    // Aur phir isse ans vector me store kar dega
    void storeSolution(vector<vector<char>> &board, int n, vector<vector<string>> &ans){
        vector<string> temp; // Ek temporary vector banaya jisme har row ki string store hogi

        for (int i = 0; i < n; i++)
        {   
            string s = "";
            for (int j = 0; j < n; j++)
            {
                s.push_back(board[i][j]); // Har cell ko string me add kar rahe hain
            }
            temp.push_back(s); // Puri row ko temporary solution me add kar rahe hain
        }
        
        ans.push_back(temp); // Temporary solution ko final answer me add karte hain
    }

    // Ye recursive function hai jo N-Queens problem solve karta hai
    void solve(vector<vector<char>> &board, int row, int n, vector<vector<string>> &ans){
        if (row >= n) // Base case: Agar saari rows process ho gayi hain
        {
            storeSolution(board, n, ans); // Store the current board configuration
        }

        for (int col = 0; col < n; col++) // Har column ke liye check karo
        {
            if (isSafe(row, col, board, n)) // Check karo ki queen yahan rakh sakti hai ya nahi
            {
                board[row][col] = 'Q'; // Queen place karo

                solve(board, row + 1, n, ans); // Recurse for the next row

                board[row][col] = '.'; // Backtrack: Remove the queen
            }
        }
    }

    // Ye function check karta hai ki queen ko current row aur column me safely place kiya ja sakta hai ya nahi
    bool isSafe(int row, int col, vector<vector<char>> &board, int n){
        // Vertical up direction me check karo
        for (int i = 0; i < row; i++)
        {
            if (board[i][col] == 'Q') // Agar upar kisi row me queen hai to unsafe hai
            {
                return false;
            }
        }

        // Top left diagonal check karo
        int i = row;
        int j = col;

        while (i >= 0 && j >= 0)
        {
            if (board[i][j] == 'Q') // Agar diagonal pe queen hai to unsafe hai
            {
                return false;
            }
            i--;
            j--;
        }

        // Top right diagonal check karo
        i = row;
        j = col;

        while (i >= 0 && j < n)
        {
            if (board[i][j] == 'Q') // Agar diagonal pe queen hai to unsafe hai
            {
                return false;
            }
            i--;
            j++;
        }

        return true; // Agar saari checks pass ho jaye to safe hai
    }

    // Ye function hai jo solve function ko call karta hai aur final solutions ko return karta hai
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.')); // NxN board initialize karo with all '.'
        vector<vector<string>> ans; // Isme sab answers store honge

        int row = 0; // Start karo first row se
        solve(board, row, n, ans); // Solve the N-Queens problem
        return ans; // Return all the solutions
    }
};
