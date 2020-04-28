class FirstUnique {
    private:
        unordered_map<int,int> freq; //Frequency map to store the freq of each element
        queue<int> unique; //A queue to store the unique elements acc. to their occurence
public:
    FirstUnique(vector<int>& nums) {
        helperSolve(nums);
    }
    
    int showFirstUnique() {
        while(!unique.empty() && freq[unique.front()] != 1){
			//If freq of front of queue is not 1, just remove that from the queue
            unique.pop();
        }
		
        if(!unique.empty()){
            return unique.front();
        }else{
            return -1;
        }
        
    }
    
    void add(int value) {
        freq[value] += 1;
        if(freq[value] == 1){
			//If the element being added occurs for first time, just add it to the unique queue
            unique.push(value);
        }
    }
    
    void helperSolve(vector<int> &nums){
        for(int i = 0 ; i < nums.size(); ++i){
            freq[nums[i]] += 1;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(freq[nums[i]] == 1){
				//If freq of nums[i] is 1, push that in the queue
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