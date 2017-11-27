#include "lintcode_comm.h"

class Solution {
public:
    /*
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int k) {
        int i = 0;
        int j = nums.size()-1;
        while (i<=j) {
            if (nums[i] < k) {
                i++;
            } else {
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                j--;
            }
        }
        return i;
    }
};

void test(vector<int> &nums, int k) {
    Solution s;
    cout << s.partitionArray(nums, k) << endl;
    showVector(nums);
}

int main(void) {
    vector<int> nums1 = {3,2,2,1};
    int k1 = 2;
    test(nums1, k1);
    vector<int> nums2 = {7,7,9,8,6,6,8,7,9,8,6,6};
    int k2 = 10;
    test(nums2, k2);
}
