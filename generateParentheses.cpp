#include "bits/stdc++.cpp"

class Solution {
public:
    vector<string>* res = nullptr;
    int numOfPairs = 0; 	// given number of total pairs of parentheses
    void helper(string curr, int numOfOpen, int numOfClosed) {
        // numOfOpen := number of open parentheses '(' 
        // numOfClosed := number of close parentheses ')' 
        // curr := string that is going to be inserted in the resulting vector *p
        if ((numOfOpen + numOfClosed) == 2 * numOfPairs) {
            // found one solution, remember it and return
            res->push_back(curr);
            return;
        }
        if (numOfOpen == numOfPairs) {
            // only room for close parentheses; example curr = "(((" and numOfOpen=3 numOfPairs=3
            helper(curr + ')', numOfOpen, numOfClosed + 1);
        }
        else {
            // here numOfPairs is bigger than numOfOpen, thus we can insert one more open parentheses
            helper(curr + '(', numOfOpen + 1, numOfClosed);
            if (numOfOpen > numOfClosed) {
                // if we have more '(' than ')' we can have one more ')'
                helper(curr + ')', numOfOpen, numOfClosed + 1);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        res = new vector<string>;
        numOfPairs = n;
        helper("(", 1, 0);  // always must start with open parentheses
        return *res;
    }
    ~Solution()
    {
        delete res;
    }
};
