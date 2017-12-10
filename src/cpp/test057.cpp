#include "lintcode_comm.h"

class Solution {
public:
    /*
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &numbers) {
        vector<vector<int> > result;
        if (numbers.size()<3) {
            return result;
        }
        sort(numbers.begin(), numbers.end());
        if (numbers.size()==3) {
            result.push_back(numbers);
            return result;
        }
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
                    if (sum3 == 0) {
                        vector<int> item = {numbers[i1], numbers[i2], numbers[i3]};
                        // if (result.size()>0 && result[result.size()-1] == item) {
                        //     continue;
                        // }
                        result.push_back(item);
                    }
                }
            }
        }
        return result;
    }
};

int main(void) {
    vector<int> numbers = {-1, 0, 1, 2, -1, -4};
    Solution s;
    vector<vector<int> > result = s.threeSum(numbers);
    show2DVector(result);
    return 0;
}
