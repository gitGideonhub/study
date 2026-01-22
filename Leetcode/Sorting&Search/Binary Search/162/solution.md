# [162. Find Peak Element](https://leetcode.com/problems/find-peak-element/description/)

# [852. Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array/description/)

In this problem, we use a feature of binary search, which is when a while loop's condition is ```(l < r)```, its mid always not meet the right index. So, we can use the ```mid``` and ```mid + 1``` index to be our condition to find the peak in a input array.


## Solution

```cpp
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0;
        int r = arr.size() - 1;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] > arr[mid + 1]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};
```


## Complexity

Time Complexity: ```O(log(N))```<br>
Space Complexity: ```O(1)```