#include "lintcode_comm.h"

class QueryItem {
public:
    QueryItem(int index, int queryVal) {
        this->index = index;
        this->queryVal = queryVal;
        this->count = 0;
    }
    int queryVal;
    int index;
    int count;
};

bool sortbyIndex(const QueryItem &left, const QueryItem &right) {
    return left.index < right.index;
}

bool sortbyValue(const QueryItem &left, const QueryItem &right) {
    return left.queryVal < right.queryVal;
}

class Solution {
public:
    /*
     * @param A: An integer array
     * @param queries: The query list
     * @return: The number of element in the array that are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {

        sort(A.begin(), A.end());

        vector<QueryItem> itemlist;
        for (int q=0; q<queries.size(); q++) {
            itemlist.push_back(QueryItem(q, queries[q]));
        }
        sort(itemlist.begin(), itemlist.end(), sortbyValue);

        int a=0;
        for (int q=0; q<queries.size(); q++) {
            if (q>0) {
                itemlist[q].count += itemlist[q-1].count;
            }
            for (; a<A.size(); a++) {
                if (A[a] < itemlist[q].queryVal) {
                    itemlist[q].count ++;
                } else {
                    break;
                }
            }
        }

        vector<int> result;
        sort(itemlist.begin(), itemlist.end(), sortbyIndex);
        for (int q=0; q<queries.size(); q++) {
            result.push_back(itemlist[q].count);
        }

        return result;
    }
};

int main(void) {
    vector<int> A = {1,2,7,8,5};
    vector<int> queries = {1,8,5};
    Solution s;
    vector<int> result = s.countOfSmallerNumber(A, queries);
    showVector(result);

    return 0;
}
