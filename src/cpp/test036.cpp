#include "lintcode_comm.h"
/**
 * Definition of singly-linked-list:
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param head: ListNode head is the head of the linked list
     * @param m: An integer
     * @param n: An integer
     * @return: The head of the reversed ListNode
     */
    ListNode * reverseBetween(ListNode * head, int m, int n) {
        if (head == NULL) {
            return NULL;
        }

        //TODO check m and n
        //1<=m<=n<=len(list)
        ListNode * orig_head = new ListNode(-1);
        orig_head->next = head;
        ListNode * pre_head = orig_head;
        ListNode * cur_head = orig_head->next;

        ListNode * m_head = NULL;
        ListNode * m_tail = NULL;
        int pos = 0;
        while (cur_head!=NULL) {
            pos++;
            if (pos == m) {
                m_head = cur_head;
                m_tail = cur_head;
                cur_head = cur_head->next;
            } else if (m < pos and pos < n) {
                ListNode * temp = cur_head->next;
                cur_head->next = m_head;
                m_head = cur_head;
                cur_head = temp;
            } else if (pos == n) {
                ListNode * temp = cur_head->next;
                pre_head->next = cur_head;
                cur_head->next = m_head;
                m_tail->next = temp;
                break;
            }
            else {
                pre_head = cur_head;
                cur_head = cur_head->next;
            }
        }

        return orig_head->next;
    }
};


int main(void) {
    ListNode * head = new ListNode(1);
    ListNode * p = head;
    for (int i=2; i<8; i++) {
      p->next = new ListNode(i);
      p = p->next;
    }
    showNodeList(head, "-->");
    Solution s;
    showNodeList(s.reverseBetween(head, 1, 3), "-->");
    return 0;
}
