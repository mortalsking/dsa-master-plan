// https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/description/
// Day 17 of 100 DSA Day Challenge.
// DS Used: Binary Search
// Time Complexity: O(N log M) where N is the number of elements in times and M is the search space for seconds (up to 1e16)
// Space Complexity: O(1) as we are using only a constant amount of extra space


#include <bits/stdc++.h>
using namespace std;


using ll = long long;
class Solution {
public:
    ll minNumberOfSeconds(int height, vector<int>& times) {
        ll lo = 1, hi = 1e16;

        while (lo < hi) {
            ll mid = (lo + hi) >> 1;
            ll tot = 0;
            for (int i = 0; i < times.size() && tot < height; i++)
                tot += (ll)(sqrt((double)mid / times[i] * 2 + 0.25) - 0.5);
            if (tot >= height)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};