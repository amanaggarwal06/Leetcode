class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        for(int i=0; i<intervals.size(); i++){

            int start = intervals[i][0], end = intervals[i][1];

            if(ans.empty() || ans.back()[1] < start){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1], end);
            }
        }

        return ans;
    }
};