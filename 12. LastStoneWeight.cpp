class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
     
        int n = stones.size();
		//Take a priority_queue (here a max-heap)
        priority_queue<int> pq;
        
        for(int i = 0; i < n; i++){
            pq.push(stones[i]);
        }
        
        while(pq.size() != 1){
			//Pop the first largest element
            int y = pq.top();
            pq.pop();
            
			//If single element is left, just return that element
            if(pq.empty()){
                return y;
            }
            
			//Pop the second largest element
            int x = pq.top();
            pq.pop();
            
			//Push (y-x) in the priority_queue
            pq.push(y-x);
        }
		
        return pq.top();
    }
};

//Time-Complexity n*log(n), building max heap O(n), push and pop operation, each log(n)
