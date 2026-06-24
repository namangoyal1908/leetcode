// Problem: Merge Intervals
// Link: https://leetcode.com/problems/merge-intervals/
// Difficulty: Medium
// Pattern: Merge Intervals
//
// Approach:
// - Sort intervals by start value
// - Track current window [start, end]
// - If next interval overlaps (end >= s) → expand end = max(end, e)
// - Else → push current window, start fresh window
// - Push last window after loop
//
// Time: O(n log n) | Space: O(n)

class Solution {
public:
vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> res;
int n=a.size();
sort(a.begin(),a.end());
int start=a[0][0];
int end=a[0][1];
int i;
for(i=1;i<n;i++)
        {
int s=a[i][0];
int e=a[i][1];
if(end>=s) //overlap
            {
                end=max(end,e);
continue;
            }
            // push
res.push_back({start,end});
            start=s;
            end=e;
        }
res.push_back({start,end});
return res;
    }};