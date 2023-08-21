class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        //unordered_set<char> unique;
        unordered_map<char, int> unique;
        unordered_map<string, int> mp;
        int l = 0;
        int r;
        for(r=0; r<minSize; r++){
            unique[s[r]]++;
        }
        r--;
        while(r < s.length()){
            if(unique.size() <= maxLetters){
                cout<<unique.size()<<" "<<l<<r<<endl;
                mp[s.substr(l, r-l+1)]++;
            }
            unique[s[l]]--;
            if(unique[s[l]] == 0) unique.erase(s[l]);
            l++;
            r++;
            unique[s[r]]++;
        }
        int ans = 0;
        for(auto it: mp){
            ans = max(ans, it.second);
        }
        //if(ans == 1) return 0;
        return ans;
    }
};