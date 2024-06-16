class Solution {

    void subset(vector<int> &nums, int indx, vector<int> output, set<vector<int>> &st){

        //base condn
        if(indx >= nums.size()){

            sort(output.begin(), output.end());
            st.insert(output);
            return;
        }

        //exclude
        subset(nums, indx+1, output, st);

        //include
        output.push_back(nums[indx]);
        subset(nums, indx+1, output, st);
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> ans; vector<int> output;
        set<vector<int>> st;

        subset(nums, 0, output, st);

        for(auto it: st){
            ans.push_back(it);
        }

        return ans;
    }
};