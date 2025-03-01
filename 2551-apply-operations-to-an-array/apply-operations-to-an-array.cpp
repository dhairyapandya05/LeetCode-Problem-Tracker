class Solution {
public:
    vector<int> applyOperations(vector<int>& arr) {
        int n=arr.size();
        //Step 01: Applying Operations
        for(int i=0;i<n-1;i++){
            if(arr[i]==arr[i+1]){
                arr[i]*=2;
                arr[i+1]=0;
                i++;
            }
        }
            //Step 02: Move non zero elements to left of array
            int index=0;
            for(int i=0;i<n;i++){
                if(arr[i]!=0){
                    swap(arr[i],arr[index]);
                    index++;
                }
            }
            return arr;
    }
};