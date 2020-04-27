class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int,int> umap;
        
        int n = arr.size();
        for(int i = 0; i < n ; i++){
            if(umap.find(arr[i]) != umap.end()){
                umap[arr[i]] += 1;
            }else{
                umap[arr[i]] = 1;
            }
        }
        
        int count = 0;
        for(int i = 0; i < n; i++){
            if(umap.find(arr[i]+1) != umap.end()){
                count += umap[arr[i]];
                umap[arr[i]] = 0;
            }
        }
        
        return count;
    }
};