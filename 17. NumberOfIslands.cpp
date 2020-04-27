class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    count += 1;
                    solveIsland(grid,i,j);
                }
            }
        }
        return count;
    }
    
    void solveIsland(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ){
            return;
        }
        if(grid[i][j] == '0'){
            return;
        }
        
        grid[i][j] = '0';
        solveIsland(grid,i-1,j);
        solveIsland(grid,i+1,j);
        solveIsland(grid,i,j-1);
        solveIsland(grid,i,j+1);
    }
};