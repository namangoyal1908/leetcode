// Problem: Upper Bound / Ceiling
// Link: https://www.geeksforgeeks.org/problems/ceil-in-a-sorted-array/1
// Difficulty: Easy
// Pattern: Binary Search
//
// How is it different from Basic Binary Search?
// - Basic search: stop as soon as exact match found, return immediately
// - Ceiling search: even after finding arr[guess] >= x, DON'T stop —
//   keep searching LEFT for a possibly SMALLER valid answer
//
// Approach:
// - Ceiling = smallest element in array that is >= x
// - If arr[guess] < x → target is too small here → move right → low = guess+1
// - If arr[guess] >= x → this COULD be the ceiling → record it as 'ans'
//   → but still move LEFT (high = guess-1) to check for a smaller
//     valid candidate (since array is sorted, smaller index = smaller value)
// - ans starts at -1 → if no element >= x exists anywhere, stays -1
//
// Why does this still work in O(log n) despite not stopping early?
// - Search space still HALVES every iteration, just like basic binary search
// - We just delay returning instead of returning immediately — both
//   halves get explored exactly once in total across the whole search
//
// Time: O(log n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        int low=0;
        int high =n-1;
        int ans=-1;
        while(high>=low){
            int guess =low+((high-low)/2);
            if(arr[guess]<x)
            {
                low=guess+1;
            }
             else if(arr[guess]>=x)
            {ans=guess;
                high=guess-1;
                
            }
            
        }
        return ans;
        
    }
};