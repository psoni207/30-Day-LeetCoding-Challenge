class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> A,B;
        
        int n = S.size();
        int m = T.size();
        
        int i = 0;
        while(i < n){
            if(S[i] == '#'){
                if(!A.empty()){
                    A.pop();
                }
            }else{
                A.push(S[i]);
            }
            i++;
        }
        
        i = 0;
        while(i < m){
            if(T[i] == '#'){
                if(!B.empty()){
                    B.pop();
                }
            }else{
                B.push(T[i]);
            }
            i++;
        }
        
        if(A.size() == B.size()){
            while(!A.empty()){
                if(A.top() == B.top()){
                    A.pop();
                    B.pop();
                }else{
                    return false;
                }
            }
        }else{
            return false;
        }
        
        return true;
    }
};
