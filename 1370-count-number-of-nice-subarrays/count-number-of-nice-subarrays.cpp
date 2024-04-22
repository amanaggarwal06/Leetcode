class Solution {

    int func(vector<int> &nums, int k){

        if(k<0) return 0;
        int l=0, r=0, oddnums=0, cnt= 0;

        while(r<nums.size()){

            if(nums[r] % 2 != 0){
                oddnums++;
            }

            while(oddnums > k){

                if(nums[l] % 2 != 0){
                    oddnums--;
                }
                l++;
            }

            if(oddnums <= k){
                cnt = cnt + (r-l+1);
            }
            r++;
        }

        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return func(nums, k) - func(nums, k-1);
    }
};