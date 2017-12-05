#include "lintcode_comm.h"

class MyQueue {
public:
    MyQueue() {
    }
    stack<int> m_1st_stack;
    stack<int> m_2nd_stack;

    /*
     * @param element: An integer
     * @return: nothing
     */
    void push(int element) {
        m_1st_stack.push(element);
    }

    /*
     * @return: An integer
     */
    int pop() {
        int value = top();
        m_2nd_stack.pop();
        return value;
    }

    /*
     * @return: An integer
     */
    int top() {
      if (m_2nd_stack.size() == 0) {
          while(m_1st_stack.size()>0) {
              m_2nd_stack.push(m_1st_stack.top());
              m_1st_stack.pop();
          }
      }
      return m_2nd_stack.top();
    }
};

int main(void) {
    MyQueue myqueue;
    myqueue.push(1);
    cout << myqueue.pop() << endl;
    myqueue.push(2);
    myqueue.push(3);
    cout << myqueue.top() << endl;
    cout << myqueue.pop() << endl;
    return 0;
}
