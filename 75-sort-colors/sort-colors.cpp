class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int size = nums.size(), mid = 0;
        int low = mid, high = size-1;

        while(mid < size && low <= mid && mid <= high){

            if(nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high--;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
        }

        return ;
    }
};