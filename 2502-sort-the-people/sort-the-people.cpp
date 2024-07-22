#include<bits/stdc++.h>
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) { 

        //Brute Force---> Via min heap ---> building pairs
        int n = names.size();
        priority_queue<pair<int,string>> pq;

        for(int i=0; i<n; i++){
            pq.push(make_pair(heights[i], names[i]));
        }

        vector<string> ans;
        while(!pq.empty()){

            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
        
    }
};