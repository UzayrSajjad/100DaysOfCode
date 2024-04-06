class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<char> str(s.size()); 
        int n = s.length();
        int count = 0;

        for(int i=0; i<n; i++) {
            str[i] = s[i];
        }
        
        // First pass from 0 index
        for(int i=0; i<n; i++) {
            if(str[i] == '(' ) {
                count++;
            }
            else if(str[i] == ')' ) {
                if(count == 0) {
                    str[i] = ' '; 
                } else {
                    count--;
                }
            }
        }

        // Second pass from n-1
        count = 0;
        for(int i=n-1; i>=0; i--) {
            if(str[i] == ')' ) {
                count++;
            }
            else if(str[i] == '(' ) {
                if(count == 0) {
                    str[i] = ' '; 
                } else {
                    count--;
                }
            }
        }

        string result;

        for(int i=0; i<n; i++) {
            if(str[i] != ' ') {
                result += str[i]; 
            }
        }
        return result;
    }
};
