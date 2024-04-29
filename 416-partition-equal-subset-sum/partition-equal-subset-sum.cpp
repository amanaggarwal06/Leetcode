
//grid formation
    int t[201][20000] = {0};
class Solution {

    void subsetsum(vector<int> &nums, int n, int s){

        //initialisation
        for(int i=0; i<=n; i++){
            for(int j=0; j<=s; j++){

                if(i==0){
                    t[i][j] = false;
                }

                if(j==0){
                    t[i][j] = true;
                }
            }
        }

        for(int i=1; i<n+1; i++){
            for(int j=1; j<s+1; j++){

                if(nums[i-1] <= j){
                    //include
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                }
                else{
                    //exclude

                    t[i][j] = t[i-1][j];
                }
            }
        }
    }
public:
    bool canPartition(vector<int>& nums) {
        
        int sum = 0, n = nums.size();
        for(int i=0; i<n; i++){
            sum += nums[i];
        }

        //edge case
        if(sum % 2 != 0){
            return false;
        }

        int s = sum/2;
        memset(t, -1, sizeof(t));

        subsetsum(nums, n, s);
        return t[n][s];
    }
};