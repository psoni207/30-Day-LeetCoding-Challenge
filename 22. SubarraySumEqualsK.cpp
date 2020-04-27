class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        int currsum = 0;
        int count = 0;
        
        unordered_map<int,int> umap;
        //umap[0] = 1;
        
        for(int i = 0; i < n; i++){
            currsum += nums[i];
            
			//If currsum equals k, increment count
            if(currsum == k){
                count++;
            }
            
			//Check if (currsum - k) exists in the map, if so add map-value to count
			//As we are traversing the array and keeping the prefix sum
			//So if at any index currsum = k + some_val, if ( (currsum - k) = some_val ) has already occurred
			//That means we have come accross an subarray whose sum is k
            if(umap.find(currsum - k) != umap.end()){
                count += umap[currsum - k];
            }
			
			//Update map
            umap[currsum]++;
        }
        
        
        return count;
        
    }
};