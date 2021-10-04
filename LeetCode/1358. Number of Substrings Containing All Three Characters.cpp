class Solution {
public:
    int numberOfSubstrings(string s) {
         //reduce the check function to grt thr desire data
        // i am usinf the silding window how to check the count the a b and c;
        int i=0,j=-1,ans=0,n=s.length();
        int a=-1,b=-1,c=-1;
        while(j<n){
            if(a>=i && b>=i && c>=i){
                ans+=n-j;
                i++;
            }else{
                j++;
                if(s[j]=='a'){a=j;}
                if(s[j]=='b'){b=j;}
                if(s[j]=='c'){c=j;}
                
            }
            
            /*
            if(!check(j,i)){
                j++;
            }else{
                ans+=n-j;
                i++;
            }
            */
        }
        return ans;
        
    }
};
