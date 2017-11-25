#include "lintcode_comm.h"

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
        //cout << "Do:" << endl;
        //showList(head);

        if (root->left != NULL) {
            DoublyListNode * leftHead = bstToDoublyList(root->left);

            //cout << "leftHead:" << endl;
            //showList(leftHead);

            DoublyListNode * leftTail = leftHead;
            while (leftTail->next != NULL) {
                leftTail = leftTail->next;
            }

            leftTail->next = head;
            head->prev = leftTail;

            tail = head;
            head = leftHead;

            //cout << "Done leftHead:" << endl;
            //showList(head);
        }

        if (root->right != NULL) {
            DoublyListNode * rightHead = bstToDoublyList(root->right);

            //cout << "rightHead:" << endl;
            //showList(rightHead);

            if (rightHead != NULL) {
                tail->next = rightHead;
                rightHead->prev = tail;
            }
        }
        //cout << "Done:" << endl;
        //showList(head);
        return head;
    }
};

int main(void) {
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    n4.left=&n2;
    n4.right=&n5;
    n2.left=&n1;
    n2.right=&n3;

    Solution s;
    DoublyListNode * bstToDoublyList = s.bstToDoublyList(&n4);

    showDoublyList(bstToDoublyList);

}
