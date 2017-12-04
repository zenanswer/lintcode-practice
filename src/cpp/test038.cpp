#include "lintcode_comm.h"

class Solution {
public:
    /*
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int>> &matrix, int target) {
        int max_m = matrix.size();
        if (max_m == 0) {
            return 0;
        }
        int max_n = matrix[0].size();
        int count = 0;
        for(int i=0; i<max_m; i++) {
            for (int j=0; j<max_n; j++) {
                if (matrix[i][j] > target) {
                    max_n = j;
                    if (j == 0) {
                        max_m = i;
                    }
                    break;
                }
                if (matrix[i][j] == target) {
                    count++;
                }
            }
        }
        return count;
    }
};


int main(void) {
    vector<vector<int>> matrix;
    matrix.push_back(vector<int>{1, 3, 5, 7});
    matrix.push_back(vector<int>{2, 4, 7, 8});
    matrix.push_back(vector<int>{3, 5, 9, 10});

    Solution s;
    cout << s.searchMatrix(matrix, 3) << endl;

    return 0;
}
