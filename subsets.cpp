#include "bits/stdc++.cpp"

/*
78. Subsets

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.


*/

class Solution {
public:
    int n = 0; // size of all numbers
    vector<int>* p = nullptr; // pointer to the input vector
    vector<vector<int>> res; // resulting pointer of all subsets (power set)
    // recursive solution (inorder)
    void generateVariations(int digitsLeft, bool includeElement, vector<int> current) {
        // digitsLeft - number of elements left to put in one subset
        // includeElement - 'false'(dont put element in this subset) or 'true' (put tihs element in this subset)
        // current - current subset (which is being updated )

        if (includeElement)
            current.push_back((*p)[n - digitsLeft - 1]); // add new item to the current vector if we need to
        if (digitsLeft == 0) {
            res.push_back(current);
            return;
        }
        generateVariations(digitsLeft - 1, false, current); // left part of subtree (without element)
        generateVariations(digitsLeft - 1, true, current); // right part of subtree (with element)
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        this->n = nums.size();
        this->p = &nums;
        generateVariations(n - 1, false, vector<int>()); // left part of tree
        generateVariations(n - 1, true, vector<int>()); // right part of  tree
        return res;
    }
};
