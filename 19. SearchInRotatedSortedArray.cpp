class Solution {
    private:
        int n;
public:
    int search(vector<int>& nums, int target) {
        n = nums.size();
        int pivot = findPivot(nums,0,n-1);
        
        if(pivot == -1){
            return binSearch(nums,0,n-1,target);
        }
        
        if(target == nums[pivot]){
            return pivot;
        }
        
        if(target <= nums[n-1]){
            return binSearch(nums,pivot+1,n-1,target);
        }else{
            return binSearch(nums,0,pivot-1,target);
        }
        
        
    }
    
    int findPivot(vector<int> &nums, int low, int high){
        
        if(low <= high){
            int mid = (low + high) / 2;
            
            if(mid != n-1 && nums[mid] > nums[mid+1]){
                return mid;
            }
            if(mid != 0 && nums[mid-1] > nums[mid]){
                return mid-1;
            }
            
            if(nums[low] >= nums[mid]){
                return findPivot(nums,low,mid-1);
            }
            
            return findPivot(nums,mid+1,high);
        }
        return -1;
    }
    
    
    int binSearch(vector<int> &nums,int low, int high, int target){
        
        while(low <= high){
            int mid = (low + high) / 2;
            
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                return binSearch(nums,low,mid-1,target);
            }else{
                return binSearch(nums,mid+1,high,target);
            }
        }
        
        return -1;
    }
    
    
};