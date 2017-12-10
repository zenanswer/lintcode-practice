#include "lintcode_comm.h"

// https://www.cnblogs.com/litao-tech/p/4163576.html
// 做了两次“最大子数组”，第一次从头到尾，第二次从尾到头。（前两个for循环）
// 最后看当i（最后一次循环中的i）在哪个位置的时候，两个数组的和最大。

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> &nums) {
        int sum_tmp = 0;

        vector<int> sum_RtL(nums.size());
        sum_tmp = nums[0];
        sum_RtL[0] = sum_tmp;
        for (int i=1; i<nums.size()-1; i++) {
            if (sum_tmp<=0) {
                sum_tmp = nums[i];
            } else {
                sum_tmp += nums[i];
            }
            if (sum_tmp > sum_RtL[i-1]) {
                sum_RtL[i] = sum_tmp;
            } else {
                sum_RtL[i] = sum_RtL[i-1];
            }
            //cout << sum_RtL[i] << endl;
        }

        vector<int> sum_LtR(nums.size());
        sum_tmp = nums[nums.size()-1];
        sum_LtR[nums.size()-1] = sum_tmp;
        for (int i=nums.size()-2; i>0; i--) {
            if (sum_tmp<=0) {
                sum_tmp = nums[i];
            } else {
                sum_tmp += nums[i];
            }
            if (sum_tmp > sum_LtR[i+1]) {
                sum_LtR[i] = sum_tmp;
            } else {
                sum_LtR[i] = sum_LtR[i+1];
            }
            //cout << sum_LtR[i] << endl;
        }

        sum_tmp = sum_RtL[0] + sum_LtR[1];
        for (int i=1; i<nums.size()-1; i++) {
            if (sum_tmp < (sum_RtL[i] + sum_LtR[i+1])) {
                sum_tmp = sum_RtL[i] + sum_LtR[i+1];
            }
        }

        return sum_tmp;
    }
};


int main(void) {
    vector<int> nums ={1, 3, -1, 2, -1, 2};
    Solution s;
    cout << s.maxTwoSubArrays(nums) << endl;
    return 0;
}
