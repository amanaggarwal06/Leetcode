class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        int cnt = 1, max_cnt = 1, freq_max_cnt = 1;
        sort(nums.begin(), nums.end());

        for(int i=1; i<nums.size(); i++){

            if(nums[i] == nums[i-1]){
                cnt++;
                if(cnt > max_cnt){
                    max_cnt = cnt;
                    freq_max_cnt = 1;
                }
                else if(cnt == max_cnt){
                        freq_max_cnt++;
                    }
            }
            else{
                cnt = 1;
                if(cnt == max_cnt){
                    freq_max_cnt++;
                }
            }

            
        }

        return max_cnt*freq_max_cnt;
    }
};