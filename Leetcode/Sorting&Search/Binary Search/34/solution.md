# [34. Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/)

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.



## Example 1:
```
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
```
## Example 2:
```
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
```
## Example 3:
```
Input: nums = [], target = 0
Output: [-1,-1]
```


## Solution
I perform a first occurence approach to find the first index and do a linear search to find the last occurence. However, my approach's time complexity is going to O(N +log(N)) if the elements are all equal to the target.
- First Solution (O(N))
```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // find first occrence
        if (nums.size() == 0) return {-1, -1};
        int l = 0;
        int r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        if (l >= nums.size() || nums[l] != target) {
            return {-1, -1};
        }

        int startIndex = l;
        while(startIndex < nums.size() && nums[startIndex] == target) {
            startIndex++;
        }
        return {l, startIndex - 1};
    }
};
```

- Second Solution O(log(N))
```cpp
class Solution {
public:
    int firstOccur(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        while(l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        if (l < nums.size() && nums[l] == target) {
            return l;
        }
       
        return -1;
    }
    int lastOccur(vector<int>& nums, int target) {
        int l = 0; int r = nums.size();
        while(l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= target) {
                l = mid + 1;
            }  else {
                r = mid;
            }
        }
        if (l > 0 && nums[l - 1] == target) {
            return l - 1;
        }

        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccur(nums, target);
        if (first == -1) return {-1, -1};
        int last = lastOccur(nums, target);
        return {first, last};
    }
};
```