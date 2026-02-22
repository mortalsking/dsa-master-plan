// Problem Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/
// Day 1 of 100 DSA Day Challenge.
// DS Used: Heap
// Time Complexity: O(log k) for add() method, O(n log k) for constructor
// Space Complexity: O(k)


#include<bits/stdc++.h>
using namespace std;
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int num : nums) {
            if (minHeap.size() < k) {
                minHeap.push(num);
            } else if (num > minHeap.top()) {
                minHeap.push(num);
                if (minHeap.size() > k) {
                    minHeap.pop();
                }
            }
        }
    }

    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push(val);
        } else if (val > minHeap.top()) {
            minHeap.push(val);
            minHeap.pop();
        }
        return minHeap.top();
    }

private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Min-heap to store the k largest elements
};