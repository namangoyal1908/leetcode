// Problem: Insert Interval
// Link: https://leetcode.com/problems/insert-interval/
// Difficulty: Medium
// Pattern: Merge Intervals
//
// Approach:
// Step 1 - Insert newInterval at correct position (by start value)
//          so that temp[] is still sorted by start
// Step 2 - Merge overlapping intervals in temp[] (standard merge)
//
// Insert Logic:
// - Traverse intervals, find first interval whose start >= newInterval[0]
// - Insert newInterval before it → temp is now sorted
// - If no such interval found → append at end
//
// Merge Logic:
// - Track current window [start, end]
// - If next interval overlaps (end >= s) → expand end = max(end, e)
// - Else → push current window, start fresh window
// - Push last window after loop
//
// Time: O(n) | Space: O(n)

class Solution {
public:
vector<vector<int>> insert(vector<vector<int>>& intervals,
vector<int>& newInterval) {
        vector<vector<int>> temp;
bool inserted = false;
for(int i=0;i<intervals.size();i++) {
if(!inserted && intervals[i][0] >= newInterval[0]) {
temp.push_back(newInterval);
                inserted = true;
            }
temp.push_back(intervals[i]);
        }
if(!inserted)
temp.push_back(newInterval);
        vector<vector<int>> res;
int start = temp[0][0];
int end = temp[0][1];
for(int i=1;i<temp.size();i++) {
int s = temp[i][0];
int e = temp[i][1];
if(end >= s) {
                end = max(end,e);
            }
else {
res.push_back({start,end});
                start = s;
                end = e;
            }
        }
res.push_back({start,end});
return res;
    }
};