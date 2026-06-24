// Problem: Overlapping Intervals
// Link: https://www.geeksforgeeks.org/check-if-any-two-intervals-overlap-among-a-given-set-of-intervals/
// Difficulty: Medium
// Pattern: Merge Intervals
//
// Approach:
// - Sort intervals by start time first → makes comparison easier
// - Track end1 = end of the "current" interval being compared
// - For every next interval, check if its start (start2) falls
//   before end1 → if yes, intervals overlap → return true
// - Otherwise update end1 to max(end1, end2) to keep widest range so far
//   → this matters because next interval might overlap with the
//     EXTENDED range, not just the immediate previous interval
//
// Why sort first?
// - Without sorting, intervals could be in any order
// - Sorting by start time guarantees we only need to compare
//   each interval with the running max end → single pass works
//
// Why end1 = max(end1, end2) instead of just end1 = end2?
// - Previous interval might have a larger end than current one
// - Need to carry forward the largest end seen so far to correctly
//   detect overlap with future intervals
//
// Time: O(n log n) → sorting dominates
// Space: O(1) extra space (excluding sort's internal usage)

class Solution {
public:
    bool isIntersect(vector<vector<int>> intervals) {
        sort(intervals.begin(), intervals.end());
        int end1 = intervals[0][1];
        int n = intervals.size();
        for(int i = 1; i < n; i++) {
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];
            if(end1 >= start2) {
                return true;
            }
            end1 = max(end1, end2);
        }
        return false;
    }
};