#include <iostream>
#include <queue>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

//Definition of TreeNode:
class TreeNode {
 public:
     int val;
     TreeNode *left, *right;
     TreeNode(int val) {
         this->val = val;
         this->left = this->right = NULL;
     }
 };

class Solution {
public:
    void searchRange(TreeNode * root, int k1, int k2, vector<int>& result) {
      if (root->val < k1 || root->val > k2) {
        return;
      }
      if (root->left != NULL) {
        searchRange(root->left, k1, k2, result);
      }
      result.push_back(root->val);
      if (root->right != NULL) {
        searchRange(root->right, k1, k2, result);
      }
    }
    /*
     * @param root: param root: The root of the binary search tree
     * @param k1: An integer
     * @param k2: An integer
     * @return: return: Return all keys that k1<=key<=k2 in ascending order
     */
    vector<int> searchRange(TreeNode * root, int k1, int k2) {
      vector<int> result;
      searchRange(root, k1, k2, result);
      return result;
    }
};

int main(void) {


  return 0;
}
