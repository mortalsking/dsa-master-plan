#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int target) {
        int left = 0;
        int right = int(arr.size()) - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                // do something;
                return mid;
            }
            if (arr[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        // left is the insertion point
        return left;
    }

// Binary search: duplicate elements, left-most insertion point

int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

// Binary search: duplicate elements, right-most insertion point
int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

// Binary search on answer template
int fn(vector<int>& arr) {
    int left = INT_MIN;
    int right = INT_MAX;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

bool check(int x) {
    // this function is implemented depending on the problem
    return true; // or false
}

// Alternative binary search on answer template (if you want to return right instead of left)
int fn(vector<int>& arr) {
    int left = INT_MIN;
    int right = INT_MAX;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return right;
}

bool check(int x) {
    // this function is implemented depending on the problem
    return true; // or false
}