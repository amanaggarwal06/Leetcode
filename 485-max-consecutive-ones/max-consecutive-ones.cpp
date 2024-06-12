class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int cnt = 0, maxi = 0;

        int i=0, j=0, n = nums.size();

        while(j<n){

            if(nums[j] == 1){
                if(j==0 || j == i+1){
                    cnt++;
                }
                else{
                    cnt = 1;
                }
                 i=j;
            }
            maxi = max(maxi, cnt);
            j++;
        }
        return maxi;

    }
};