class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int n = nums.size(), l=0, r=0, sum = 0;
        double maxavg = INT_MIN;

        sum  = sum + 0.0;
        while(r<n){

            sum += nums[r];

            if(r-l+1 == k){

                double avg = 1.0*sum/k;
                if(avg > maxavg){
                    maxavg = avg;
                }

                //slide the window
                sum -= nums[l];
                l++;
            }

            r++;

        }

        return maxavg;
    }
};