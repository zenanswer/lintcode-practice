#include "lintcode_comm.h"

class Solution {
public:
    /*
     * @param numbers: Give an array
     * @param target: An integer
     * @return: Find all unique quadruplets in the array which gives the sum of zero
     */
    vector<vector<int> > fourSum(vector<int> numbers, int target) {
        vector<vector<int> > result;

        if (numbers.size() < 4) {
            return result;
        }

        sort(numbers.begin(), numbers.end());

        if (numbers.size() == 4) {
            int sum = 0;
            for (int i=0; i<4; i++) {
                sum += numbers[i];
                if (sum == target) {
                    result.push_back(numbers);
                    break;
                }
            }
            return result;
        }

        int i1 = 0;
        int i2 = 0;
        int i3 = 0;
        int i4 = 0;
        int sum1 = 0;
        int sum2 = 0;
        int sum3 = 0;

        for (; i1 < numbers.size()-3; i1++) {
            if (i1>0 && numbers[i1] == numbers[i1-1]) {
                continue;
            }
            i2 = i1+1;
            i3 = i1+2;
            i4 = i1+3;
            sum1 = numbers[i1];
            for(; i2<numbers.size()-2; i2++) {
                if (i2-i1>1 && numbers[i2] == numbers[i2-1]) {
                    continue;
                }
                i3 = i2+1;
                i4 = i2+2;
                sum2 = sum1 + numbers[i2];
                for(; i3<numbers.size()-1; i3++) {
                    if (i3-i2>1 && numbers[i3] == numbers[i3-1]) {
                        continue;
                    }
                    i4 = i3+1;
                    sum3 = sum2 + numbers[i3];
                    for(; i4<numbers.size(); i4++) {
                        if (i4-i3>1 && numbers[i4] == numbers[i4-1]) {
                            continue;
                        }
                        if (sum3 + numbers[i4] == target) {
                            vector<int> tuple;
                            tuple.push_back(numbers[i1]);
                            tuple.push_back(numbers[i2]);
                            tuple.push_back(numbers[i3]);
                            tuple.push_back(numbers[i4]);
                            result.push_back(tuple);
                            break;
                        }
                    }
                }
            }
        }
        return result;
    }
};

int main(void) {
    vector<int> inputarrayS = {1, 0, -1, 0, -2, 2};
    int target = 0;

    Solution s;
    vector<vector<int> > result = s.fourSum(inputarrayS, target);

    show2DVector(result);

}
