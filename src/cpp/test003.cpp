#include <iostream>

using namespace std;

class Solution {
public:
    /*
     * @param : An integer
     * @param : An integer
     * @return: An integer denote the count of digit k in 1..n
     */
    int digitCounts(int k, int n) {
        int kcount = 0;
        for (int ni = 0; ni<=n; ni++) {
            int value = ni;
            do {
                if (value%10 == k) {
                    kcount++;
                }
                value /= 10;
            } while (value > 0);
        }
        return kcount;
    }
};

int main(void) {
  Solution s;
  cout << s.digitCounts(1, 12) << endl;
}
