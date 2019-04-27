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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int nums = intervals.size();
        vector<Interval> result;
 
        // boundary
        if (0 == nums) {
            result.push_back(newInterval);
            return result;
        }
 
        // find the index of two value
        int firstValue = newInterval.start;
        int secondValue = newInterval.end;
        int firstIndex = nums, secondIndex = nums;
        int newFirstValue = firstValue, newSecondValue = secondValue;
 
        // find firstIndex
        for (int i = 0; i < nums; ++i) {
            if (firstValue < intervals[i].start) {
                firstIndex = i;
                newFirstValue = firstValue;
                break;
            }
            else if (firstValue <= intervals[i].end) {
                firstIndex = (i = 0 ? -1 : i);
                newFirstValue = intervals[i].start;
                break;
            }
        }
        // find secondIndex
        for (int i = 0; i < nums; ++i) {
            if (secondValue < intervals[i].start) {
                secondIndex = i - 1;
                newSecondValue = secondValue;
                break;
            }
            else if (secondValue <= intervals[i].end) {
                secondIndex = i;
                newSecondValue = intervals[i].end;
                break;
            }
        }
 
        // merge
        Interval temp;
        temp.start = newFirstValue;
        temp.end = newSecondValue;
        if (firstIndex < 0) {
            result.push_back(temp);
        }
 
        for (int i = 0; i < firstIndex; ++i) {
            result.push_back(intervals[i]);
        }
        if (firstIndex >= 0 && firstIndex < nums) {
            result.push_back(temp);
        }
        for (int i = secondIndex + 1; i < nums; i++) {
            result.push_back(intervals[i]);
        }
 
        if (firstIndex >= nums) {
            result.push_back(temp);
        }
 
        return result;
    }
};
