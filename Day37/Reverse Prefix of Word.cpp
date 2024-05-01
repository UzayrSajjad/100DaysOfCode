class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0;
        int j = word.find(ch);
        
        while(i < j) {
            swap(word[i], word[j]);
            i++;
            j--;
        }
        
        return word;
        
    }
};
