#include <iostream>

#include <vector>

using namespace std;

class Solution {
public:
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
      vector<int>::iterator it = nums.begin();
      for (; it!=nums.end(); it++) {
          if (it!= nums.begin() && *it==*(it-1)) {
              continue;
          }
          vector<int> sub_nums;
          sub_nums.insert(sub_nums.end(), nums.begin(), it);
          sub_nums.insert(sub_nums.end(), it+1, nums.end());
          vector<vector<int> > sub_result = permute(sub_nums);
          for (int j=0; j<sub_result.size(); j++) {
              vector<int> new_item;
              new_item.push_back(*it);
              new_item.insert(
                  new_item.end(),
                  sub_result[j].begin(), sub_result[j].end());
              result.push_back(new_item);
          }
      }
      return result;
    }
    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        return permute(nums);
    }
};

void test01() {
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(2);
  Solution s;
  vector<vector<int> > result = s.permuteUnique(nums);
  for (int i=0; i<result.size(); i++) {
    cout << endl;
    for (int j=0; j<result[i].size(); j++) {
      cout << " " << result[i][j];
    }
  }
  cout << endl;
}

void test02() {
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(2);
  Solution s;
  vector<vector<int> > result = s.permuteUnique(nums);
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
  cout << "=====" << endl;
  test02();
  return 0;
}
