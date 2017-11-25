#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void permute(vector<int> &father, vector<int> &nums, vector<vector<int> >& result) {
      vector<int>::iterator it = nums.begin();
      for (; it!=nums.end(); it++) {
        vector<int> father_copy = father;
        father_copy.push_back(*it);
        result.push_back(father_copy);
        vector<int> sub_nums;
        //sub_nums.insert(sub_nums.end(), nums.begin(), it);
        sub_nums.insert(sub_nums.end(), it+1, nums.end());
        permute(father_copy, sub_nums, result);
      }
    }
    /*
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int> > subsets(vector<int> &nums) {
      vector<vector<int> > result;
      vector<int> empty;
      result.push_back(empty);
      permute(empty, nums, result);
      return result;
    }
};

int main(void) {
  vector<int> nums;
  //[9,3,2,4,8]
  int v1[10] = {1,2,3};
  for(int i=0; i<3; i++ ) {
    nums.push_back(v1[i]);
  }

  Solution s;
  vector<vector<int> > result = s.subsets(nums);

  cout << endl;
  for(int i=0; i<result.size(); i++) {
    for(int j=0; j<result[i].size(); j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
}
