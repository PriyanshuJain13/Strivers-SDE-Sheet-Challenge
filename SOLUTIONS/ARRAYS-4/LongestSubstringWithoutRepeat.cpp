class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int n=s.size();
        int ans=0;

        set<char> st;

        while(j<n){
            if(st.count(s[j])<1){
                ans=max(ans,j-i+1);
            }else{
                while(s[i]!=s[j]){
                    st.erase(s[i]);
                    i++;
                }
                st.erase(s[i]);
                i++;
                ans=max(ans,j-i+1);
            }
            st.insert(s[j]);
            j++;
        }
        return ans;
    }
};
