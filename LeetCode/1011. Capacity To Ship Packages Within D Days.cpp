class Solution {
public:
    int maxElement(vector<int>& weights, int n){
        int maxEle=weights[0];
        for(int i=1; i<n; i++)
            maxEle=max(maxEle, weights[i]);
        return maxEle;
    }
    int sumOfElements(vector<int>& weights, int n){
        int sum=weights[0];
        for(int i=1; i<n; i++)
            sum+=weights[i];
        return sum;
    }
    bool isValid(vector<int>& weights, int n, int days, int maxShips){
        int no_of_days=1;
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=weights[i];
            if(sum>maxShips){
                no_of_days++;
                sum=weights[i];
            }
            if(no_of_days>days)
                return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        if(n<days)
            return -1;
        int start=maxElement(weights, n);
        int end=sumOfElements(weights, n);
        int res=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isValid(weights, n, days, mid)==true){
                res=mid;
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return res;
    }
};
