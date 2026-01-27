# [912. Sort an Array]()

## Solution

Counting sort<br>
Time Complexity: ```O(n + k)```, ```k``` is the max to min interval + 1;<br>
Space Complexity: ```O(n)```
```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int minVal = *min_element(nums.begin(), nums.end());

        vector<vector<int>> count(maxVal - minVal + 1);
        for (int num:nums) {
            count[num - minVal].push_back(num);
        }
        vector<int> res;

        for (int i = 0; i < maxVal - minVal + 1; i++) {
            for (int idx = 0; idx < count[i].size(); idx++) {
                res.push_back(count[i][idx]);
            }
        }
        return res;
    }
};
```