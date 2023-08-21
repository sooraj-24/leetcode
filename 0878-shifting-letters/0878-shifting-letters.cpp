class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        if(n > 1){
            for(int i=n-2; i>=0; i--){
                shifts[i] += shifts[i+1];
                if(shifts[i] >= 26) shifts[i] = shifts[i] % 26;
            }
        }
        for(int i=0; i<n; i++){
            if(shifts[i] >= 26) shifts[i] = shifts[i] % 26;
            if(s[i] + shifts[i] <= 'z'){
                s[i] = s[i] + shifts[i];
            } else {
                s[i] = s[i] + shifts[i] - 'z' + 'a' - 1;
            }
        }
        return s;
    }
};