class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int size = nums.size();
        int dip_indx = -1;

        //finding dip indx
        for(int i = size-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                dip_indx = i;
                break;
            }
        }

        //edge case
        if(dip_indx == -1){
            sort(nums.begin(), nums.end());
            return;
        }


        for(int i = size-1; i> dip_indx; i--){
            if(nums[i] > nums[dip_indx]){
                swap(nums[i], nums[dip_indx]);
                break;
            }
        }

        reverse(nums.begin() + dip_indx + 1, nums.end());
        return;
    }
};