// Problem: Minimum Meeting Rooms
// Link: https://www.geeksforgeeks.org/problems/attend-all-meetings-ii/1
// Difficulty: Hard
// Pattern: Merge Intervals + Two Pointers
//
// Approach:
// - Sort start times and end times SEPARATELY (not as pairs)
// - Use two pointers i (tracks start times) and j (tracks end times)
// - If start[i] < end[j] → a new meeting begins before any room frees up
//   → need a NEW room → room++ → move i forward
// - Else (start[i] >= end[j]) → a meeting has ended before/when this one starts
//   → that room becomes free → reuse it → room-- → move j forward
// - Track max rooms needed at any point → res = max(room, res)
//
// Why sort start and end separately instead of as (start,end) pairs?
// - We don't care WHICH meeting ends, only WHEN a room frees up
// - Sorting them independently still gives correct chronological order
//   of "room needed" vs "room freed" events
//
// Why room-- when start[i] >= end[j]?
// - It means a previous meeting has ended, freeing up a room
// - That freed room can be reused for the new meeting → don't increase room
// - But we already accounted for that room in a previous room++ → so room--
//   balances it out before potentially incrementing again later
//
// Time: O(n log n) → sorting dominates
// Space: O(1) extra (excluding sort's internal usage)

class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        int n=start.size();
        
        int room=0,res=0,i=0,j=0;
        
        sort(start.begin(),start.end());// sort
         sort(end.begin(),end.end());
         
         // using 2 pointer 
         while(i<n&&j<n){
             if(start[i]<end[j]){//no room available
                 room++;// make room
                 res=max(room,res);
                 i++;
             }
             
             else{
                 room--;
                 j++;
                 
             }
             
             
         }return res;
    }
};