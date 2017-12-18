#include "lintcode_comm.h"

class SVNRepo {
    public:
    static bool isBadVersion(int k) {
        m_count++;
        cout << "SVNRepo::isBadVersion count: " << m_count << endl;
        if (k>=m_badversion) {
            return true;
        }
        return false;
    }
    static int m_badversion;
    static int m_count;
};

class Solution {
public:
    /*
     * @param n: An integer
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        if (n==0) {
            return n;
        }
        if (n == 1/* && SVNRepo::isBadVersion(n)*/) {
            return n;
        }
        //using long type here, in case for "int(max)+int(max)"
        long start=0, end=n;
        for(; start!=(end-1); ){
            //cout << "start:" << start << ", end:" << end << endl;
            int mid = (start+end)/2;
            if (SVNRepo::isBadVersion(mid)) {
                end = mid;
            } else {
                start = mid;
            }
        }
        return end;
    }
};

int SVNRepo::m_count = 0;
int SVNRepo::m_badversion = 2147483647;

int main(void) {
    cout << "Bad version:" << SVNRepo::m_badversion << endl;
    cout << "Count:" << SVNRepo::m_count << endl;

    Solution s;
    cout << s.findFirstBadVersion(2147483647) << endl;
    return 0;
}
