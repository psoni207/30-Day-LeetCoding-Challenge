class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        
        if(m == 0 || n == 0){
            return 0;
        }
        
        int res = 0;
        while(m && n){
			
			//Find the msb bits of m and n
			
            int msb1 = findMSB(m);
            int msb2 = findMSB(n);
            
			//If they are not same just break
			//This just mean the sequence is like (0001xxxx ... 001xxxxx)
			//Assuming the bit differs(d >= 1), here d = 1
			//The sequence will contain starting from 0001xxxx will go upto 001xxxxx
			//This would finally result in 0 as every bit toggles in between these
            if( msb1 !=  msb2){
                break;
            }
            
			//Add value to the res
            res |= (1 << msb1);
            
			//Unset that bit-position in the m and n
            m -= (1 << msb1);
            n -= (1 << msb2);
        }
        
        return res;
        
        
    }
    
    int findMSB(int a){
        
        int msb = -1;
        while(a){
            msb += 1;
            a = a >> 1;
        }
        return msb;
    }
};