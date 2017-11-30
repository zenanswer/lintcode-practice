#include "lintcode_comm.h"

class PosPoint {
public:
    PosPoint(int pos, int value) {
        this->pos = pos;
        this->value = value;
    }
    int pos;
    int value;
};

class Solution {
public:
    /*
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    string minWindow(string &source , string &target) {
        //NOTE tgt_len should be greater than 1
        int tgt_len = target.size();
        int src_len = source.size();

        if (tgt_len == 0 || src_len == 0) {
          return "";
        }

        if (src_len < tgt_len) {
          return "";
        }

        vector<int> tgt_hash = vector<int>(256, 0);
        for (int i=0; i<tgt_len; i++) {
            tgt_hash[target[i]]++;
        }

        deque<PosPoint> start_point;

        int ret_start = -1;
        int ret_end = -1;

        int count = 0;

        vector<int> src_sub_hash = vector<int>(256, 0);
        for (int i=0; i<src_len; i++) {
            cout << "=== index:" << i << ", src:" << source[i] << endl;
            src_sub_hash[source[i]]++;
            //if found all target or not
            int cur_count = 0;
            for (int j=0; j<tgt_len; j++) {
                if (src_sub_hash[target[j]]>=tgt_hash[target[j]]) {
                    cur_count += src_sub_hash[target[j]]-tgt_hash[target[j]];
                }
                cout << "cur_count:" << cur_count << ", count:" << count << endl;
            }
            if (cur_count - count == 1) {
                cout << "Push start" << endl;
                start_point.push_back(PosPoint(i, source[i]));
                if (start_point.front().value == source[i]) {
                    int start_count = 0;
                    deque<PosPoint>::iterator it = start_point.begin();
                    for (; it != start_point.end(); it++) {
                        if ((*it).value == source[i]) {
                            start_count++;
                        }
                    }
                    if (start_count > tgt_hash[source[i]]) {
                        cout << "More pop" << endl;
                        src_sub_hash[source[i]]--;
                        start_point.pop_front();
                        count--;
                    }
                }
            }
            count = cur_count;
            if (count == tgt_len) {
                int cur_end = i;
                int cur_start = start_point.front().pos;
                cout << "cur_start:" << cur_start << ", cur_end:" << cur_end << endl;

                src_sub_hash[source[cur_start]]--;
                start_point.pop_front();
                count--;

                if (ret_start == -1 || ret_end == -1) {
                    ret_start = cur_start;
                    ret_end = cur_end;
                } else if (cur_end-cur_start<ret_end-ret_start) {
                    cout << "Update" << endl;
                    ret_start = cur_start;
                    ret_end = cur_end;
                }
            }
        }
        if (ret_start == -1 || ret_end == -1) {
            return "";
        }
        cout << "start:" << ret_start << ", end:" << ret_end << endl;
        return source.substr(ret_start, ret_end-ret_start+1);

    }
};

void test01() {
    string source("ADOBECODEBANC");
    string target("ABC");

    Solution s;
    cout << s.minWindow(source, target) << endl;
}

void test02() {
    string source("AAABECODEBANC");
    string target("ABBC");

    Solution s;
    cout << s.minWindow(source, target) << endl;
}

int main(void) {
    test01();
    test02();
    return 0;
}
