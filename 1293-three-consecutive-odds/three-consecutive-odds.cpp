class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        
        int n = arr.size();

        //edge case
        if(n<3) return false;

        //first window of size=3
        int prod = 1;

        for(int i=0; i<3; i++){
            prod = prod*arr[i];
        }

        //traversing rest window
        for(int i=3; i<n; i++){

            if(prod % 2 != 0) return true;
            prod = prod/arr[i-3];
            prod = prod*arr[i];
        }

        //checking last window
        return (prod%2 != 0) ? true: false;
    }
};