# [74. Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/description/)

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

 ## Solution
 I was trying to find a row's first index which its value is less than the target and next row's first element is greater than target, so I applied the the insert search to find specific index.
 After find the row which containing the target we perform binary search at the found row. However, there are sevearl corner cases
 1. if we found the insert index is zero which mean that the matrix[0][0] is greater than or equal to the target.
 2. The found row's first index is equal to the target. Because we assumming we performing a binary search at [found index - 1]
 ```cpp
 class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // we need to find the index in rows first
        int rowl = 0;
        int rowr = matrix.size();
        while(rowl < rowr) {
            int rowMid = rowl + (rowr - rowl) / 2;
            if (matrix[rowMid][0] < target) {
                rowl = rowMid + 1;
            } else {
                rowr = rowMid;
            }
        }
    
        if (rowl < matrix.size() && matrix[rowl][0] == target) return true;
        if (rowl == 0) return matrix[0][0] == target;

        
        int colL = 0;
        int colR = matrix[0].size() - 1;
        while(colL <= colR) {
            int colMid = colL + (colR - colL) / 2;
            if (matrix[rowl-1][colMid] < target) {
                colL = colMid + 1;
            } else if (matrix[rowl-1][colMid] == target){
                return true;
            } else {
                colR = colMid - 1;
            }
        }

        return false;
    }
};
 ```
