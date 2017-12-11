#include "lintcode_comm.h"

class Solution {
public:
    /*
     * @param A: an integer ratated sorted array and duplicates are allowed
     * @param target: An integer
     * @return: a boolean
     */
    bool search(vector<int> &A, int target) {
        if (A.size() == 0) {
            return false;
        }
        if (A.size() == 1) {
            if (target == A[0]) {
                return true;
            }
            return false;
        }
        if (target == A[0]) {
            return true;
        }
        if (target < A[0]) {
            for (int i=1; i<A.size(); i++) {
                int flag = false;
                if (A[i-1] == A[i]) {
                    continue;
                }
                if (A[i-1] > A[i]) {
                    flag = true;
                }
                if (flag and target<A[i]) {
                    continue;
                }
                if (target == A[i]) {
                    return true;
                }
            }
        }
        for (int i=1; i<A.size(); i++) {
          if (A[i-1] == A[i]) {
              continue;
          }
          if (A[i] < A[i-1]) {
              return false;
          }
          if (target == A[i]) {
              return true;
          }
        }
        return false;
    }
};

int main(void) {
    vector<int> A = {3,4,4,5,7,0,1,2};
    int target = 4;
    Solution s;
    cout << s.search(A, target) << endl;

}
