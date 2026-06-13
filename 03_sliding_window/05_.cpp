// Problem: Longest Substring Without Repeating Characters
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Difficulty: Medium
// Pattern: Sliding Window (Variable Size)
//
// Brute Force: O(n²)
// - Fix every starting index, expand right until a repeat is found
// - Track maximum length seen
// - Too slow for large inputs
//
// Variable Sliding Window - The "k is hidden" Insight
//
// In fixed window problems, k (window size) is given directly.
// Here, k is NOT given — but we can DERIVE it:
//
//   A window is valid when all characters are unique
//   → unique chars = distinct keys in hashmap = f.size()
//   → window length = high - low + 1
//   → valid condition: f.size() == high - low + 1
//     (every character in the window appears exactly once)
//
// Strategy:
// - EXPAND right (high++) → add character to hashmap (increase freq)
// - If f.size() < window length → duplicate exists → SHRINK from left
//     → decrement freq of s[low], erase if 0, low++
// - Once f.size() == window length → window is valid → record length
//
// Analogy:
// - Imagine collecting unique trading cards in a bag
// - Keep adding cards from the right
// - If bag has a duplicate → throw out from the left until all unique again
// - Track the biggest bag size where all cards were unique
//
// Key Insight:
// - f.size() < (high - low + 1) means a duplicate snuck in
// - f.size() == (high - low + 1) means window is perfectly unique
//
// Time: O(n) | Space: O(min(n, 26)) → O(1) for lowercase alpha
// Each character is added once (high++) and removed once (low++) → O(2n) = O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int low = 0;
        int res = INT_MIN;
        unordered_map<char, int> f;  // frequency map of current window

        for (int high = 0; high < n; high++) {
            f[s[high]]++;  // EXPAND → add character to window

            int len = high - low + 1;

            while (f.size() < len) {  // duplicate exists → shrink
                f[s[low]]--;          // reduce freq of leftmost char
                if (f[s[low]] == 0)
                    f.erase(s[low]);  // clean up zero-freq entries
                low++;
                len = high - low + 1;
            }

            // f.size() == len → all characters unique → valid window
            res = max(res, high - low + 1);
        }

        return (res == INT_MIN) ? 0 : res;  // 0 if string was empty
    }
};