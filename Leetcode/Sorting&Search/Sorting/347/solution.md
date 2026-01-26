# [347. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/description/)

In this problem, I try to use bucket sort to find the solution. The constrain is:
- ```-10^4 <= nums[i] <= 10^4``` 
- ```1 <= nums.length <= 10^5```<br>
So, If I use a array ```count``` with length of nums it is only cost around 100KB * 4(word size), linear space complexity is acceptable.

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<vector<int>> count(nums.size() + 1);
        unordered_map<int, int> map;
        for (int num:nums) {
            map[num]++;
        }

        for (auto& it:map) {
            count[it.second].push_back(it.first);
        }
        int index = count.size() - 1;
        vector<int> res;
        while(index && k) {
            if (count[index].size() > 0) {
                for (int i = 0; i < count[index].size(); i++) {
                    if (k == 0) break;
                    res.push_back(count[index][i]);
                    k--;
                }
            }
            index--;
        }
        return res;
    }
};
```