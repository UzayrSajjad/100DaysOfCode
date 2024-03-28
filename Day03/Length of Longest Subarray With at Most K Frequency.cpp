class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> mp; // Map to store frequency of elements
        
        int i = 0; // Left pointer of the sliding window
        int j = 0; // Right pointer of the sliding window
        int result = 0; // Variable to store the maximum subarray length
        
        // Sliding window technique
        while(j < n) {
            // Update frequency of nums[j] in the map
            mp[nums[j]]++;
            
            // If frequency of nums[j] exceeds k, move the left pointer to shrink the window
            while(i < j && mp[nums[j]] > k) {
                mp[nums[i]]--; // Decrease the frequency of nums[i]
                i++; // Move the left pointer
            }
            
            // Update the result with the maximum subarray length found so far
            result = max(result, j - i + 1);
            
            // Move the right pointer to expand the window
            j++;
        }
        
        // Return the maximum subarray length
        return result;
    }
};
