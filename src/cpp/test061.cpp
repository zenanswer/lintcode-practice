#include "lintcode_comm.h"


class Solution {
public:
    /*
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: a list of length 2, [index1, index2]
     */
    vector<int> searchRange(vector<int> &A, int target) {
        vector<int> result = {-1, -1};
        for (int i=0; i<A.size(); i++) {
            if (target == A[i]) {
                if (result[0] == -1) {
                    result[0] = i;
                }
                result[1] = i;
            }
        }
        return result;
    }
};


int main(void) {
    vector<int> A = {5, 7, 7, 8, 8, 10};
    Solution s;
    int target = 8;
    vector<int> result;
    result = s.searchRange(A, target);
    showVector(result);
    return 0;
}
