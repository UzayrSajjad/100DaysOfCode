class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int result = -1;
        
        for (int &i : nums) {
            for (int &j : nums) {
                // If there exists a number j such that i is the negative of j
                if (i == -j) {
                    // Update the answer to the maximum of current ans and absolute value of i
                    result = max(result, abs(i));
                }
            }
        }

        return result;
    }
};
