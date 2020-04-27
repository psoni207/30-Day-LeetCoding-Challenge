/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        
        vector<int> dim = binaryMatrix.dimensions();
        int m = dim[0];
        int n = dim[1];
        
        int col = n;
        for(int row = 0; row < m; ++row){
            while(col > 0 && binaryMatrix.get(row,col-1) == 1){
                col -= 1;
            }
        }
        
        if(col == n){
            col = -1;
        }
        
        return col;
    }
};