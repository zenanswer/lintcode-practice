#include <iostream>
using namespace std;

class MinStack {
public:

    class Item {
    public:
        Item(int val) {
            this->val = val;
            this->next = NULL;
        }
        int val;
        Item* next;
    };

    MinStack() {
        this->top = NULL;
        this->minp = NULL;
    }

    Item* top;
    Item* minp;

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        Item* item = new Item(number);
        item->next = this->top;
        this->top = item;
        if (this->minp == NULL || this->minp->val > this->top->val) {
            this->minp = this->top;
        }
    }

    /*
     * @return: An integer
     */
    int pop() {
        if (this->top == NULL) {
            return 0;
        }
        if (this->top == this->minp) {
            Item* item = this->top->next;
            this->minp = item;
            while(item != NULL) {
                if (item->val < this->minp->val) {
                    this->minp = item;
                }
                item = item->next;
            }
        }
        Item* item = this->top;
        this->top = this->top->next;
        int ret = item->val;
        delete item;
        return ret;
    }

    /*
     * @return: An integer
     */
    int min() {
        if (this->minp != NULL) {
          return this->minp->val;
        }
        return 0;
    }
};

int main(void) {
  MinStack s;
  s.push(1);
  cout << s.pop() << endl;
  s.push(2);
  s.push(3);
  cout << s.min() << endl;
  s.push(1);
  cout << s.min() << endl;


  return 0;
}
