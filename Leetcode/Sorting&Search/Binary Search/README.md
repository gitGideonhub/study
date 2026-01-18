# Binary Search

A normal binary search can be used on a array without duplicated elements

## Normal Binary Search Cheat Sheat
Assuming all elements are distinct
```cpp
int binarySearch(vector<int>& arr, int target) {
    int l = 0, r = arr.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == target)
            return mid;          // STOP immediately
        else if (arr[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

```
## Duplicated Input Array

However, What if the arr contains duplicated elements what the found index is ???? There are several conditions might break the normal binary search algorithm.


> **Note:** A input array conatins duplicated elements and you need to find the first/last occurence index.<br>
🔑 Normal binary search answers “does it exist?”<br>
🔑 Bounded binary search answers “where exactly?”<br>

<br>
✔ Target existence check
```
arr = [1, 2, 2, 2, 3]
target = 2
```
<br>
Return target index could be:
<br>

```
1 or 2 or 3
```
<br>


Why normal binary search fail on these cases? Because it violates this invariant:
```
Left < target
Right > target
```
If the input array contains the duplicated element, the condition sould be set into like:

```
Left <= target
Right >= target
```
### Correct Tool For Duplicates
| Goal             | Correct method       |
| ---------------- | -------------------- |
| Exists?          | Normal binary search |
| First occurrence | lower_bound          |
| Last occurrence  | upper_bound - 1      |
| Insertion index  | lower_bound          |
| Count duplicates | upper - lower        |


### Example
```cpp
vector<int> arr = {1, 2, 2, 2, 3, 5};
int target = 2;
```
---

#### Exists
This is the normal binary search
```cpp
int exists(const vector<int>& arr, int target) {
    int l = 0, r = arr.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == target)
            return true;
        else if (arr[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return false;
}
```
---

#### First Occurence
```cpp
int firstOccur(const vector<int>& arr, int target) {
    int l = 0; r = arr.size();
    while(l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] < target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    if (l < arr.size() && arr[l] == target) {
        return l;
    }

    return -1;
}
```
> **Note:** Differences between normal binary search<br> 1. right starting from arr.size() -> r = arr.size();<br> 2. while(l < r)<br> 3. left shirnk is r = mid instead of r = mid - 1;<br> 4. condition at the end of function

---

#### Last Occurence
```cpp
int lastOccur(const vector<int>& arr, int target) {
    int l = 0, r = arr.size();

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] <= target)
            l = mid + 1;
        else
            r = mid;
    }

    if (l > 0 && arr[l - 1] == target)
        return l - 1;
    return -1;
}
```
> **Note:** Differences between normal binary search<br> 1. right starting from arr.size() -> r = arr.size();<br> 2. while(l < r)<br> 3. left shirnk is r = mid instead of r = mid - 1;<br> 4. condition at the end of function<br> 5. shrink condition is if (nums[mid] <= target)

---

#### Insertion Index


```cpp
int insertionIndex(const vector<int>& arr, int target) {
    int l = 0, r = arr.size();

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] < target)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}
```
> **Note:** Insertion index similar to the first occurence but different is that insertion index is return the first place could be insert instead of find the first match element. So basically, there body is same to each other but differnet at the end. The first occurance need to check the l is less than input array size and left index of arr is match to target, but Insertion Index just return left index.
---

#### Count Duplicates -> (Upper - Lower)
```cpp
int countDuplicates(const vector<int>& arr, int target) {
    int first = insertionIndex(arr, target);

    int l = 0, r = arr.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] <= target)
            l = mid + 1;
        else
            r = mid;
    }

    int lastPlusOne = l;
    return lastPlusOne - first;
}
```