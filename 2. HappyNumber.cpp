class Solution {
public:
    bool isHappy(int n) {
        
        if (n == 1 || n == 7) 
            return true;
        
        int sum = n, x = n; 

        while(sum > 9) {
            
            sum = findSum(x);
            
            if (sum == 1 || sum == 7) 
                return true; 
            x = sum; 
        }
        
        return false;
    }
    
    int findSum(int x){
        
        int sum = 0;
        while (x > 0) { 
            int d = x%10; 
            sum += d*d; 
            x/=10;
        }
        
        return sum;
    }
};