class Solution {
public:
    int partition_algo(vector<int>& nums, int l,int r){
        int p=nums[l];
        int i=l+1;
        int j=r;
        while(i<=j){
            if(nums[i]<p and nums[j]>p){
                swap(nums[i],nums[j]);
                j--;
                i++;
            }
            if(nums[i]>=p){
                i++;
            }
            if(nums[j]<=p){
                j--;
            }
        }
        swap(nums[l],nums[j]);
        return j;// pivot element is at jth index
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0,right=n-1;
        int pivotidx=0;
        while(true){
            pivotidx=partition_algo(nums,left,right);
            if(pivotidx==k-1){
                break;
            }
            else if(pivotidx>k-1){
                right=pivotidx-1;
            }
            else if(pivotidx<k-1){
                left=pivotidx+1;
            }
        }
        return nums[pivotidx];
    }
};