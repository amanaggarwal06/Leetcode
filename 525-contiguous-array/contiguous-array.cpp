// class Solution {
// public:
//     int findMaxLength(vector<int>& nums) {
        
//         int maxi = 0, cnt1 = 0, cnt0 = 0;
//         int size = nums.size();
//         for(int i=0; i<size; i++){

//             cnt1 = 0; cnt0 = 0;
//             for(int j=i; j<size; j++){
                
//                 //now check for 1's equlas 0's
//                 if(nums[j] == 0) cnt0++;
//                 else cnt1++;

//                 if(cnt1 == cnt0) {
//                     maxi = max(maxi, j-i+1);
//                 }

//             }
//         }

//         return maxi;
//     }
// };

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
		vector<int> arr(2*nums.size() + 1, INT_MIN);
		arr[nums.size()] = -1;
        int maxLen = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 0 ? -1 : 1);
			if (arr[sum + nums.size()] >= -1)  maxLen = max(maxLen, i - arr[sum + nums.size()]);
			else  arr[sum + nums.size()] = i; 
        }
        return maxLen;
    }
};