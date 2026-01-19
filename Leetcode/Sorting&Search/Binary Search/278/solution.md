# [278. First Bad Version](https://leetcode.com/problems/first-bad-version/description/)


The problem is give you a api which is ```isBadVersion(int version);``` and it will return the version is bad or not. Assuming there serveal code version from ```0``` to ```n```, we can easily perform a linear search to find the first return true from ```isBadVersion(int version)```. However, there is a faster method than linear search is that find the first true ->  **First Occurence**.<br> in binary search section we study before, the edge cases of First Occurence is when we found the last element in the search target, but the problem's constrain ```1 <= bad version <= n``` perfectly avoid the edge case.

## Solution
```cpp
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0;
        int r = n;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid) == false) {
                /* shrink left */
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }
};
```

## Time Complexity ```O(log(N))```
## Space Complexity ```O(1)```