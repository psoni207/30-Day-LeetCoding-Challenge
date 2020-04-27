class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int res = 0;
		//XOR each element, as a^a = 0, so you'll be left with only non-repeated element
        for(int i = 0; i < nums.size(); i++){
            res ^= nums[i];
        }
        
        return res;
    }
};