class Solution {
public:
    bool isValid(string s) {
        stack<char> pstack;
        for (int i = 0; i<s.size(); i++){
            if (s[i]=='(' || s[i]=='{' || s[i]=='[') {
                pstack.push(s[i]);
                continue;
            }
            
            if (s[i]==')' || s[i]=='}' || s[i]==']'){
                if (pstack.empty()){
                    return false;
                }
                if (s[i]==')' && pstack.top()!='(') {
                    return false;
                }
                if (s[i]=='}' && pstack.top()!='{') {
                    return false;
                }
                if (s[i]==']' && pstack.top()!='[') {
                    return false;
                }
                pstack.pop();
            }
        }

        return (pstack.empty());
    }
};
