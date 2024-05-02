// class Solution {
// public:
//     int findMaxK(vector<int>& nums) {
        
//         unordered_map<int, int> mp; int maxi = INT_MIN; int ans = -1;

//         for(int i=0; i<nums.size(); i++){

//             maxi = max(maxi, nums[i]);
//             maxi = -1*maxi;

//             if(mp.find(maxi) != mp.end()){
//                ans = max(ans, -1*maxi);
//             }
//             mp[nums[i]]++;
//             maxi = -1*maxi;
//         }

        

//         return ans;
//     }
// };
class Solution 
{
public:
    int findMaxK(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int low=0, high=nums.size()-1;
        
        while(low < high)
        {
            if((nums[low] + nums[high]) == 0)
            {
                return  nums[high];
            }
            
            else if((nums[low] + nums[high]) < 0)
                low++;
            
            else high--;
        }
        return -1;
    }
};