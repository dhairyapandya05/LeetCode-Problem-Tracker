class Solution {
public:
    bool binarySearch(vector<int>& invalidIdx,vector<int>& query){
        int low=query[0]+1;
        int high=query[1];
        int s=0,e=invalidIdx.size()-1;
        while(s<=e){
            int mid=(s+(e-s)/2);
            if(invalidIdx[mid]<low) s=mid+1;
            else if(invalidIdx[mid]>high) e=mid-1;
            else{
                return true;
            }
        }
        return false;

    }
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> invalidIdx;
        int m=queries.size();
        int j=1;
        while(j<n){ 
            if(nums[j]%2==nums[j-1]%2){
                invalidIdx.push_back(j);
            }
            j++;
        }
        vector<bool> result(m,false);

        for(int i=0;i<m;i++){
            bool r1=binarySearch(invalidIdx,queries[i]);
             result[i]=!r1;
        }
        return result;
    }
};
