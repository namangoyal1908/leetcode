// Problem: Permutation in a String
// Link: https://leetcode.com/problems/permutation-in-string/
// Difficulty: Hard
// Pattern: Sliding Window (Fixed Size)
//
// Problem in simple terms:
// - Check if any permutation of s1 exists as substring in s2
// - Permutation = same characters, any order
//
// Key Insight:
// - All permutations of s1 have same character frequencies
// - So instead of generating all permutations → just match frequencies
// - Window size is fixed = s1.length() → Fixed Sliding Window
//
// Why Fixed Window here? (Pratyush taught variable but fixed works better)
// - Permutation length must equal s1.length() → window size never changes
// - Variable window is for unknown size → here size is known = n
// - Fixed window is cleaner and more efficient here
//
// Approach:
// - need[26]   → frequency of s1 characters
// - window[26] → frequency of current window in s2
// - Build first window of size n → compare with need
// - Slide window one step at a time:
//   → add incoming character (s2[i])
//   → remove outgoing character (s2[i-n])
//   → compare frequencies → if match → permutation found
//
// Why int[26] instead of HashMap?
// - Only lowercase letters → 26 possible values
// - Array index = char - 'a' → O(1) access
// - Comparing two arrays of size 26 = O(26) = O(1)
//
// Time: O(26*m) = O(m) | Space: O(26) = O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (n > m) return false;

        int need[26] = {0};    // frequency of s1
        int window[26] = {0};  // frequency of current window in s2

        // Build need and first window of size n
        for (int i = 0; i < n; i++) {
            need[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        }

        // Check first window
        bool same = true;
        for (int i = 0; i < 26; i++) {
            if (need[i] != window[i]) {
                same = false;
                break;
            }
        }
        if (same) return true;

        // Slide fixed window across s2
        for (int i = n; i < m; i++) {
            window[s2[i] - 'a']++;      // add incoming character
            window[s2[i - n] - 'a']--;  // remove outgoing character

            // Compare frequencies
            same = true;
            for (int j = 0; j < 26; j++) {
                if (need[j] != window[j]) {
                    same = false;
                    break;
                }
            }
            if (same) return true;
        }

        return false;
    }
};