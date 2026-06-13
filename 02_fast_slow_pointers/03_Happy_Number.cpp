// Problem: Happy Number
// Link: https://leetcode.com/problems/happy-number/
// Difficulty: Medium
// Pattern: Fast & Slow Pointers
//
// What is a Happy Number?
// - Repeatedly replace number with sum of squares of its digits
// - If eventually reaches 1 → Happy Number
// - If never reaches 1 → gets stuck in a cycle → Not Happy
//
// Why Fast & Slow Pointers?
// - Unhappy numbers loop infinitely → cycle exists
// - Happy numbers reach 1 → no cycle
// - Same Floyd's algorithm → if cycle exists slow==fast!=1
// - If happy → slow==fast==1
//
// Key Difference from LinkedList Cycle:
// - No actual linked list → numbers themselves form the sequence
// - next node = findSquareSum(current)
// - slow = one step, fast = two steps (same concept, different domain)
//
// Why do loop instead of while?
// - Both start at n → if checked before moving → always equal
// - do-while guarantees at least one move before comparison
//
// findSquareSum():
// - Extract digits using % 10
// - Square each digit and add to sum
// - Move to next digit using / 10
//
// Time: O(log n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSquareSum(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;   // extract last digit
            sum += digit * digit; // square and add
            n /= 10;              // remove last digit
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = findSquareSum(slow);                    // 1 step
            fast = findSquareSum(findSquareSum(fast));     // 2 steps
        } while (slow != fast);

        return slow == 1;  // met at 1 → happy | met elsewhere → cycle
    }
};