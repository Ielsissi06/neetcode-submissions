class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) return false;

        stack<char> characters;
        for (const char& c : s) {
            if (c == '(' || c == '[' || c == '{') {
                characters.push(c);
            } else if (c == ')') {
                if (characters.empty()) return false;
                if (characters.top() != '(') return false;
                else characters.pop();
            } else if (c == ']') {
                if (characters.empty()) return false;
                if (characters.top() != '[') return false;
                else characters.pop();
            } else if (c == '}') {
                if (characters.empty()) return false;
                if (characters.top() != '{') return false;
                else characters.pop();
            }
        }
        return characters.empty();
    }
};
