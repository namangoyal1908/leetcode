// Problem: Triplets with Smaller Sum
// Link: https://www.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1
// Difficulty: Medium
// Pattern: Two Pointers
//
// How is it different from Three Sum and Three Sum Closest?
//
// Three Sum:          find ALL triplets with sum == 0       → store triplets
// Three Sum Closest:  find ONE triplet closest to target    → track minDiff
// Triplets < Sum:     COUNT all triplets with sum < target  → count with math trick
//
// Key Difference - The COUNT TRICK:
// - When arr[i] + *p1 + *p2 < sum → ALL elements between p1 and p2 will
//   also form valid triplets with arr[i] and *p1
// - Why? Array is sorted → everything between p1 and p2 is smaller than *p2
// - So instead of moving p1 one step and checking again,
//   we add (p2 - p1) to ans directly → counts all valid pairs at once!
// - This is the BIGGEST difference from the other two problems
//
// Example:
// arr = [1, 2, 3, 4, 5], sum = 8, fixed = 1
// p1 = 2, p2 = 5 → 1+2+5 = 8 → not < 8 → p2--
// p1 = 2, p2 = 4 → 1+2+4 = 7 → < 8 → ans += (p2-p1) = 2 → means (1,2,3) and (1,2,4)
//
// No result vector needed → just counting, not storing
// No duplicate skipping for p1/p2 → we want COUNT not unique triplets
//
// Time: O(n²) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriplets(int sum, vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int l = arr.size();
        int ans = 0;

        for (int i = 0; i < l - 2; i++) {

            // Skip duplicate fixed elements
            if (i > 0 && arr[i] == arr[i - 1])
                continue;

            int* p1 = &arr[i + 1];  // left pointer
            int* p2 = &arr[l - 1];  // right pointer

            while (p1 < p2) {
                if (arr[i] + *p1 + *p2 >= sum) {
                    // sum too big or equal → move right pointer left
                    p2--;
                }
                else {
                    // sum < target → all elements from p1+1 to p2
                    // will also form valid triplets with arr[i] and *p1
                    ans += (p2 - p1);  // COUNT TRICK → key difference!
                    p1++;
                }
            }
        }

        return ans;
    }
};