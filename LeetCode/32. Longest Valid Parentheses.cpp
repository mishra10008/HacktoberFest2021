int Solution::LBSlength(const string s) {
  if (s.length() <= 1) return 0;
  int curMax = 0;
  vector < int > longest(s.size(), 0);
  for (int i = 1; i < s.length(); i++) {
    if (s[i] == '>' || s[i] == ')' || s[i] == ']' || s[i] == '}') {
      if ((s[i] == '>' && s[i - 1] == '<') ||
        (s[i] == ')' && s[i - 1] == '(') ||
        (s[i] == ']' && s[i - 1] == '[') ||
        (s[i] == '}' && s[i - 1] == '{')) {
        longest[i] = (i - 2) >= 0 ? (longest[i - 2] + 2) : 2;
        curMax = max(longest[i], curMax);
      } else {
        if (i - longest[i - 1] - 1 >= 0 && (
            (s[i] == '>' && s[i - longest[i - 1] - 1] == '<') ||
            (s[i] == ')' && s[i - longest[i - 1] - 1] == '(') ||
            (s[i] == ']' && s[i - longest[i - 1] - 1] == '[') ||
            (s[i] == '}' && s[i - longest[i - 1] - 1] == '{'))) {
          longest[i] = longest[i - 1] + 2 + ((i - longest[i - 1] - 2 >= 0) ? longest[i - longest[i - 1] - 2] : 0);
          curMax = max(longest[i], curMax);
        }
      }
    }
    //if s[i] == '<' or '(' or '[' or '{', skip it, because longest[i] must be 0
  }
  return curMax;
}
