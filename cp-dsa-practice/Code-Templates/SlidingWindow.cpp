#include <bits/stdc++.h>
using namespace std;


int fn(vector<int>& arr) {
    int left = 0, ans = 0, curr = 0;

    for (int right = 0; right < arr.size(); right++) {
        // do logic here to add arr[right] to curr

        while (arr[right] - arr[left] > 100) {
            // remove arr[left] from curr
            left++;
        }

        // update ans
        ans = max(ans, right - left + 1);
    }

    return ans;
}