/*
78. Subsets

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.


*/

class Solution {
public:
    int n = 0; // size of all numbers
    vector<int>* p = nullptr; // pointer to the input vector
    vector<vector<int>>* res = nullptr; // resulting pointer of all subsets (power set)
    
    // recursive solution (backtracking)
    void generateVariations(int digitsLeft, char newDigit, vector<int> current) {
        // digitsLeft - number of elements let to put in one subset
        // newDigit - '0'(dont put element in this subset) or '1' (put tihs element in this subset)
        // current - current subset
        if (digitsLeft == 0) {
            if (newDigit == '1') current.push_back((*p)[n - 1]); // add last element if '1' is set
            res->push_back(current);
            return;
        }
        if (newDigit == '1') {
            // add new item to the current vector
            current.push_back((*p)[n - digitsLeft - 1]);
        }
        generateVariations(digitsLeft-1, '0', current); // left part of subtree (without element)
        generateVariations(digitsLeft-1, '1', current); // right part of subtree (with element)
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        this->n = nums.size();
        this->p = &nums;
        res = new vector<vector<int>>(); // on heap!
        generateVariations(n - 1, '0', vector<int>()); // left part of backtracking tree
        generateVariations(n - 1, '1', vector<int>()); // right part of backtracking tree
        return *res;
    }
};