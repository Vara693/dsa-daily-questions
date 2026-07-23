// You are given an integer array nums of length n.

// Construct an array prefixGcd where for each index i:

// Let mxi = max(nums[0], nums[1], ..., nums[i]).
// prefixGcd[i] = gcd(nums[i], mxi).
// After constructing prefixGcd:

// Sort prefixGcd in non-decreasing order.
// Form pairs by taking the smallest unpaired element and the largest unpaired element.
// Repeat this process until no more pairs can be formed.
// For each formed pair, compute the gcd of the two elements.
// If n is odd, the middle element in the prefixGcd array remains unpaired and should be ignored.
// Return an integer denoting the sum of the GCD values of all formed pairs.

// The term gcd(a, b) denotes the greatest common divisor of a and b.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        while(b!=0) {
            int tmp = b;
            b = a%b;
            a = tmp;
        }

        return a;
    }

    long long gcdSum(vector<int>& nums) {
        int currMax = nums[0];
        int n = nums.size();
        vector<int> gcdStore(n, -1);
        gcdStore[0] = nums[0];

        for(int i=1; i<n; i++) {
            currMax = max(currMax, nums[i]);
            gcdStore[i] = gcd(currMax, nums[i]);
        }

        sort(gcdStore.begin(), gcdStore.end());

        int left = 0;
        int right = n-1;
        long long addition = 0;
        while (left < right) {
            addition += gcd(gcdStore[left], gcdStore[right]);
            left++;
            right--;
        }

        return addition;
    }
};

int main() {

    return 0;
}