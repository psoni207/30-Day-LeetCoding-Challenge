class FirstUnique {
    private:
        unordered_map<int,int> umap;
        queue<int> unique;
public:
    FirstUnique(vector<int>& nums) {
        helperSolve(nums);
    }
    
    int showFirstUnique() {
        while(!unique.empty() && umap[unique.front()] != 1){
            unique.pop();
        }
        if(!unique.empty()){
            return unique.front();
        }else{
            return -1;
        }
        
    }
    
    void add(int value) {
        umap[value] += 1;
        if(umap[value] == 1){
            unique.push(value);
        }
    }
    
    void helperSolve(vector<int> &nums){
        for(int i = 0 ; i < nums.size(); ++i){
            umap[nums[i]] += 1;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(umap[nums[i]] == 1){
                unique.push(nums[i]);
            }
        }
    }
    
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */