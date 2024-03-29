class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int maxi = *max_element(nums.begin(), nums.end());

        int cnt = 0, j=0;
        long long  ans = 0;

        for(int i=0; i<nums.size(); i++){

            if(nums[i] == maxi){
                cnt++;
            }

            for(; cnt>=k && j<=i; j++){
                if(nums[j] == maxi) cnt--;
            }

            ans += j;
        }

        return ans;

    }
};