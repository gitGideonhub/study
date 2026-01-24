#[3814. Maximum Capacity Within Budget](https://leetcode.com/problems/maximum-capacity-within-budget/description/?envType=problem-list-v2&envId=wpl9cukj)

Exhausted day..., I was trying solution weekly contest 485 and this problem is really beat me. At the beginning, I try to find the subsequence with only 2 elements of the original array. But it went to TLE...,

This solution is found from discussion not mind, I already add this problem to my review plan. I have to say, this problem should be hard one.


## Solution
```cpp
class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < costs.size(); i++) {
            pairs.push_back({costs[i], capacity[i]});
        }

         // sort by cost
        sort(pairs.begin(), pairs.end(),
             [](const pair<int,int>& a, const pair<int,int>& b) {
                 return a.first < b.first;
             });

        int maxRes = 0;

        for (auto p:pairs) {
            auto [cost, cap] = p;
            if (cost < budget) {
                maxRes = max(maxRes, cap);
            }
        }

        vector<int> prefixMax(costs.size(), 0);

        for (int i = 0; i < prefixMax.size(); i++) {
            if (i > 0) {
                prefixMax[i] = max(prefixMax[i-1], pairs[i].second);
            } else {
                prefixMax[i] = pairs[i].second;
            }
        }

        for (int r = 1; r < pairs.size(); r++) {
            int remain = budget - pairs[r].first;
            if (remain <= 0) continue;
            int l = 0, h = r - 1, bestIdx = -1;
            while (l <= h) {
                int mid = l + (h - l) / 2;
                if (pairs[mid].first < remain) {
                    bestIdx = mid;
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            }
            if (bestIdx != -1) {
                maxRes = max(maxRes, pairs[r].second + prefixMax[bestIdx]);
            }
        }

        return maxRes;
    }
};
```