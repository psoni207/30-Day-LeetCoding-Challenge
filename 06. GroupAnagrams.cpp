class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        unordered_map<string,vector<string> > umap;
        
        int n = strs.size();
        for(int i = 0; i < n; i++){
            string str = strs[i];
			//sort the string and put it in a map with the original string
			//here the map-value is a vector of string
            sort(str.begin(),str.end());
            umap[str].push_back(strs[i]);
        }
        
        unordered_map<string,vector<string> >::iterator it;
        for(it = umap.begin(); it!= umap.end(); it++){
			
            res.push_back(it->second);
        }
        
        return res;
    }
};