# [153. Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/)


```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {

        int l = 0;
        int r = nums.size() - 1;
        if (nums[l] < nums[r]) return nums[l];
        while(l < r) {
            int mid = l + (r - l) / 2;
            // [4,5,6,7,0,1,2]
            if (nums[r] < nums[mid]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
};
```