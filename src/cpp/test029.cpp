#include "lintcode_comm.h"


class Solution {
public:
    /*
     * @param s1: A string
     * @param s2: A string
     * @param s3: A string
     * @return: Determine whether s3 is formed by interleaving of s1 and s2
     */
    bool isInterleave(string &s1, string &s2, string &s3) {
        if (s1.size() == 0) {
            if (s2 == s3) {
              return true;
            }
            return false;
        } else if (s2.size() == 0) {
            if (s1 == s3) {
              return true;
            }
            return false;
        } else if (s3.size() == 0) {
            return false;
        }
        bool ret_1 = false;
        bool ret_2 = false;
        string s3_sub(s3.begin()+1, s3.end());
        if (s1[0] == s3[0]) {
            string s1_sub(s1.begin()+1, s1.end());
            ret_1 = isInterleave(s1_sub, s2, s3_sub);
        }
        if (s2[0] == s3[0]) {
            string s2_sub(s2.begin()+1, s2.end());
            ret_2 = isInterleave(s1, s2_sub, s3_sub);
        }
        return (ret_1||ret_2);
    }
};


int main(void) {
  string s1("aabcc");
  string s2("dbbca");
  string s3_1("aadbbcbcac");
  string s3_2("aadbbbaccc");

  Solution s;
  cout << s.isInterleave(s1, s2, s3_1) << endl;
  cout << s.isInterleave(s1, s2, s3_2) << endl;
}
