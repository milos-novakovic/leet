/*
Given a list of daily temperatures T, return a list such that, for each day in the input, 
tells you how many days you would have to wait until a warmer temperature. 
If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
*/

/*
(leetcode)
Here is a worked example of the contents of the stack as we work through T = [73, 74, 75, 71, 69, 72, 76, 73]
 in reverse order, at the end of the loop (after we add T[i]). 
 For clarity, stack only contains indices i, but we will write the value of T[i] beside it in brackets, such as 0 (73).

When i = 7, stack = [7 (73)]. 				ans[7] = 0.
When i = 6, stack = [6 (76)]. 				ans[6] = 0.
When i = 5, stack = [5 (72), 6 (76)]. 			ans[5] = 1.
When i = 4, stack = [4 (69), 5 (72), 6 (76)]. 		ans[4] = 1.
When i = 3, stack = [3 (71), 5 (72), 6 (76)]. 		ans[3] = 2.
When i = 2, stack = [2 (75), 6 (76)]. 			ans[2] = 4.
When i = 1, stack = [1 (74), 2 (75), 6 (76)]. 		ans[1] = 1.
When i = 0, stack = [0 (73), 1 (74), 2 (75), 6 (76)]. 	ans[0] = 1.

*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
		// stack contains the indices of the vector T, but sorted (smallest temperature is on the top of the stack)
		stack<int> s;
		// resulting vecor is same size so we will allocate only T.size() length
		vector<int> res(T.size(),0);
		for (int i = T.size()-1; i >= 0; i--){
			// start from the back of T
			while (!s.empty() && T[i] >= T[s.top()])
				// we dont care for smaller temperatures from the i-th element to the last, so we remove them from stack
				s.pop();
			// if stack is empty that means we dont have a higer temperature from the i-th element till the last
			res[i] = s.empty() ? 0 : s.top() - i;
			// push the i-th element to be the candidate for the next iteration
			s.push(i);
		}
		return res;
    }
};
