// Problem: Subarray Sums Divisible by K
// Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/
// Difficulty: Medium
// Pattern: Prefix Sum + HashMap
//
// How is it different from Subarray Sum Equals K?
// - Equals K: find prefixSum - k in map (exact difference)
// - Divisible by K: find matching REMAINDER in map, not actual sum
//
// Key Insight:
// - If two prefix sums have SAME remainder when divided by k
// - Their difference (subarray sum) is divisible by k
// - sum[i] % k == sum[j] % k → subarray [j+1, i] divisible by k
// - So instead of storing prefix sum → store sum % k in map
//
// Why handle negative remainder?
// - In C++, negative % positive can give negative result (e.g. -1 % 3 = -1)
// - Mathematically remainder should always be 0 to k-1
// - rem += k fixes this → converts negative remainder to positive equivalent
//
// Why f[0] = 1?
// - Handles subarrays from index 0 with remainder 0
//
// Time: O(n) | Space: O(min(n, k))

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> f;
        int sum=0;
        f[0]=1;
        int res=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            int rem=sum%k;
            if(rem<0){
                rem=rem+k;
            }
            int freq=f[rem];
            res=res+freq;
            f[rem]++;
        }return res;
    }
};  