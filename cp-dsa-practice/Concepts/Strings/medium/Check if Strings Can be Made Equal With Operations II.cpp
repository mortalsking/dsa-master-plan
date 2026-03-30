//linked to problem: https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/description/
// Day 32 of 100 DSA Day Challenge.
// DS Used: String
// Time Complexity: O(n) where n is the length of the input strings s1 and s2. We are iterating through both strings once to calculate the frequency of characters, which takes O(n) time.
// Space Complexity: O(1) as we are using a fixed-size frequency array of size 52 to store the counts of characters, which takes constant space.


#include <bits/stdc++.h>
using namespace std;

// Approach 1 - Frequency Count
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int freq[52] = {};
        for(int i=0;i<s1.length();i++){
            int off = (i&1) * 26;
            freq[s1[i]-'a'+off]++;
            freq[s2[i]-'a'+off]--;
        }
        for(int i=0;i<52;i++){
            if(freq[i]!=0) return false;
        }
        return true;
    }
};
// Alternative using prime numbers to calculate hash values for both strings and compare them
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int prime[26] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                         43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

        const long long mod = 1000000007; //cap accumulated value w/ min hash collision
        array<long long, 2> h1 = {1, 1}, h2 = {1, 1};

        for (int i = 0; i < s1.length(); i++) {
            int off = i & 1;
            h1[off] = (h1[off] * prime[s1[i] - 'a']) % mod;
            h2[off] = (h2[off] * prime[s2[i] - 'a']) % mod;
        }

        return h1 == h2;
    }
};
// Approach 3 - Sorting
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        array<string, 2> A, B;
        for (int i = 0; i < s1.length(); i++) {
            int off = i & 1;
            A[off] += s1[i];
            B[off] += s2[i];
        }

        for (int i = 0; i < 2; i++) {
            sort(A[i].begin(), A[i].end());
            sort(B[i].begin(), B[i].end());
        }

        return A == B;
    }
};
// Approach 4 - Bit Manipulation and Arithmetic
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        long long eX = 0, oX = 0, eS = 0, oS = 0;
        
        for (int i = 0; i < s1.length(); ++i) {
            int v1 = s1[i], v2 = s2[i];
            int dx = v1 ^ v2;
            int ds = (v1 * v1) - (v2 * v2);
            if (i & 1) {
                oX ^= dx;
                oS += ds;
            } else {
                eX ^= dx;
                eS += ds;
            }
        }
        return !(eX | oX | eS | oS);
    }
};