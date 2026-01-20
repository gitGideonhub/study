# [33. Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/description/)


Because the array is rotated and all elements are distinct. At the beginning I am trying to find the sorted order for entire region [l, r], but it cannot be solve when the region still in a rotated index.
<br>
The case would be like following 2 list:
1. left is the sorted array ```[4,5,6,7,8,1,2,3]```, when first iter, l = 0, r = 7. If the target is in left side, we shrink to left```r = mid - 1```, else ```l = mid + 1```
2. right is the sorted array ```nums[mid] > nums[l]``` and ``` nums[mid] < target < nums[r]```, we go right.

> **Note:** Assuming the left side is in sorted and the target is in right side, we cannot not perform ```target < nums[r]``` to be the shrink condition.

## Solution

```cpp

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > nums[l]) {
                // left is in sorted order
                if (nums[mid] > target && target >= nums[l]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
```