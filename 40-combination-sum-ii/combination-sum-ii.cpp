class Solution {

    void solve(vector<int> &arr, int indx, int target, vector<int> output, vector<vector<int>> &ans){

        int n = arr.size();
        //base condn
        if(target == 0){
            ans.push_back(output);
            return;
        }
        else if(indx >= n) return;

        for(int i=indx; i<n; i++){

            if(i>indx && arr[i] == arr[i-1]){
                continue;
            }

            if(arr[i] > target){
                break;
            }

            output.push_back(arr[i]);
            solve(arr, i+1, target-arr[i], output, ans);
            output.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        
        vector<vector<int>> ans;
        vector<int> output;

        sort(arr.begin(), arr.end());
        solve(arr, 0, target, output, ans);
        return ans;
    }
};