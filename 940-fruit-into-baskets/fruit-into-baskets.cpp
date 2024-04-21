class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;

        int n = fruits.size();
        int l=0, r = 0, maxi = 0;

        while(r < n){

            int curr = fruits[r];

            if(mp.find(curr) == mp.end()){
                mp[curr] = 1;
            }
            else{
                mp[curr]++;
            }

            while(mp.size() > 2){

                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0){
                    mp.erase(fruits[l]);
                }

                l++;
            }

            if(mp.size() <= 2){
                maxi = max(maxi, r-l+1);
            }

            r++;
            
        }

        return maxi;
    }
};