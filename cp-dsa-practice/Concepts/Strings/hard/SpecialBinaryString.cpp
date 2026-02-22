#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        return helper(s);
    }

private:
    string helper(const string &s) {
        vector<string> substrings;
        int count = 0, start = 0;

        for (int i = 0; i < s.size(); i++) {
            count += (s[i] == '1' ? 1 : -1);
            if (count == 0) {
                // Recursively process the inside part
                string inner = helper(s.substr(start + 1, i - start - 1));
                substrings.push_back("1" + inner + "0");
                start = i + 1;
            }
        }

        // Sort substrings in descending lex order
        sort(substrings.begin(), substrings.end(), greater<string>());
        string result;
        for (auto &sub : substrings) result += sub;
        return result;
    }
};
