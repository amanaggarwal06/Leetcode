class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int ele1 = INT_MIN, ele2 = INT_MIN;
        int cnt1 = 0, cnt2 = 0, n = nums.size();
        int condn = n/3;

        for(int i=0; i<n; i++){

            if(cnt1 == 0 && nums[i] != ele2){
                cnt1 = 1; ele1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i] != ele1){
                cnt2 = 1; ele2 = nums[i];
            }
            else if(nums[i] == ele1) cnt1++;
            else if(nums[i] == ele2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }

        }

        vector<int> ans;

        //verification
        cnt1 = 0; cnt2 = 0;

        for(int i=0; i<n; i++){

            if(nums[i] == ele1) cnt1++;
            else if(nums[i] == ele2) cnt2++;
        }

        if(ele1 != INT_MIN && cnt1 > condn) ans.push_back(ele1);
        if(ele2 != INT_MIN && cnt2 > condn) ans.push_back(ele2);

        return ans;
    }
};