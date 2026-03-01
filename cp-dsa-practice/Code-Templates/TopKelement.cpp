#include <bits/stdc++.h>
using namespace std;

vector<int> fn(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int num: arr) {
        heap.push(num);
        if (heap.size() > k) {
            heap.pop();
        }
    }

    vector<int> ans;
    while (heap.size() > 0) {
        ans.push_back(heap.top());
        heap.pop();
    }

    return ans;
}