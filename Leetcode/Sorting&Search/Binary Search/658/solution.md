# [658. Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/)

Because it seems like some problem about the copyright problem, I won't update any proble descroption in my public personal repo. I will just paste the solution I write and what my personal perspective about the problem. However, The link about the original like should be okay here. If there is any problem about the copyright please just send me an email, I will fix it **ASAP**!


## Solution

After read the decription of this problem, the first thing comes up to my mind is **Insertion**, We can easily find the position in input array, but there are some corner cases.<br>

1. lower bound is equal to the target **x**
    1. This is find and just head to find the window
    
2. lower bound is not equal to the target **x**
    1. what is the window index should be started. -> the insertion index is mean this closest index is from the ```l``` or ```l - 1```, a edge case is if input arrat ```[1,2,3,4,5,8]``` and ```x``` is ```6```. We start to find the window from last index ```8```. Therefore, we should find the closest index from ```l``` and ```l - 1```
    2. If the found index is ```0``` or ```arr.size()```, we just return the ```arr.begin(), k``` or ``` arr.end() - k, arr.end()```

```cpp
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        deque<int> temp;
        // insert search

        int l = 0; int r = arr.size();
        while(l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] < x) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (l == 0) return {arr.begin(), arr.begin() + k};
        if (l == arr.size()) return {arr.end() - k, arr.end()};
        if (abs(arr[l - 1] - x) <= abs(arr[l] - x)) l--;
        int i = l;
        int j = i + 1;
        while(k--) {
            if (i < 0) {
                temp.push_back(arr[j]);
                j++;
                continue;
            }

            if (j >= arr.size()) {
                temp.push_front(arr[i]);
                i--;
                continue;
            }


            if (abs(arr[i] - x) <= abs(arr[j] - x)) {
                temp.push_front(arr[i]);
                i--;
            } else {
                temp.push_back(arr[j]);
                j++;
            }
        }
        return {temp.begin(), temp.end()};
        
    }
};
```



## Complexity Analyze

### Time Complexity ```O(log(N) + k)```
The time we cost to find insertion index is ```log(N)``` which N is the input array size and we also cost ```k``` to find the window and copy it to return. so the specific time complexity is ```log(N) + 2k```

### Space Complexity
We use a deque struct which cost ```k``` to store the return struct;
