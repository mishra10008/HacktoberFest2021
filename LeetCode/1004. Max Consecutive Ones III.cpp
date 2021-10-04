class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=-1;
        int mx=-1e5,n=nums.size(),z=0,s=0;
      
        for(int i=0;i<n;i++){
            if(!nums[i]){z++;}
            
                while(z>k){
                    if(!nums[s]){z--;}
                    s++;
                }
          
            mx=max(mx,i-s+1);
        }
        
        
        return mx;
    }
};