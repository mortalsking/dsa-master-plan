#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> memo;

int fn(int n) {
    return dp(n);
}

int dp(int state) {
    // BASE_CASE
    if (state == 0) return 0;
    if (state == 1) return 1;

    if (memo.count(state)) {
        return memo[state];
    }

    // RECURRENCE_RELATION(STATE)
    int ans = dp(state - 1) + dp(state - 2);

    memo[state] = ans;
    return ans;
}

int main() {
    int n = 10;
    cout << "Fib(" << n << ") = " << fn(n) << "\n";
    return 0;
}