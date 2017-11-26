#include "lintcode_comm.h"

class Solution {
public:
    void subset(vector<int> &father, vector<int> &nums, vector<vector<int> >& result) {
        vector<int>::iterator it = nums.begin();
        for (; it!=nums.end(); it++) {
            if (it != nums.begin() && *(it-1) == *(it)) {
                continue;
            }
            vector<int> father_copy = father;
            father_copy.push_back(*it);
            result.push_back(father_copy);
            vector<int> sub_nums;
            //sub_nums.insert(sub_nums.end(), nums.begin(), it);
            sub_nums.insert(sub_nums.end(), it+1, nums.end());
            subset(father_copy, sub_nums, result);
        }
    }
    /*
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int> > result;
        vector<int> empty;
        result.push_back(empty);
        sort(nums.begin(), nums.end());
        subset(empty, nums, result);
        return result;
    }
};

int main(void) {
  Solution s;
  vector<int> nums = {1,2,2};
  vector<vector<int>> result = s.subsetsWithDup(nums);
  show2DVector(result);
  return 0;
}
