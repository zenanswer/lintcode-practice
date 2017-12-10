#include "lintcode_comm.h"

class Solution {
public:
    /*
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> &numbers, int target) {
      int result = std::numeric_limits<int>::max();
      if (numbers.size()<=3) {
          result = 0;
          for (int i=0; i<numbers.size(); i++) {
              result += numbers[i];
          }
          return result;
      }
      sort(numbers.begin(), numbers.end());
      int i1 = 0;
      int i2 = 0;
      int i3 = 0;
      int sum1 = 0;
      int sum2 = 0;
      int sum3 = 0;
      for (i1=0; i1<numbers.size(); i1++) {
          if (i1>0 && numbers[i1] == numbers[i1-1]) {
              continue;
          }
          sum1 = numbers[i1];
          for (i2=i1+1; i2<numbers.size(); i2++) {
              if (i2>i1+1 && numbers[i2] == numbers[i2-1]) {
                  continue;
              }
              sum2 = sum1 + numbers[i2];
              for (i3=i2+1; i3<numbers.size(); i3++) {
                  if (i3>i2+1 && numbers[i3] == numbers[i3-1]) {
                      continue;
                  }
                  sum3 = sum2 + numbers[i3];
                  if (abs(sum3-target) < abs(result-target)) {
                      result = sum3;
                  }
              }
          }
      }
      return result;
    }
};


int main(void) {
    vector<int> numbers = {-1, 2, 1, -4};
    int target = 1;
    Solution s;
    cout << s.threeSumClosest(numbers, target) << endl;
    return 0;
}
