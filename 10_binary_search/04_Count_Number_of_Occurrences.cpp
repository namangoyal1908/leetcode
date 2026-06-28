// Problem: Count Number of Occurrences
// Link: https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1
// Difficulty: Easy
// Pattern: Binary Search
//
// How is it different from "First and Last Position"?
// - Exact SAME two binary searches to find first and last occurrence
// - Only difference: instead of RETURNING the indices, we use them to
//   CALCULATE the count → y = (resi[1] - resi[0]) + 1
//
// Why (resi[1] - resi[0]) + 1?
// - resi[0] = index of first occurrence, resi[1] = index of last occurrence
// - Number of elements between two indices (inclusive) = difference + 1
//   e.g., indices 3 to 6 → (6-3)+1 = 4 elements: 3,4,5,6
//
// Why check resi[0] == -1 before calculating?
// - If target doesn't exist in array, BOTH resi[0] and resi[1] stay -1
//   (never updated inside either binary search)
// - Without this check → (resi[1]-resi[0])+1 = (-1-(-1))+1 = 1 → WRONG,
//   would incorrectly say count is 1 even though target isn't present
// - Edge case fix returns 0 directly when target is genuinely absent
//
// Time: O(log n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
   int last(int low, int guess) {
        low = guess + 1;
        return low;
    }
    int first(int high, int guess) {
        high = guess - 1;
        return high;
    }
    
    int countFreq(vector<int>& arr, int target) {
        vector<int> resi = {-1, -1}; 
        int n = arr.size();
        
        int low = 0;
        int high = n - 1;
        while (high >= low) {
            int guess = low + ((high - low) / 2);
            if (arr[guess] > target) {
                high = first(high, guess);
            } 
            else if (arr[guess] < target) {
                low = last(low, guess);
            } 
            else if (arr[guess] == target) {
                resi[0] = guess; 
                high = first(high, guess); 
            }
        }
        low = 0;
        high = n - 1;
        while (high >= low) {
            int guess = low + ((high - low) / 2);
            if (arr[guess] > target) {
                high = first(high, guess);
            } 
            else if (arr[guess] < target) {
                low = last(low, guess);
            } 
            else if (arr[guess] == target) {
                resi[1] = guess; 
                low = last(low, guess); 
            }
        }
        // EDGE CASE FIX: If target wasn't found, return 0 directly
        if (resi[0] == -1) {
            return 0;
        }
        int y = (resi[1] - resi[0]) + 1;
        return y;
    }
};