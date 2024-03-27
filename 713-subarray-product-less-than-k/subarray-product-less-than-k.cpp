class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        //edge case
        if(k==0) return 0;

        int size = nums.size();
        int cnt = 0;
        long long product = 1;

        int i=0, j=0;
        while(j<size){

            product = product*nums[j];

            while(product >= k && i<j){
                product = product/nums[i];
                i++;
            }

            if(product < k){
                cnt+= (j-i+1);
            }
            
            j++;
        }

        return cnt;
    }
};