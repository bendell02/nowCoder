/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        int nums = intervals.size();
        if (0 == nums) { return {}; }
 
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) { return a.start < b.start; });
 
        vector<Interval> result;
        result.push_back(intervals[0]);
        for (int i = 1; i < nums; ++i) {
            if (result.back().end < intervals[i].start) {
                result.push_back(intervals[i]);
            }
            else {
                result.back().end = std::max(result.back().end, intervals[i].end);
            }
        }
 
        return result;
    }
};
