#include "lintcode_comm.h"


class Solution {
public:
    /*
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int>& A) {
        int end = A.size();
        if (end <= 1) {
            return 0;
        }
        int start = 0;
        for (;start!=(end-1);) {
            int mid = (start+end)/2;
            if(A[mid]<A[mid+1]) {
                start = mid;
            } else {
                end = mid;
            }
        }
        return end;
    }
};

int main(void) {
    vector<int> A = {1, 2, 1, 3, 4, 5, 7, 6};
    Solution s;
    cout << s.findPeak(A) << endl;
}
