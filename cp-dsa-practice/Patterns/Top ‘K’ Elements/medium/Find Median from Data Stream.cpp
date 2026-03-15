//Problem Link: https://leetcode.com/problems/find-median-from-data-stream/
//Day 18 of 100 DSA Day Challenge.
//DS Used: Sorting
//Time Complexity: O(N log N) for sorting the array each time we call findMedian().
//Space Complexity: O(N) for storing the elements in the array.



#include <bits/stdc++.h>
using namespace std;

//Approach 1: Sorting(TLE)
class MedianFinder {
public:
    vector<int>arr;
    MedianFinder() {
    }
    
    void addNum(int num) {
        arr.push_back(num);
    }
    
    double findMedian() {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        if(n%2 == 0){
        return (arr[n/2] + arr[n/2 - 1])/2.0;
        }else{
        return arr[n/2];  
        }
    }
};
//Approach 2: Two Heaps
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int> > minHeap;
	priority_queue<int> maxHeap;
    MedianFinder(){}

    void addNum(int num) {
        if (maxHeap.empty() or maxHeap.top() > num) {
			maxHeap.push(num);
		} else {
			minHeap.push(num);
		}

		if (maxHeap.size() > minHeap.size() + 1) {
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		} else if (minHeap.size() > maxHeap.size() + 1) {
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
			if (maxHeap.empty()) {
				return 0;
			} else {
				double avg = (maxHeap.top() + minHeap.top()) / 2.0;
				return avg;
			}

		} else {
			return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
		}
    }
};