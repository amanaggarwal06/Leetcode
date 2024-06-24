typedef pair<int, int> pp;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){

            mp[nums[i]]++;
        }

        priority_queue<pp, vector<pp>, greater<pp>> pq;

        for(auto it: mp){
            pq.push({it.second, it.first});

            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};