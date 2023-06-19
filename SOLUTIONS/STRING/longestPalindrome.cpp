class Solution {
public:
    string longestPalindrome(string s) {
        int n =s.length();
        string str;
        int ans = 0;
        
        for(int i=0;i<s.length();i++)
        {
            int left=i,right=i+1;
            while(left>=0  && right<s.length() &&  s[left]==s[right] )
            {
                left--;
                right++;
            }
            left++;
            right--;
            int length = (right-left)+1;

            if(ans<length)
            {
               ans=length;
               str = s.substr(left, right-left+1);
            }
        
            left=i,right=i;
            // if length is odd
            while(left>=0 && right<s.length() && s[left]==s[right])
            {
                  
                left--;
                right++;
            }
            left++;
            right--;
            length = right-left+1;
            if(ans<length)
            {
               ans=length;
               str = s.substr(left, right-left+1);
            }
        }
    
     return str;
    }
};
