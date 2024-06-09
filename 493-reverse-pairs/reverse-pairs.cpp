class Solution {

    int merge(vector<int> &arr, int st, int mid, int end){

        vector<int> ans; int cnt = 0;
        int low = st, high = mid+1;

        //checking arr[low] > 2*arr[high] then inc the count

        while(low <= mid && high <= end){

            long long secondEle = arr[high];
            secondEle *= 2;
            if(arr[low] > secondEle){
                cnt += (mid-low+1);
                high++;
            }
            else{
                low++;
            }
        }

        int i = st, j = mid+1;

        while(i<= mid && j<= end){

            if(arr[i] < arr[j]){
                ans.push_back(arr[i++]);
            }
            else{

                // int temp = i;

                // while(temp <= mid){
                //     long long secondEle = 2*arr[j];
                //     if(arr[temp] > secondEle){
                //         cnt = cnt + (mid-temp+1);
                //         break;
                //     }
                //     temp++;
                // }
                ans.push_back(arr[j++]);
            }
        }

        while(i<=mid){
            ans.push_back(arr[i++]);
        }

        while(j<=end){
            ans.push_back(arr[j++]);
        }

        for(int i=st; i<= end; i++){
            arr[i] = ans[i-st];
        }


        return cnt;
    }

    int mergeSort(vector<int> &arr, int st, int end){

        //base condn
        if(st == end) return 0;

        int cnt = 0; int mid = st + (end-st)/2;

        cnt += mergeSort(arr, st, mid);
        cnt += mergeSort(arr, mid+1, end);

        cnt += merge(arr, st, mid, end);
        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        
        int cnt = 0, n = nums.size();
        
        return mergeSort(nums, 0, n-1);
    }
};