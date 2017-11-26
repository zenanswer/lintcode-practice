#include "lintcode_comm.h"

class Solution {
public:
    /*
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        if(S.size() < 3) {
            return 0;
        }

        sort(S.begin(), S.end());

        int i = 0;
        int i1 = 0;
        int i2 = 0;
        int count = 0;

        for (; i < S.size()-2; i++) {
            i1 = i+1;
            i2 = i+2;
            //cout << "i :" << i << i1 << i2 <<endl;
            for(; i1<S.size()-1; i1++) {
                //cout << "i1:" << i << i1 << i2 <<endl;
                i2 = i1 + 1;
                for(; i2<S.size(); i2++) {
                    //cout << "i2:" << i << i1 << i2 <<endl;
                    if (S[i]+S[i1] > S[i2]) {
                        //cout << S[i] << S[i1] << S[i2] << endl;
                        count ++;
                    } else {
                        break;
                    }
                }
            }
        }
        return count;
    }
};

int main(void) {
    Solution s;
    vector<int> s1 = {3,4,6,7};
    cout << "result-1:" << s.triangleCount(s1) << endl;
    vector<int> s2 = {4,4,4,4};
    cout << "result-2:" << s.triangleCount(s2) << endl;
}
