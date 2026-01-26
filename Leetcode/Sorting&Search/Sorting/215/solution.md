# [215. Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/description/)

In this problem, I try to use **Quick Select** to solve this problem, but it lead to TLE in some large input case. Following code is my first version:
```cpp
class Solution {
public:
    int partition(vector<int>& nums, int l, int r, int pivotIndex) {
        int store = l;
        int pivot = nums[pivotIndex];
        swap(nums[pivotIndex], nums[r]);
        for (int i = l; i < r; i++) {
            if (nums[i] <= pivot) {
                swap(nums[store], nums[i]);
                store++;
            }
        }

        swap(nums[store], nums[r]);
        return store;
    }
    int quickSelect(vector<int>& nums, int l, int r, int k) {
        if (l == r) return nums[l];
        int pivot = l + rand() % (r - l);
        pivot = partition(nums, l, r, pivot);
        if (pivot < k) {
            return quickSelect(nums, pivot + 1, r, k);
        } else if (pivot > k) {
            return quickSelect(nums, l, pivot - 1, k);
        } else {
            return nums[k];
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int K = nums.size() - k;
        return quickSelect(nums, 0, nums.size() - 1, K);
    }
};
```


Seems like the ```pivot``` index always same in this case. I can easily solve by sorting or priority queue, but I need to review other algorithm. -> **Three Way Partition**.<br>

In each recursion, we divid the nums into ```left```, ```mid``` and ```right``` and there are three condition at each iteration:<br>
1. left array size is greater than the target ```k``` -> this means the ```k``` is in left, so we go left array.
2. the left size and mid size is less than target ```k``` -> we go right but ```k``` needs to minus the left size and mid size.
3. left size add mid size is greater than ```k``` && left size is not greater than ```k```. This means we find the ```k```'s value which is our ```pivot```.


```cpp
class Solution {
public:
    int quickSelect(vector<int>& nums, int k) {
        int pivot = nums[rand() % nums.size()];

        vector<int> left;
        vector<int> right;
        vector<int> mid;

        for (int num:nums) {
            if (num > pivot) {
                left.push_back(num);
            } else if (num < pivot) {
                right.push_back(num);
            } else {
                mid.push_back(num);
            }
        }

        if (k <= left.size()) {
            return quickSelect(left, k);
        }

        if (left.size() + mid.size() < k) {
            return quickSelect(right, k - left.size() - mid.size());
        }

        return pivot;
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, k);
    }
};
```


counting sort
```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int minVal = *min_element(nums.begin(), nums.end());

        vector<int> count(maxVal - minVal + 1, 0);

        for (int num:nums) {
            count[num-minVal]++;
        }

        for (int i = count.size() - 1; i >= 0; i--) {
            if (count[i] > 0) {
                k-=count[i];
            }

            if (k <= 0) {
                return i+minVal;
            }
        }

        return -1;
    }
};
```