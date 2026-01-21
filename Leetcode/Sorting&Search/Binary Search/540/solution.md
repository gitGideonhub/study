# [540. Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/description/)

In this problem, I found the right direction which are these two condition 
1. ```nums[mid] == nums[mid+1]```
2. ```mid % 2```

Because, if ```nums[mid] == nums[mid + 1]``` and the mid position is even like a period ```[1,1,2,3,3,4,4]```, when ```l = 0```, ```r = 6``` and ```mid = 3```. The single element is in left side.

## Solution
```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0; int r = nums.size() - 1;
        while(l < r) {
            int mid = l +(r - l) / 2;
            if (nums[mid] != nums[mid + 1]) {
                if (mid % 2 == 0) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } else {
                if (mid % 2 == 1) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
        }

        return nums[l];
    }
};
```