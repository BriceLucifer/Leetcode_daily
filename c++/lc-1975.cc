#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        auto num_neg {0};
        auto rows = matrix.size();
        auto cols = matrix[0].size();
        auto small_neg = abs(matrix[0][0]);
        long long result = 0;

        for(int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (matrix[i][j] < 0){
                    num_neg += 1;
                }

                // collect the abs smallest
                if (abs(matrix[i][j]) < small_neg){
                    small_neg = abs(matrix[i][j]);
                }

                result += abs(matrix[i][j]);
            }
        }

        if (num_neg % 2 == 1){
            result = result - 2 * small_neg;
            return result;
        }

        return result;
    }
};
