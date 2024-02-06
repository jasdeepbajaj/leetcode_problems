class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        // Get the dimensions of the input matrix
        int m = matrix.size(); 
        int n = matrix[0].size();
    
        // Create an output matrix with transposed dimensions 
        vector<vector<int>> v1(n, vector<int>(m,0)); 
        
        // Iterate through input matrix
        for(int i = 0; i<m; i++){
            
            // Iterate through columns
            for(int j=0; j<n; j++)
                
                // Set value in transposed location
                v1[j][i] = matrix[i][j]; 
        }

        // Return transposed matrix
        return v1;
        
    }
};