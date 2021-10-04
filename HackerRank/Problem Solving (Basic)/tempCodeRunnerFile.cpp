long repeatedString(string s, long n) {
    long count=0, i=0;
    while (i<n)
    {
        long j=0;
        while(s[j]!='\0' && i<n){
            if(s[j]=='a'){
                count++;
            }
            i++;
            j++;
        }
    }
    return count;    
}