class Solution {
public:
    double myPow(double x, int n) {
        
        double ans = 1.0000;
        long long nn = n;
        if(n<0){
            nn = -1*nn;
        }

        while(nn>0){

            if(nn%2 == 0){
                x = x*x;
                nn = nn/2;
            }
            else{
                ans = ans*x;
                nn = nn - 1;
            }
        }

        if(n<0){
            ans = 1.00/ans;
        }
        return ans;

    }
};