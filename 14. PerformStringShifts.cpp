class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int n = shift.size();
        int left=0,right=0;
        
		//Calculate total left and right shifts
        for(int i = 0; i < n; i++){
            if(shift[i][0] == 0){
                left += shift[i][1];
            }else{
                right += shift[i][1];
            }
        }
        
        int len = s.size();
		
		//Acc. to value of left and right shifts, calculate overall shift either in left or right direction
        if(left > right){
            left = left - right;
            left %= len;
            leftShift(s,left,len);
        }else{
            right = right - left;
            right %= len;
            rightShift(s,right,len);
        }
        
        return s;
        
    }
    
    void leftShift(string &s,int left,int len){
        string temp = "";
        for(int i = 0; i < left; i++){
            temp += s[i];
        }
        
        for(int j = left; j < len; j++){
            s[j-left] = s[j];
        }
        
        for(int i = 0, j = len - left; j < len; j++, i++){
            s[j] = temp[i];
        }
    }
    
    void rightShift(string &s, int right,int len){
        string temp = "";
        for(int i = len - right ; i < len; i++){
            temp += s[i];
        }
        
        for(int i = len - 1, j = len - right -1; j >= 0; j--, i--){
            s[i] = s[j];
        }
        
        for(int i = 0; i < right; i++){
            s[i] = temp[i];
        }
    }
};