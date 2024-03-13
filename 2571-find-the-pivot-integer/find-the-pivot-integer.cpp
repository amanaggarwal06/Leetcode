class Solution {
public:
    int pivotInteger(int n) {
        
        int total_sum = n*(n+1)/2;

        for(int mid =1; mid<=n; mid++ ){

            int sum1 = (mid)*(mid+1)/2;
            int sum2 = total_sum - sum1 + mid;

            if(sum1 == sum2) return mid;
        }

        return -1;
    }
};