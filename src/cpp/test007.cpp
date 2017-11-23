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
    /**
     * This method will be invoked first, you should design your own algorithm
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode * root) {
        if (root == NULL) {
          return "{}";
        }
        string serialized;
        queue<TreeNode*> node_queue;

        node_queue.push(root);
        serialized = to_string(root->val);

        while(node_queue.size() != 0) {
          TreeNode * node = node_queue.front();
          node_queue.pop();
          if (node->left != NULL) {
            node_queue.push(node->left);
            serialized += ",";
            serialized += to_string(node->left->val);
          } else {
            serialized += ",#";
          }
          if (node->right != NULL) {
            node_queue.push(node->right);
            serialized += ",";
            serialized += to_string(node->right->val);
          } else {
            serialized += ",#";
          }
        }
        serialized = serialized.substr(0, serialized.find_last_not_of(",#")+1);
        serialized = "{" + serialized + "}";
        return serialized;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
    TreeNode * deserialize(string &data) {
      int len = data.length();
      queue<TreeNode*> node_queue;
      int pos = 0;
      int num_start = 0;
      int node_cnt = 0;
      TreeNode * root = NULL;
      for(; pos != len; pos++) {
        if (data[pos] == '{') {
          continue;
        }
        if (data[pos] != ',' && num_start == 0) {
          num_start = pos;
          continue;
        }
        if (data[pos] == ',' or data[pos] == '}') {
          if (pos-num_start == 1 and data[num_start] == '#') {
            node_cnt++;
          } else {
            int val = stoi(data.substr(num_start, pos-num_start+1));
            TreeNode * node = new TreeNode(val);
            if (node_queue.size() > 0) {
              TreeNode * father = node_queue.front();
              if (node_cnt == 0) {
                father->left = node;
              } else if(node_cnt == 1) {
                father->right = node;
              }
              node_cnt++;
            } else {
              root = node;
            }
            node_queue.push(node);
          }
          if (node_cnt == 2) {
            node_queue.pop();
            node_cnt = 0;
          }
          num_start = 0;
          continue;
        }
      }
      return root;
    }
};

void deserialize_test() {
  string test_str="{3,9,20,#,#,15,7}";
  Solution s;
  TreeNode * tree = s.deserialize(test_str);
  string serialized = s.serialize(tree);
  cout << "deserialize + serialized:" << serialized << endl;
}

void serialize_test() {
  TreeNode * root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(88);

  Solution s;
  string serialized = s.serialize(root);
  cout << "serialized:" << serialized << endl;
}

int main(void) {
  serialize_test();
  deserialize_test();
  return 0;
}
