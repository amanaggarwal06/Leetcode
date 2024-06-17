class Solution {

    void solve(vector<int> &nums, int indx, vector<int> output, vector<vector<int>> &ans){

        //base condn
        if(indx >= nums.size()){
            ans.push_back(output);
            return;
        }
        
        //adding subset to my ans
        ans.push_back(output);

        for(int i=indx; i<nums.size(); i++){

            if(i>indx && nums[i] == nums[i-1]){
                continue;
            }

            output.push_back(nums[i]);
            solve(nums, i+1, output, ans);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> output;

        solve(nums, 0, output, ans);
        return ans;
    }
};