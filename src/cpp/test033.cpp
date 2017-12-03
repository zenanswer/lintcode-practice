#include "lintcode_comm.h"

class Solution {
public:
     void solveNQueens(
          int n, int i, vector<int>& head, vector<vector<int> > & result) {
        if (head.size() == n) {
            result.push_back(head);
            return;
        }
        vector<int> candidates;
        for (int pos=1; pos<=n; pos++) {
            bool found = false;
            for (int i=0; i<head.size(); i++) {
                if (pos == head[i] or abs(pos-head[i]) == (head.size()-i)) {
                    found = true;
                }
            }
            if (!found) {
                candidates.push_back(pos);
            }
        }
        if (candidates.size() == 0) {
            return;
        }

        for (int i=0; i<candidates.size(); i++) {
            vector<int> sub_head = head;
            sub_head.push_back(candidates[i]);
            // if (sub_head.size() == n) {
            //     result.push_back(sub_head);
            // } else {
                solveNQueens(n, candidates[i], sub_head, result);
            //}
        }
    }
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > results;

        vector<vector<int> > solutions;
        for (int i=1; i<=n; i++) {
            vector<int> head;
            head.push_back(i);
            solveNQueens(n, i, head, solutions);
        }
        show2DVector(solutions);
        //TODO int pos to string
        for (int i=0; i<solutions.size(); i++) {
            vector<string> result;
            for (int j=0; j<solutions[i].size(); j++) {
                string result_str;
                for (int x=1; x<=n; x++) {
                  if (x == solutions[i][j]) {
                      result_str += "Q";
                  } else {
                      result_str += ".";
                  }
                }
                result.push_back(result_str);
            }
            results.push_back(result);
        }
        return results;
    }
};


int main(void) {
    Solution s;
    vector<vector<string> > solutions = s.solveNQueens(5);
    show2DVector(solutions);
    return 0;
}
