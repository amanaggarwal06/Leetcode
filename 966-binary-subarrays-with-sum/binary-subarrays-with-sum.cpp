class Solution {

    int func(vector<int> &nums, int target){

        if(target < 0) return 0;

        int n= nums.size(), l=0, r=0, sum=0, cnt=0;

        while(r<n){

            sum += nums[r];

            while(sum > target){
                sum -= nums[l];
                l++;
            }

            
            cnt += (r-l+1);
            r++;
        }

        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return ( func(nums, goal) - func(nums, goal-1) );

    }
};