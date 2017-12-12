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
    vector<vector<int> > subLevelOrderBottom(deque<TreeNode *> &nodes, int x) {
        deque<TreeNode *>::iterator it = nodes.begin();
        cout << "x:" << x << ",in: ";
        for (; it!=nodes.end(); it++) {
            cout << (*it)->val << ',';
        }
        cout << endl;
        deque<TreeNode *> sub_nodes;
        vector<int> nodes_val;
        while(nodes.size()>0) {
            if (x%2==0) {
                TreeNode * node = nodes.front();
                if (node->right != NULL) {
                    cout << "push_back:" << node->right->val << endl;
                    sub_nodes.push_back(node->right);
                }
                if (node->left != NULL) {
                    cout << "push_back:" << node->left->val << endl;
                    sub_nodes.push_back(node->left);
                }
                nodes_val.push_back(node->val);
                nodes.pop_front();
            } else {
                TreeNode * node = nodes.back();
                if (node->left != NULL) {
                    cout << "push_front:" << node->left->val << endl;
                    sub_nodes.push_front(node->left);
                }
                if (node->right != NULL) {
                    cout << "push_front:" << node->right->val << endl;
                    sub_nodes.push_front(node->right);
                }
                nodes_val.push_back(node->val);
                nodes.pop_back();
            }
        }
        vector<vector<int> > result;
        result.push_back(nodes_val);
        x++;
        if (sub_nodes.size()>0) {
            vector<vector<int> > sub_result = subLevelOrderBottom(sub_nodes, x);
            result.insert(result.end(), sub_result.begin(), sub_result.end());
        }

        return result;
    }

    /*
     * @param root: A tree
     * @return: buttom-up level order a list of lists of integer
     */
    vector<vector<int> > zigzagLevelOrder(TreeNode * root) {
        if (root == NULL) {
            vector<vector<int> > result;
            return result;
        }
        deque<TreeNode *> sub_nodes;

        int x = 1;
        if (root->right != NULL) {
            sub_nodes.push_back(root->right);
        }
        if (root->left != NULL) {
            sub_nodes.push_back(root->left);
        }

        vector<vector<int> > result;
        vector<int> root_val = {root->val};
        result.push_back(root_val);
        x++;
        vector<vector<int> > sub_result = subLevelOrderBottom(sub_nodes, x);
        result.insert(result.end(), sub_result.begin(), sub_result.end());
        return result;
        // [[1],[3,2],[4,5],[7,6],[8]]
    }
};

void test01(void) {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);
    TreeNode node7(7);
    TreeNode node8(8);
    TreeNode node9(9);
    TreeNode node10(10);
    TreeNode node11(11);
    TreeNode node12(12);
    TreeNode node13(13);

    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;
    node4.left = &node8;
    node4.right = &node9;
    node5.left = &node10;
    node5.right = &node11;

    Solution s;
    vector<vector<int> > result = s.zigzagLevelOrder(&node1);
    show2DVector(result);

}

int main(void) {
    test01();
    // TreeNode root(1);
    // TreeNode node2(2);
    // TreeNode node3(3);
    // TreeNode node4(4);
    // TreeNode node5(5);
    // TreeNode node6(6);
    // TreeNode node7(7);
    // TreeNode node8(8);
    //
    // root.left = &node2;
    // root.right = &node3;
    // node2.left = &node4;
    // node3.right = &node5;
    // node5.left = &node6;
    // node5.right = &node7;
    // node7.right = &node8;
    //
    // Solution s;
    // vector<vector<int> > result = s.zigzagLevelOrder(&root);
    // show2DVector(result);
    return 0;
}
