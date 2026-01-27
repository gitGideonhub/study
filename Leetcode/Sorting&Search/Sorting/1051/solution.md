# [1051. Height Checker](https://leetcode.com/problems/height-checker/description/)




## Solution
### Merge Sort<br>
Time Complexity: ```O(log(n))``` <br>
Space Complexity: ```O(n)```
```cpp
class Solution {
public:
    void merge(vector<int>& nums, int l, int mid, int r, vector<int>& temp) {
        int i = l;
        int j = mid + 1;
        int k = l;

        while(i <= mid && j <= r) {
            if (nums[i] < nums[j]) {
                swap(nums[i], nums[j])
                i++;
            } else {
                temp[k] = nums[j];
                j++;
            }
            k++;
        }

        while(i <= mid) {
            temp[k] = nums[i];
            i++;
            k++;
        }

        while(j <= r) {
            temp[k] = nums[j];
            j++;
            k++;
        }

        for (int p = l; p <= r; p++) {
            nums[p] = temp[p];
        }

    }
    void mergeSort(vector<int>& nums, int l, int r, vector<int>& temp) {
        if (l >= r) return;

        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid, temp);
        mergeSort(nums, mid + 1, r, temp);
        merge(nums, l, mid, r, temp);
    }
    int heightChecker(vector<int>& heights) {
        vector<int> temp(heights.size());
        vector<int> h = heights;
        mergeSort(h, 0, heights.size() - 1, temp);
        for (int num:temp) {
            cout << num << " ";
        } cout << endl;
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != h[i]) {
                res++;
            }
        }

        return res;
        
    }
};
```