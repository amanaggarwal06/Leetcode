class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size(), l=0, r=0, maxlen=0, zeroes = 0;

        while(r<n){

            if(nums[r] == 0) zeroes++;

            if(zeroes > 1){
                if(nums[l] == 0) zeroes--;
                l++;
            }

            if(zeroes <= 1){
                maxlen = max(maxlen, r-l+1);
            }
            

            r++;
        }

        return maxlen == 0 ? 0 : maxlen-1;
    }
};