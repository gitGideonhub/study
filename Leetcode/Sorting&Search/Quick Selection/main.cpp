#include <vector>
using namespace std;
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
        int pivot = l + (r - l) / 2;
        pivot = partition(nums, l, r, pivot);
        if (pivot < k) {
            return quickSelect(nums, pivot + 1, r, k);
        } else if (pivot > k) {
            return quickSelect(nums, l, pivot - 1, k);
        } else {
            return nums[k];
        }
    }
};


int main() {
    return 0;
}