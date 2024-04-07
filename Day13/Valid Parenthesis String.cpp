class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0;

        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen = max(0, minOpen - 1);
                maxOpen--;
                if (maxOpen < 0) return false; 
            } else {
                minOpen = max(0, minOpen - 1); 
                maxOpen++; 
            }
        }
        return minOpen == 0;
    }
};
