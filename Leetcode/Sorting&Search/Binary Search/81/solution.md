# [81. Search in Rotated Sorted Array II] (https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/)

Basically, this problem is similar to [33. Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/description/) but with duplicated element. If I use the perform the solution with the code from **33**, it will lead to tast fail when the element has duplicated number like ```[1,0,1,1,1]```. The ```nums[l] == nums[r]``` break entire condition define for the original problem. So, I add the following code to trigger next mid find.

```cpp
    if (nums[l] == nums[mid]) {
        l++;
        continue;
    }
```


But because the condition we added above, the entire time complexity seems like approaching to ```O(N)```.


## Solution

```cpp
/*
[4,5,6,7,0,1,2] target = 0
l = 0, r = 6, mid = 3, (4, 7, 2) -> l = mid +１ = 4
l = 4, r = 6, mid = 5, (0, 1, 2) -> r = 5 - 1 = 4

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return true;
            if (nums[l] == nums[mid]) {
                l++;
                continue;
            }
            if (nums[mid] > nums[l]) {
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
        return false;
    }
};
```