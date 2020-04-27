class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res;
        int n = nums.size();
        res = findMaxSubarray(nums,0,n-1);
        
        return res;
    }
    
    int findMaxSubarray(vector<int> &nums,int low,int high){
        if(low == high){
            return nums[low];
        }
        
         int mid = (low + high) / 2;
        return findMax(findMaxSubarray(nums,low,mid),
                   findMaxSubarray(nums,mid+1,high),
                   findCrossingSum(nums,low,mid,high)
        );
    }
    
    int findCrossingSum(vector<int> &nums,int low,int mid,int high){
        int sum = 0;
        int leftSum = INT_MIN;
        
        for(int i = mid; i >= low; i--){
            sum += nums[i];
            if(sum > leftSum){
                leftSum = sum;
            }
        }
        
        sum = 0;
        int rightSum = INT_MIN;
        
        for(int i = mid+1; i <= high; i++){
            sum += nums[i];
            if(sum > rightSum){
                rightSum = sum;
            }
        }
        
        return findMax(leftSum + rightSum, leftSum, rightSum);
    }
    
    int findMax(int a,int b,int c){
        return max(max(a,b),c);
    }
};