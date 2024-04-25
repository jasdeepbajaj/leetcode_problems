#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // Yeh function board ki current state ko vector of strings mein convert karta hai
    // Aur phir ise ans vector mein store kar deta hai
    void storeSolution(vector<vector<char>> &board, int n, vector<vector<string>> &ans){
        vector<string> temp; // Ek temporary vector banaya gaya jisme har row ki string store hogi

        for (int i = 0; i < n; i++)
        {   
            string s = "";
            for (int j = 0; j < n; j++)
            {
                s.push_back(board[i][j]); // Har cell ko string mein add karte hain
            }
            temp.push_back(s); // Puri row ko temporary solution mein add kar rahe hain
        }
        
        ans.push_back(temp); // Temporary solution ko final answer mein add karte hain
    }

    // Yeh recursive function N-Queens problem ko solve karta hai
    void solve(vector<vector<char>> &board, int row, int n, vector<vector<string>> &ans, int &count){
        if (row >= n) // Base case: Jab saari rows process ho jaati hain
        {
            storeSolution(board, n, ans); // Store the current board configuration
            count++;
            return;
        }

        for (int col = 0; col < n; col++) // Har column ke liye check karo
        {
            if (isSafe(row, col, board, n)) // Check karo ki queen yahan rakh sakte hain ya nahi
            {
                board[row][col] = 'Q'; // Queen ko place karo

                solve(board, row + 1, n, ans, count); // Next row ke liye recurse karo

                board[row][col] = '.'; // Backtrack: Queen ko hatao
            }
        }
    }

    // Yeh function check karta hai ki queen ko current row aur column mein safely place kiya ja sakta hai ya nahi
    bool isSafe(int row, int col, vector<vector<char>> &board, int n){
        // Vertical up direction mein check karo
        for (int i = 0; i < row; i++)
        {
            if (board[i][col] == 'Q') // Agar upar kisi row mein queen hai to yeh unsafe hai
            {
                return false;
            }
        }

        // Top left diagonal check karo
        int i = row;
        int j = col;

        while (i >= 0 && j >= 0)
        {
            if (board[i][j] == 'Q') // Agar diagonal pe queen hai to yeh unsafe hai
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
            if (board[i][j] == 'Q') // Agar diagonal pe queen hai to yeh unsafe hai
            {
                return false;
            }
            i--;
            j++;
        }

        return true; // Agar saare checks pass ho jaaye to yeh safe hai
    }

    // Yeh function solve function ko call karta hai aur final solutions ko return karta hai
    int totalNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.')); // NxN board ko initialise karo sab cells ko '.' se
        vector<vector<string>> ans; // Yahaan sabhi answers store honge

        int row = 0; // Pehli row se shuru karo
        int count = 0;
        solve(board, row, n, ans, count); // N-Queens problem ko solve karo
        return count; // Sabhi solutions return karo
    }
};
