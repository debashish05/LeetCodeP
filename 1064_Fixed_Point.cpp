// Read question carefully. In this question it was given, the elements are distinct, but you missed that. 

class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        
        int low=0,high=arr.size()-1;
        int ans=-1,mid=0;
        
        while(low<=high)
        {
            mid=low+(high-low)/2;
            
            if(mid==arr[mid])ans=mid;
            
            if(mid>arr[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            
        }
        return ans;
    }
};



