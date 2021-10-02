class Solution
{
public:
   vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
   {
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
      int n = mat.size(), m = mat[0].size();
      for (int i = 0; i < n; i++)
      {
         /*int start=0,end=m-1;
            while(start<=end){
                int mid=start+ ((end -start)/2);
                if(mat[i][mid]==1 && mat[i][mid+1]==0){
                    q.push({mid,i});
                }else if(mat[i][mid]==1){
                    start=mid+1;
                }else if(mat[i][mid]==0){
                    end=mid-1;
                }
            }*/
         int p = 0;
         for (int j = 0; j < m; j++)
         {
            if (mat[i][j] == 1)
            {
               p++;
            }
         }
         q.push({p + 1, i});
      }

      vector<int> ans;
      for (int i = 0; i < k; i++)
      {
         //cout<<q.top().first<<" "<<q.top().second<<"\n";
         ans.push_back(q.top().second);
         q.pop();
      }
      return ans;
   }
};