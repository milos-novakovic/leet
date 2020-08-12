#include "bits/stdc++.cpp"

class Solution {
public:
    vector<string>* res = nullptr;
    int numberOfPairs = 0; 	// given number of total pairs of parentheses
    void helper(string curr, int numOfOpen, int numOfClosed) {
        // numOfOpen := number of open parentheses '(' 
        // numOfClosed := number of close parentheses ')' 
        // curr := string that is going to be inserted in the resulting vector *p
        if ((numOfOpen + numOfClosed) == 2 * numberOfPairs) {
            // found one solution, remember it and return
            res->push_back(curr);
            return;
        }
        if (numOfOpen == numberOfPairs) {
            // only room for close parentheses
            helper(curr + ')', numOfOpen, numOfClosed + 1);
        }
        else {
            // room for open parentheses
            helper(curr + '(', numOfOpen + 1, numOfClosed);
            if (numOfOpen > numOfClosed) {
                helper(curr + ')', numOfOpen, numOfClosed + 1);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        res = new vector<string>;
        numberOfPairs = n;
        helper("(", 1, 0);  // always must start with open parentheses
        return *res;
    }
    ~Solution()
    {
        delete res;
    }
};