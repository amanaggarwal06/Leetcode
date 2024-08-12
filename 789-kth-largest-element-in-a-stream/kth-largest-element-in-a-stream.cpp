class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> minh;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int i=0; i<nums.size(); i++){

            minh.push(nums[i]);
            if(minh.size() > k){
                minh.pop();
            }
        }
    }
    
    int add(int val) {
        
        minh.push(val);
        if(minh.size() > K){
            minh.pop();
        }

        return minh.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */