# [410. Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/description/)

# [1011. Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/)

Today, ChatGPT gives me two similar questions with different problem decription. The core of these two problem is spilt a array to certain length subarray and return the maximum sum of subarray after spilt it. At the beginning, I thought it was a dynamic problem, but the study plan show me today's topic is binary search. So I try to find the search region which are the total sum of input array and the maximum element's value.

This is very hard to figure it out during an interview because the problem is leading my mind heading to dynamic programming. If I used a dynamic programming, the time complexity goes to ```O(D*N^2)```, these will ***TLE***.

## Solution

```cpp
class Solution {
public:
    int helper(vector<int>& nums, int target, int k) {
        int sum = 0;
        int needs = 0;
        for (int num:nums) {
            sum+=num;
            if (sum > target) {
                sum = num;
                needs++;
            }
        }

        return needs >= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxVal = *max_element(nums.begin(), nums.end());

        int l = maxVal;
        int r = sum;

        while(l < r) {
            int mid = l + (r - l) / 2;
            if (helper(nums, mid, k)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }
};
```


## Complexity

Time Complexity: ```O(N log(K))```, where k is represented the range form max element to total sum

Space Complexity: ```O(1)```