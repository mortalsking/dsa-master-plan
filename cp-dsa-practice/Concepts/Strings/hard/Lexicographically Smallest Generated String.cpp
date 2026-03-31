// Problem: Lexicographically Smallest Generated String
// DS Used: String
//day 33 of 100 day challenge
// Time Complexity: O(n*m) where n is the length of string s and m is the length of string t. We are iterating through string s and for each 'T' character, we are checking a substring of length m.
// Space Complexity: O(n+m) for the answer string and the old_ans string which are both of size n+m-1.



#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    string generateString(string s, string t) {
        int n = s.size(), m = t.size();
        string ans(n + m - 1, '?'); // ? indicates an undecided position

        // Process T
        for (int i = 0; i < n; i++) {
            if (s[i] != 'T') {
                continue;
            }
            // The substring must equal t
            for (int j = 0; j < m; j++) {
                char v = ans[i + j];
                if (v != '?' && v != t[j]) {
                    return "";
                }
                ans[i + j] = t[j];
            }
        }

        string old_ans = ans;
        for (char& c : ans) {
            if (c == '?') {
                c = 'a'; // Initial value for undecided positions is a
            }
        }

        // Process F
        for (int i = 0; i < n; i++) {
            if (s[i] != 'F') {
                continue;
            }
            // The substring must not equal t
            if (string(ans.begin() + i, ans.begin() + i + m) != t) {
                continue;
            }
            // Find the last undecided position
            bool ok = false;
            for (int j = i + m - 1; j >= i; j--) {
                if (old_ans[j] == '?') { // Previously filled with a, now change it to b
                    ans[j] = 'b';
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                return "";
            }
        }

        return ans;
    }
};