class Solution {
public:
    bool isValid(string s) {
        
        stack<char>s1;
        
        if(s[0]=='}' || s[0]==')' || s[0]==']')
            return false;
        
        s1.push(s[0]);
        for(int i=1;i<s.size();i++)
        {
            if(s[i]=='{' || s[i]=='(' || s[i]=='[')
                s1.push(s[i]);
            else if(s[i]=='}' && s1.size()==0 || s[i]=='}' &&  s1.top()!='{')
                return false;
            else if(s[i]==']' && s1.size()==0  ||s[i]==']' && s1.top()!='[')
                return false;
            else if(s[i]==')' && s1.size()==0 || s[i]==')' && s1.top()!='(')
                return false;
            else 
                s1.pop();
        }
        
        
        if(s1.size()>0)
            return false;
      
        
        return true;
    }
};
