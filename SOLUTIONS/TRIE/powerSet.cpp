class Solution{
	public:
		vector<string> ans;
        void print(string &s,string res,int ind,int size)
        {
            if(ind==size )
            {   
                if(res=="") return ;
                ans.push_back(res);
                return;
            }
            res.push_back(s[ind]);
            print(s,res,ind+1,size);
            res.pop_back();
            print(s,res,ind+1,size);
           
        }
    
        vector<string> AllPossibleStrings(string s)
        {
           int size = s.length();
           print(s,"",0,size);
           sort(ans.begin(),ans.end());
           return ans;
        }
};
