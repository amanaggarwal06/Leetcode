class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        unordered_map<char, int> mp;
        int src = s.size(), target = p.size();

        for(int i=0; i<target; i++){
            mp[p[i]]++;
        }

        vector<int> ans;
        int l=0, r=0;
        int distinct_cnt = mp.size();

        while(r<src){

            //adding element in the window
            if(mp.find(s[r]) != mp.end()){
                mp[s[r]]--;

                if(mp[s[r]] == 0){
                    distinct_cnt--;
                }
            }

            if(r-l+1 == target){

                if(distinct_cnt == 0){
                    ans.push_back(l);
                }

                //sliding window with removing the left element and that element count from the window as well

                if(mp.find(s[l]) != mp.end()){

                    mp[s[l]]++;

                    //if it's a first elemnt
                    if(mp[s[l]] == 1){
                        distinct_cnt++;
                    }
                }
                l++;
            }

            r++;
        }

        return ans;
    }
};