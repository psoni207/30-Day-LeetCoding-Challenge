class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        int max_jump = 0;
        
        for(int i = 0; i < n ; ++i){
            if(i > max_jump || max_jump >= n-1){
                break;
            }
            
			//Just update max_jump that can be jumped from each index
            max_jump = max(max_jump, i + nums[i]);
        }
        
        return (max_jump >= n - 1 ? true : false);
    }
};