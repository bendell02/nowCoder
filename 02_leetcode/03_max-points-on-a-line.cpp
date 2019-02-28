/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 
// ax + by + c = 0
class Line {
public:
    int a;
    int b;
    int c;
    int x;
    int y;
    int flag_zeros; // one point line
    Line(int x, int y, int z) : a(x), b(y), c(z) {}
    Line(Point &p1, Point &p2)
    {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = p2.x*p1.y - p1.x*p2.y;
        if (0==a && 0==b && 0==c) {
            flag_zeros = true;
            x = p1.x;
            y = p1.y;
        }
        else {
            flag_zeros = false;
        }
    }
 
    bool point_on_line(Point &pt)
    {
        if(flag_zeros) {
            if(x==pt.x && y==pt.y) {
                return true;
            }
            else {
                return false;
            }
        }
 
        if(0 == (a*pt.x+b*pt.y+c)) {
            return true;
        }
 
        return false;
    }
};
 
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int num_points = points.size();
 
        // boundary
        if (num_points <= 2) {
            return num_points;
        }
 
        int max_points_in_a_line=0, temp=0;
        for(int i=0; i<num_points; i++) {
            for(int j=i+1; j<num_points; j++) {
                Line line(points[i], points[j]);
                temp = 0;
                for(int k=0; k<num_points; k++) {
                    if(line.point_on_line(points[k])) {
                        temp++;
                    }
                }
 
                if (max_points_in_a_line < temp) {
                    max_points_in_a_line = temp;
                }
            }
        }
 
        return max_points_in_a_line;
    }
};