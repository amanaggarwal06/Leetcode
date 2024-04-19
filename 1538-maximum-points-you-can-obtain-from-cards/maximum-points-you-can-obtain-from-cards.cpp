class Solution {
public:
    int maxScore(vector<int>& points, int k) {
        
        int n = points.size();
        int sum = 0, r = n-1, maxi = sum;

        for(int i=0; i<k; i++){
            sum += points[i];
        }

        maxi = max(maxi, sum);
        int l = k-1;

        for(int i=k-1; i>=0; i--){
            sum -= points[i];
            sum += points[r];
            r--;

            maxi = max(maxi, sum);
        }

        return maxi;

    }
};