//problem link is-https://leetcode.com/problems/valid-parentheses/





class Solution {
public:
    bool isValid(string x) {
               	stack<char>s;
		for (int i = 0; i < x.size(); i++) {
			char c = x[i];
			if (c == '{' || c == '[' || c == '(')
				s.push(c);
			else if (c == '}') {
				if ( !s.empty() && s.top() == '{' )
					s.pop();
				else
					return 0;
			}
			else if (c == ']') {
				if (!s.empty() && s.top() == '[' )
					s.pop();
				else
					return 0;
			}
			else if (c == ')') {
				if (!s.empty() && s.top() == '(' )
					s.pop();
				else
					return 0;
			}
		}
		if (s.empty())
			return true;
		else
			return false;
    }
};


