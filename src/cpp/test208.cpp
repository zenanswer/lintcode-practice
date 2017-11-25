#include "lintcode_comm.h"

class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        int len = strlen(pData);
        this->m_pData = new char[len];
        strncpy(this->m_pData, pData, len);
    }
    ~Solution() {
        if (this->m_pData != NULL) {
            delete this->m_pData;
            this->m_pData = NULL;
        }
    }
    // Implement an assignment operator
    Solution &operator=(const Solution &object) {
        if (this->m_pData == object.m_pData) {
            return *this;
        }
        if (this->m_pData != NULL) {
            delete this->m_pData;
            this->m_pData = NULL;
        }
        if (object.m_pData == NULL) {
            this->m_pData = NULL;
            return *this;
        }
        int len = strlen(object.m_pData);
        this->m_pData = new char[len];
        strncpy(this->m_pData, object.m_pData, len);
        return *this;
    }
};

bool operator==(const Solution &left, const Solution &right) {
  if (left.m_pData == NULL) {
    if (right.m_pData == NULL) {
      return true;
    }
    return false;
  }
  if (right.m_pData == NULL) {
    return false;
  }
  if (strlen(left.m_pData) != strlen(right.m_pData)) {
    return false;
  }
  int ret = strncmp(left.m_pData, right.m_pData, strlen(left.m_pData));
  return ret==0?true:false;
}

int main(void) {
  char* A = new char[2]{'A', '\0'};
  char* B = new char[2]{'B', '\0'};
  char* C = new char[2]{'C', '\0'};
  Solution sA(A);
  Solution sB(B);
  sA = sB;
  cout << ((sA==sB)?'T':'F') << endl;

  Solution sA2(A);
  Solution sB2(B);
  Solution sC2(C);
  sA2 = sB2 = sC2;
  cout << ((sA2==sB2)?'T':'F') << endl;
  cout << ((sB2==sC2)?'T':'F') << endl;

  return 0;
}
