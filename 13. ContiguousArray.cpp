class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> umap;
        
        int res = 0,currSum=0;
        int n = nums.size();
        
        for(int i = 0;i < n; i++){
			//Take 0 as -1, and 1 as 1
			//And the problem reduces to finding the max-size subarray with sum 0
            currSum += (nums[i]==0) ? -1 : 1;
            
            if(currSum == 0){
                if(res < i+1)
                    res = i+1;
            }
            else if(umap.find(currSum) != umap.end()){
				//If that sum has already occurred, that means there is a subarray having sum 0
				//Find the previous index having that sum, and update res
                if(res < i - umap[currSum]){
                    res = i - umap[currSum];
                }
            }
            else{
				//Else save this sum with its index
                umap[currSum] = i;
            }
        }
        return res;
    }
};