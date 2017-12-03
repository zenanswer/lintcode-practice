#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>

using namespace std;

//lintcode header

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

//Definition for a point.
struct Point {
   int x;
   int y;
   Point() : x(0), y(0) {}
   Point(int a, int b) : x(a), y(b) {}
};

// helper func for print

ostream& operator << (ostream& output,Point& c) //定义运算符“<<”重载函数
{
   output<<"["<<c.x<<":"<<c.y<<"]";
   return output;
}

void showDoublyList(DoublyListNode * bstToDoublyList) {
    cout << "DoublyList:" << endl;
    DoublyListNode* temp = bstToDoublyList;
    while(temp != NULL) {
      cout << temp->val;
      if (temp->next!=NULL) {
        cout << " <-> ";
      }
      temp = temp->next;
    }
    cout << endl;
}

// void showVector(vector<int> input) {
//   cout << "vector:" << endl;
//   for(int i=0; i<input.size(); i++) {
//     cout << input[i];
//     if (i!=input.size()-1) {
//       cout << ",";
//     }
//   }
//   cout << endl;
//}

template<typename T>
void showVector(vector<T> input) {
  cout << "vector:" << endl;
  for(int i=0; i<input.size(); i++) {
    cout << input[i];
    if (i!=input.size()-1) {
      cout << ",";
    }
  }
  cout << endl;
}

template<typename T>
void show2DVector(vector<vector<T> > input) {
  cout << "vector:" << endl;
  for(int i=0; i<input.size(); i++) {
    for(int j=0; j<input[i].size(); j++) {
      cout << input[i][j];
      if (j!=input[i].size()-1) {
        cout << ",";
      }
    }
    if (i!=input.size()-1) {
      cout << endl;
    }
  }
  cout << endl;
}
