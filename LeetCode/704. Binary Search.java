class Solution {
    public int search(int[] nums, int target) {
        
        int li = 0;
        int hi = nums.length - 1;
        int mi = (li + hi)/2;
        
        while(li<=hi){
            if(nums[mi]==target){
                return mi;
                // break;
            }
            else if(nums[mi] < target){
                li = mi + 1;
            }
            else{
                hi = mi - 1; 
            }
            mi = (li + hi)/2;        
        }

            return -1;
    }
}
