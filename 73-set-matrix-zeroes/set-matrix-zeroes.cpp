class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int col0 = 1;

        // Step 1: Mark rows and columns
        for (int i = 0; i < rows; i++) {

            if (matrix[i][0] == 0)
                col0 = 0;

            for (int j = 1; j < cols; j++) {

                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 2: Fill matrix using markers
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {

                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        // Step 3: First row
        if (matrix[0][0] == 0) {
            for (int j = 0; j < cols; j++)
                matrix[0][j] = 0;
        }

        // Step 4: First column
        if (col0 == 0) {
            for (int i = 0; i < rows; i++)
                matrix[i][0] = 0;
        }
    }
};