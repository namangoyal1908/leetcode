// Problem: Longest Substring with Same Letters after Replacement
// Link: https://leetcode.com/problems/longest-repeating-character-replacement/
// Difficulty: Hard
// Pattern: Sliding Window (Variable Size) + Frequency Array
//
// Problem in simple terms:
// - You can replace at most k characters in the window
// - Find longest substring where all chars are same after replacements
//
// Key Insight:
// - In any window of length len, if most frequent char appears maxcnt times
// - Then (len - maxcnt) = characters that need to be replaced
// - If (len - maxcnt) <= k → valid window (we can fix it with k replacements)
// - If (len - maxcnt) > k → invalid → shrink from left
//
// Why Frequency Array instead of HashMap?
// - Only 256 ASCII characters possible → fixed size array faster than map
// - vector<int> f(256, 0) → index = ASCII value, value = frequency
// - f[s[high]]++ → same as map but O(1) with no hashing overhead
//
// find() function:
// - Scans all 256 entries → returns max frequency in current window
// - Called every time window changes to get updated maxcnt
// - O(256) = O(1) constant time
//
// Invalid condition:
// - (len - maxcnt) > k → too many replacements needed → shrink
// - After shrinking → recalculate maxcnt and len
//
// Why res updates every iteration?
// - After while loop window is always valid
// - Every valid window is a candidate for answer
//
// Brute Force: O(n² * 26) → fix start, try all ends, track max freq
// Optimised: O(n * 256) = O(n) → sliding window with freq array
//
// Time: O(n) | Space: O(256) = O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Returns frequency of most common character in window
    int find(vector<int>& a) {
        int maxc = -1;
        for (int i = 0; i < 256; i++) {
            maxc = max(maxc, a[i]);
        }
        return maxc;
    }

    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> f(256, 0);  // frequency array for all ASCII chars

        int low = 0;
        int res = 0;

        for (int high = 0; high < n; high++) {
            f[s[high]]++;  // EXPAND → add new character

            int maxcnt = find(f);      // most frequent char in window
            int len = high - low + 1;  // current window size

            // SHRINK → too many replacements needed
            while (len - maxcnt > k) {
                f[s[low]]--;
                low++;
                maxcnt = find(f);      // recalculate after shrinking
                len = high - low + 1;
            }

            // Valid window → update result
            res = max(res, len);
        }

        return res;
    }
};