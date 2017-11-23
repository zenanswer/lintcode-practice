#include <iostream>

#include <vector>

using namespace std;

class Solution {
public:
    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> &nums) {
        vector<vector<int> > result;
        if (nums.size() == 0) {
            vector<int> item;
            result.push_back(item);
            return result;
        }
        if (nums.size() == 1) {
            vector<int> item;
            item.push_back(nums[0]);
            result.push_back(item);
            return result;
        }
        int head = nums[0];
        vector<int> sub_nums(nums.begin()+1, nums.end());
        vector<vector<int> > sub_result = permute(sub_nums);
        for (int i=0; i<sub_result.size(); i++) {
            vector<int>::iterator it = sub_result[i].begin();
            for (; it!=sub_result[i].end(); it++) {
                vector<int> item;
                item.insert(item.end(), sub_result[i].begin(), it);
                item.push_back(head);
                item.insert(item.end(), it, sub_result[i].end());
                result.push_back(item);
            }
            vector<int> item2;
            item2.insert(item2.end(), sub_result[i].begin(), sub_result[i].end());
            item2.push_back(head);
            result.push_back(item2);
        }
        return result;
    }
};

void test01() {
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  Solution s;
  vector<vector<int> > result = s.permute(nums);
  for (int i=0; i<result.size(); i++) {
    cout << "-----" << endl;
    for (int j=0; j<result[i].size(); j++) {
      cout << " " << result[i][j];
    }
  }
}

void test02() {
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(4);
  Solution s;
  vector<vector<int> > result = s.permute(nums);
  for (int i=0; i<result.size(); i++) {
    cout << endl;
    for (int j=0; j<result[i].size(); j++) {
      cout << " " << result[i][j];
    }
  }
  cout << endl;
}

int main(void) {
  test01();
  test02();
  return 0;
}
