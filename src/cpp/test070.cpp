#include "lintcode_comm.h"

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
public:
    vector<vector<int> > subLevelOrderBottom(queue<TreeNode *> &nodes) {
        queue<TreeNode *> sub_nodes;
        vector<int> nodes_val;
        while(nodes.size()>0) {
            TreeNode * node = nodes.front();
            if (node->left != NULL) {
                sub_nodes.push(node->left);
            }
            if (node->right != NULL) {
                sub_nodes.push(node->right);
            }
            nodes_val.push_back(node->val);
            nodes.pop();
        }
        vector<vector<int> > result;
        if (sub_nodes.size()>0) {
            result = subLevelOrderBottom(sub_nodes);
        }
        result.push_back(nodes_val);
        return result;
    }

    /*
     * @param root: A tree
     * @return: buttom-up level order a list of lists of integer
     */
    vector<vector<int> > levelOrderBottom(TreeNode * root) {
        if (root == NULL) {
            vector<vector<int> > result;
            return result;
        }
        queue<TreeNode *> sub_nodes;
        if (root->left != NULL) {
            sub_nodes.push(root->left);
        }
        if (root->right != NULL) {
            sub_nodes.push(root->right);
        }
        vector<vector<int> > result = subLevelOrderBottom(sub_nodes);
        vector<int> root_val = {root->val};
        result.push_back(root_val);
        return result;
    }
};

int main(void) {
    TreeNode root(3);
    TreeNode node9(9);
    TreeNode node20(20);
    TreeNode node15(15);
    TreeNode node7(7);

    root.left = &node9;
    root.right = &node20;
    node20.left = &node15;
    node20.right = &node7;

    Solution s;
    vector<vector<int> > result = s.levelOrderBottom(&root);
    show2DVector(result);
    return 0;
}
