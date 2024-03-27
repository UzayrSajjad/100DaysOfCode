class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k<=1) {
            return 0;
        }
        
        int product = 1;
        int count = 0;
        int j = 0;

        for(int i=0; i<n; i++) {
            product *= nums[i];
            while(product >= k) {
                product /= nums[j];
                j++;
            }
            count += i-j+1;
        }
        return count;
    }
};
