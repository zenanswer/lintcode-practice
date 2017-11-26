#include "lintcode_comm.h"

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class PointW {
public:
    PointW(int x, int y, Point& origin) {
        this->x = x;
        this->y = y;
        this->count = 1;
        this->dis = sqrt(pow(origin.x-x, 2) + pow(origin.y-y, 2));
    };
    int x;
    int y;
    float dis;
    mutable int count;
    bool operator<(const PointW & right) const{
        if(dis<right.dis) {
            return true;
        } else if (dis==right.dis) {
            if(x<right.x) {
                return true;
            } else if (x==right.x) {
                if(y<right.y) {
                    return true;
                } else if (y==right.y) {
                    count ++;
                    return false;
                }
            }
        }
        return false;
    };
};

class Solution {
public:
    /*
     * @param points: a list of points
     * @param origin: a point
     * @param k: An integer
     * @return: the k closest points
     */
    vector<Point> kClosest(vector<Point> points, Point origin, int k) {
        set<PointW> cache;
        for(int i=0; i<points.size(); i++) {
            PointW temp(points[i].x, points[i].y, origin);
            cache.insert(temp);
        }
        vector<Point> result;
        std::set<PointW>::iterator it = cache.begin();
        for (; it != cache.end(); ++it) {
            for (int i=0; i<(*it).count; i++) {
                result.push_back(Point((*it).x, (*it).y));
                k--;
                if(k==0) return result;
            }
        }
        return result;
    }
};

int main(void) {
    vector<Point> points = \
      {Point(4,6), Point(4,7),Point(4,4),Point(2,5),Point(1,1)};
    Point origin(0, 0);
    int k=3;
    Solution s;
    vector<Point> result = s.kClosest(points, origin, k);
    showVector(result);

    return 0;
}
