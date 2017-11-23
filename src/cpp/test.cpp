#include <iostream>

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
//Definition of Doubly-ListNode
class DoublyListNode {
public:
    int val;
    DoublyListNode *next, *prev;
    DoublyListNode(int val) {
        this->val = val;
           this->prev = this->next = NULL;
    }
};

void showList(DoublyListNode * list) {
  while (list->prev != NULL) {
    list = list->prev;
  }
  while (list != NULL) {
    cout << list->val << endl;
    list = list->next;
  }
}

class Solution {
public:
    /*
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode * bstToDoublyList(TreeNode * root) {

        if (root == NULL) {
            return NULL;
        }

        DoublyListNode * head = new DoublyListNode(root->val);
        DoublyListNode * tail = head;
        cout << "Do:" << endl;
        showList(head);

        if (root->left != NULL) {
            DoublyListNode * leftHead = bstToDoublyList(root->left);

            cout << "leftHead:" << endl;
            showList(leftHead);

            DoublyListNode * leftTail = leftHead;
            while (leftTail->next != NULL) {
                leftTail = leftTail->next;
            }

            leftTail->next = head;
            head->prev = leftTail;

            tail = head;
            head = leftHead;

            cout << "Done leftHead:" << endl;
            showList(head);
        }

        if (root->right != NULL) {
            DoublyListNode * rightHead = bstToDoublyList(root->right);

            cout << "rightHead:" << endl;
            showList(rightHead);

            if (rightHead != NULL) {
                tail->next = rightHead;
                rightHead->prev = tail;
            }
        }
        cout << "Done:" << endl;
        showList(head);
        return head;
    }
};

void calculate(TreeNode* root) {
  Solution s;
  DoublyListNode * list = s.bstToDoublyList(root);

  cout << "End:" << endl;
  showList(list);
}

void dotest01(void) {
  //{4,2,5,1,3}
  TreeNode* node4 = new TreeNode(4);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node5 = new TreeNode(5);
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node3 = new TreeNode(3);
  node4->left = node2;
  node4->right = node5;
  node2->left = node1;
  node2->right = node3;

  calculate(node4);
}

void dotest02(void) {
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(2);

  node1->left = node2;

  calculate(node1);
}

int main(void) {
  dotest01();
  dotest02();

  return 0;
}
