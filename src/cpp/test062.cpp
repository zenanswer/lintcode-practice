#include "lintcode_comm.h"

class Solution {
public:
    /*
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target) {
        if (A.size() == 0) {
            return -1;
        }
        if (A.size() == 1) {
            if (target == A[0]) {
                return 0;
            }
            return -1;
        }
        if (target == A[0]) {
            return 0;
        }
        if (target < A[0]) {
            for (int i=1; i<A.size(); i++) {
                int flag = false;
                if (A[i-1] > A[i]) {
                    flag = true;
                }
                if (flag and target<A[i]) {
                    continue;
                }
                if (target == A[i]) {
                    return i;
                }
            }
        }
        for (int i=1; i<A.size(); i++) {
          if (A[i] < A[i-1]) {
              return -1;
          }
          if (target == A[i]) {
              return i;
          }
        }
        return -1;
    }
};

int main(void) {
    Solution s;
    vector<int> A1 = {4, 5, 1, 2, 3};
    int t1 = 1;
    cout << s.search(A1, t1) << endl;
    vector<int> A2 = {4, 5, 1, 2, 3};
    int t2 = 0;
    cout << s.search(A2, t2) << endl;
    return 0;
}
