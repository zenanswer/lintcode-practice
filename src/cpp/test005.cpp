#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
        if (n <= 0) {
            return 0;
        }
        if (n>nums.size()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        return nums[nums.size()-n];
    }
};

int main(void) {
  vector<int> nums;
  //[9,3,2,4,8]
  int v1[10] = {9,3,2,4,8};
  for(int i=0; i<5; i++ ) {
    nums.push_back(v1[i]);
  }

  Solution s;
  cout << s.kthLargestElement(3, nums) << endl;
}
