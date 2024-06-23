class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size(), n2 = nums2.size();
        int left = (n1 + n2 + 1)/2;
        int total_len = n1 + n2;

        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int low = 0, high = n1;

        while(low <= high){

            int mid1 = low + (high-low)/2;
            int mid2 = left - mid1;

            int l1 = -1, l2 = -1;
            l1 = (mid1 - 1) >= 0 ? nums1[mid1-1] : INT_MIN;
            l2 = (mid2 - 1) >= 0 ? nums2[mid2-1] : INT_MIN;

            int r1 = INT_MAX, r2 = INT_MAX;
            r1 = (mid1 < n1) ? nums1[mid1] : INT_MAX;
            r2 = (mid2 >=0 && mid2 < n2) ? nums2[mid2] : INT_MAX;

            //valid indx
            if(l1 <= r2 && l2 <= r1){
                if(total_len % 2 == 1){
                    return max(l1,l2);
                }
                else{
                    //even len

                    return ((double)(max(l1,l2) + min(r1,r2))/2.0);
                }
            }

            if(l1 > r2){
                high = mid1 - 1;
            }
            else{
                low = mid1 + 1;
            }



        }
        return -1;
    }
};