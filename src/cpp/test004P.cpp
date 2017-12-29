
#include "lintcode_comm.h"

class Solution {
public:
    vector<int> calculate(int start, int end) {
        vector<int> ugly_list;

        int index = start/7;
        int number = index*7;

        bool founddivisibleby5 = false;
        int count5 = 1;
        if (number < start) {
            number +=7;
        }
        while(number<=end) {
            //find the 1st number could be divisible by 5
            if (!founddivisibleby5) {
                int x = number%5;
                if (x == 0) {
                    cout << "Found 1st divisible by 5:" << number << endl;
                    founddivisibleby5 = true;
                    count5 = 1;
                } else {
                    ugly_list.push_back(number);
                }
                number += 7;
                continue;
            }
            //if this number could be divisible by 5, skipe
            if (count5==5) {
              cout << "Divisible by 5:" << number << endl;
              count5 = 1;
              number += 7;
              continue;
            }
            //save this number
            cout << "Save :" << number << endl;
            ugly_list.push_back(number);
            count5++;
            number += 7;
        }
        return ugly_list;
    }
};

int main(void) {
  Solution s;
  cout << "Result:" << endl;
  showVector(s.calculate(2000, 3200));
}
