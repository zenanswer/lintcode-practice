
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getMin(int num1, int num2, int num3)
    {
        int min = num1 < num2 ? num1 : num2;
        min = min < num3 ? min : num3;
        return min;
    }
    /*
     * @param n: An integer
     * @return: the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        int count_ugly = 1;

        vector<int> ugly_list;
        ugly_list.push_back(1);

        int ugly_2_index = 0;
        int ugly_3_index = 0;
        int ugly_5_index = 0;

        int ugly_2 = 0;
        int ugly_3 = 0;
        int ugly_5 = 0;

        while (count_ugly != n) {
            if (ugly_2==0) {
                ugly_2 = ugly_list[ugly_2_index]*2;
            }
            if (ugly_3==0) {
                ugly_3 = ugly_list[ugly_3_index]*3;
            }
            if (ugly_5==0) {
                ugly_5 = ugly_list[ugly_5_index]*5;
            }
            int min = getMin(ugly_2, ugly_3, ugly_5);
            cout << "min:" << min << endl;
            ugly_list.push_back(min);
            count_ugly ++;
            if (min==ugly_2) {
                ugly_2 = 0;
                ugly_2_index ++;
            }
            if (min==ugly_3) {
                ugly_3 = 0;
                ugly_3_index ++;
            }
            if (min==ugly_5) {
                ugly_5 = 0;
                ugly_5_index ++;
            }
        }
        for (int i=0; i<ugly_list.size(); i++) {
          cout << ":" << ugly_list[i] << endl;
        }
        return ugly_list[n-1];
    }
};

int main(void) {
  Solution s;
  cout << "Result:" << s.nthUglyNumber(41) << endl;
}
