// Problem: Subarray Sum Equals K
// Link: https://leetcode.com/problems/subarray-sum-equals-k/
// Difficulty: Easy
// Pattern: Prefix Sum + HashMap
//
// Brute Force: O(n²)
// - Two loops → fix start, expand end, track sum == k
//
// Why Prefix Sum + HashMap?
// - prefixSum[i] = sum of elements from index 0 to i
// - Sum of subarray [j+1, i] = prefixSum[i] - prefixSum[j]
// - We want prefixSum[i] - prefixSum[j] == k
// - → prefixSum[j] == prefixSum[i] - k
// - At every index ask: how many previous prefix sums equal (currentSum - k)?
// - HashMap stores {prefixSum → frequency} for O(1) lookup
//
// Why f[0] = 1?
// - Handles case where subarray starts from index 0
// - If prefixSum == k → prefixSum - k == 0 → needs f[0] to exist
// - Without this → subarrays starting at index 0 are missed
//
// Why check BEFORE updating map?
// - Must add to result before inserting current prefix sum
// - Otherwise current index could match itself → wrong count
//
// Time: O(n) | Space: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;

        unordered_map<int, int> f;
        f[0] = 1;  // empty prefix sum → handles subarrays from index 0

        int res = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            int ques = sum - k;   // target previous prefix sum
            int freq = f[ques];   // how many times it appeared
            res += freq;

            f[sum]++;  // add current prefix sum to map
        }

        return res;
    }
};