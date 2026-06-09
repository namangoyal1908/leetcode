// Problem: Longest Substring with K Distinct Characters
// Link: https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
// Difficulty: Medium
// Pattern: Sliding Window (Variable Size) + HashMap
//
// Why HashMap here?
// - We need to track COUNT of each character in current window
// - HashMap stores → {character: frequency} pairs
// - f.size() = number of DISTINCT characters in window
// - We need distinct count <= k → HashMap gives this in O(1)
//
// HashMap Syntax Used:
// unordered_map<char, int> f;  → declares map of char to int
// f[s[high]]++                 → increment frequency of character
// f[s[low]]--                  → decrement frequency of character
// f.erase(s[low])              → remove character from map completely
// f.size()                     → number of distinct characters
//
// Variable Sliding Window + HashMap:
// - EXPAND right (high++) → add character to map, increase frequency
// - SHRINK left (low++) → when distinct chars > k
//   → decrease frequency of leftmost char
//   → if frequency hits 0 → erase from map (no longer in window)
// - Record answer only when f.size() == k (exactly k distinct chars)
//
// Why erase when frequency == 0?
// - If we don't erase → f.size() still counts that character
// - But it's no longer in the window → wrong distinct count
// - Erasing keeps f.size() accurate
//
// Why res = -1?
// - If no valid window with exactly k distinct chars exists → return -1
//
// Microsoft Hiring Analogy 🏢
// - Hire employees (high++) but only allow k TYPES of skills
// - If more than k skill types → fire oldest (low++) until back to k
// - Track longest team with exactly k skill types
//
// Time: O(n) | Space: O(k) → map holds at most k+1 chars at any time

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestKSubstr(string& s, int k) {
        int low = 0;
        int res = -1;
        int n = s.size();

        unordered_map<char, int> f;  // {character → frequency in window}

        for (int high = 0; high < n; high++) {
            f[s[high]]++;  // EXPAND → add new character to window

            // SHRINK → too many distinct characters
            while (f.size() > k) {
                f[s[low]]--;          // reduce frequency of leftmost char
                if (f[s[low]] == 0) {
                    f.erase(s[low]);  // remove from map if no longer in window
                }
                low++;
            }

            // Valid window → exactly k distinct characters
            if (f.size() == k) {
                int len = high - low + 1;
                res = max(res, len);
            }
        }

        return res;
    }
};