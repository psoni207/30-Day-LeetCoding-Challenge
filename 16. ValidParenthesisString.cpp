class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<int,char> > st,stars;
        int n = s.size();
        
        int i = 0;
        
        while(i < n){
            if(s[i] == '('){
                st.push({i,'('});
            }else if(s[i] == '*'){
                stars.push({i,'*'});
            }else{
                if(!st.empty()){
                    st.pop();
                }else if(!stars.empty()){
                    stars.pop();
                }else{
                    return false;
                }
            }
            i++;
        }
        
        if(st.empty()){
            return true;
        }else{
            while(!st.empty() && !stars.empty()){
                if(stars.top().first > st.top().first){
                    stars.pop();
                    st.pop();
                }else{
                    stars.pop();
                }    
            }
            
        }
        
        if(st.empty()){
            return true;
        }else{
            return false;
        }
        
        
        
    }
};