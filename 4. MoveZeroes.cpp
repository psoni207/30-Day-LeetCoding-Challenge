class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = n-1; i >= 0; i--){
            if(nums[i] == 0){
                shiftLeft(nums,i,n);
            }
        }
    }
    
    void shiftLeft(vector<int>& nums, int ind, int n){
        int i;
        for( i = ind + 1; i < n && nums[i]!=0; i++ ){
            nums[i-1] = nums[i];
        }
        nums[i-1]=0;
    }
};


void pushZerosToEnd(int arr[], int n) 
{ 
    int count = 0;
    for (int i = 0; i < n; i++){
		if (arr[i] != 0) 
            arr[count++] = arr[i];
	}
         
    while (count < n){
		arr[count++] = 0;
	} 
	
}

void moveZerosToEnd(int arr[], int n) 
{ 
    // Count of non-zero elements 
    int count = 0; 
  
    // Traverse the array. If arr[i] is non-zero, then 
    // swap the element at index 'count' with the 
    // element at index 'i' 
    for (int i = 0; i < n; i++) 
        if (arr[i] != 0) 
            swap(arr[count++], arr[i]); 
}