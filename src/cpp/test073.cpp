#include "lintcode_comm.h"

// http://blog.csdn.net/sgbfblog/article/details/7783935
/*
      ___7___
      /     \
    10      2
  /   \    /
 4    3   8
      \  /
      1 11
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) {
            return NULL;
        }
        int i = 0;
        TreeNode * root = buildTree(preorder, inorder, i);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int& preorder_i) {
      TreeNode * root = new TreeNode(preorder[preorder_i]);
      if (preorder.size()==preorder_i+1) {
          return root;
      }
      std::vector<int>::iterator it, sub_it;
      it = find(inorder.begin(), inorder.end(), preorder[preorder_i]);
      // if (it!=inorder.end()) {
      //     cout << "found:" << preorder[preorder_i] << endl;
      // }
      // exception here if no found
      sub_it = find(inorder.begin(), it, preorder[preorder_i+1]);
      if (sub_it != it) {
          vector<int> sub_inorder(inorder.begin(), it);
          preorder_i++;
          root->left = buildTree(preorder, sub_inorder, preorder_i);
      }
      if (preorder.size()==preorder_i+1) {
          return root;
      }
      sub_it = find(it+1, inorder.end(), preorder[preorder_i+1]);
      if (sub_it != inorder.end()) {
          vector<int> sub_inorder(it+1, inorder.end());
          preorder_i++;
          root->right = buildTree(preorder, sub_inorder, preorder_i);
      }
      return root;
    }
};

void DLR_LDR_test() {
    TreeNode node7(7);
    TreeNode node10(10);
    TreeNode node2(2);
    TreeNode node4(4);
    TreeNode node3(3);
    TreeNode node8(8);
    TreeNode node1(1);
    TreeNode node11(11);

    node7.left = &node10;
    node7.right = &node2;
    node10.left = &node4;
    node10.right = &node3;
    node3.right = &node1;
    node2.left = &node8;
    node8.left = &node11;

    vector<int> result_DLR;
    DLR(&node7, result_DLR);
    showVector(result_DLR, "DLR test");

    vector<int> result_LDR;
    LDR(&node7, result_LDR);
    showVector(result_LDR, "LDR test");
}

int main(void) {
    DLR_LDR_test();

    vector<int> preorder = {7,10,4,3,1,2,8,11};
    vector<int> inorder = {4,10,3,1,7,11,8,2};

    Solution s;
    TreeNode * result = s.buildTree(preorder, inorder);

    vector<int> result_DLR;
    DLR(result, result_DLR);

    showVector(preorder, "Orig DLR");
    showVector(result_DLR, "Result DLR");
    return 0;
}
