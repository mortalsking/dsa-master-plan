//link: https://leetcode.com/problems/fancy-sequence/description/
//DS used: Trie and Segment Tree
//Time Complexity: O(N) for append, addAll and multAll operations, where N
//is the number of elements in the sequence. O(1) for getIndex operation.
//Space Complexity: O(N) for storing the sequence in the arr vector.


#include<bits/stdc++.h>
using namespace std;

//approach 1: TLE
class Fancy {
public:
    vector<long long>arr;
    long long MOD = 1000000007LL;
    Fancy() {
        
    }
    
    void append(int val) {
        arr.push_back(val);
    }
    
    void addAll(int inc) {
        for(int i=0;i<arr.size();i++){
            arr[i] = (arr[i] + inc)%MOD;
        }
    }
    
    void multAll(int m) {
        for(int i=0;i<arr.size();i++){
            arr[i] = (arr[i]*m)%MOD;
        }    
    }
    
    int getIndex(int idx) {
        if(idx>= arr.size()) return -1;
        return arr[idx]%MOD;
    }
};

//Approach: Lazy Propagation with Segment Tree
class Fancy {
public:
        long long mul,add;
        long long MOD = 1000000007LL;
        vector<long long>arr;
    Fancy() {
        mul = 1;
        add = 0;
    }
    long long power(long long a,long long b){
        long long res = 1;
        a %= MOD;
        while(b>0){
            if(b&1){
                res = (res * a)%MOD;
            }
            a = (a*a)%MOD;
            b >>= 1;
        }
        return res;
    }
    long long modInverse(long long x){
        return power(x,MOD-2);
    }
    void append(int val) {
        long long stored = ((val - add + MOD) % MOD * modInverse(mul)) % MOD;
        arr.push_back(stored);
    }
    
    void addAll(int inc) {
        add = (add + inc)%MOD;
    }
    
    void multAll(int m) {
        mul = (mul*m)%MOD;
        add = (add*m)%MOD;
    }
    
    int getIndex(int idx) {
        if(idx >= arr.size()) return -1;
        long long ans  = (arr[idx] * mul) %MOD;
        ans = (ans + add)%MOD;
        return (int)ans;
    }
};


