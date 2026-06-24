// Problem: Intervals Intersection
// Link: https://leetcode.com/problems/interval-list-intersections/
// Difficulty: Medium
// Pattern: Merge Intervals + Two Pointers
//
// Approach (from your comments):
// - Use 2 pointers i and j to track position in firstList and secondList
// - At each step compare start1/end1 (current interval in firstList)
//   with start2/end2 (current interval in secondList)
// - If start1 <= start2 and end1 >= start2 → intervals overlap
//   → intersection = [max(start1,start2), min(end1,end2)]
// - If start2 < start1 and end2 >= start1 → intervals overlap (other direction)
//   → same intersection formula applies
// - After checking overlap, move pointer of whichever interval ENDS first
//   → if end1 <= end2 → i++ (firstList interval is done, move to next)
//   → else → j++ (secondList interval is done, move to next)
// - This works because once an interval's end is crossed, it can't
//   overlap with any future intervals (since lists are sorted)
//
// Why two separate if blocks instead of one?
// - Handles both cases of which interval starts first
// - start1 <= start2 → check if firstList's end reaches into secondList
// - start2 < start1  → check if secondList's end reaches into firstList
// - Both compute the same intersection formula but cover different orderings
//
// Time: O(n + m) → each pointer moves forward only, single pass through both lists
// Space: O(1) extra space (excluding result vector)

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        //result vector
        vector<vector<int>>res;
        //assign variables
        int i=0,j=0;
        int n=firstList.size();
        int m=secondList.size();
        while(i<n&&j<m){//using 2 pointer for keeping track on each array 
            int start1=firstList[i][0];// assign starting and endings 
            int start2=secondList[j][0];
            int   end1=firstList[i][1];
            int   end2=secondList[j][1];
            if(start1<=start2){
                if(end1>=start2){
                    int s=max(start1,start2);
                    int e=min(end1,end2);
                    res.push_back({s,e});
                }
            }
            if(start2<start1){
                if(end2>=start1){
                    int s=max(start1,start2);
                    int e=min(end1,end2);
                    res.push_back({s,e});
                }
            }
            if(end1<=end2){//handle i and  j according ending of list 
                    i++;
                }
            else{j++;}
        }return res;
    }
};