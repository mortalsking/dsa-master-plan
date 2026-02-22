#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int deletions = 0;

        for (char c : s) {
            if (!st.empty() && st.top() == 'b' && c == 'a') {
                // Violation: 'a' comes after 'b'
                // Option 1: delete this 'a'
                // Option 2: delete one 'b' from stack
                deletions++;
                st.pop();  // delete 'b' instead of 'a'
            } else {
                st.push(c);
            }
        }

        return deletions;
    }
};
