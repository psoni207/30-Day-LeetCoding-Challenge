class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> myStack;
    int minNum;
    int topPtr = -1;
	
    MinStack() {
        minNum = INT_MAX;
    }
    
    void push(int x) {
        myStack.push_back(x);
        if(x < minNum){
            minNum = x;
        }
        topPtr += 1;
    }
    
    void pop() {
        int num = myStack[topPtr];
        myStack.pop_back();
        topPtr -= 1;
		
		//Check if popped element(num) is equal to minNum
        if(num == minNum){
            findMinAgain();
        }
    }
    
    int top() {
        return myStack[topPtr];
    }
    
    int getMin() {
        return minNum;
    }
    
    void findMinAgain(){
        minNum = INT_MAX;
        for(int i = 0; i <= topPtr; i++){
            if(myStack[i] < minNum){
                minNum = myStack[i];
            }
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */