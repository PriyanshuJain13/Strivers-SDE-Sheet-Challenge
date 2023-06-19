class Solution {
    private:
    int prime=5381;
public:
    int repeatedStringMatch(string a, string b) {
        if(a==b) return 1;
        int count=1;
        string pattern=a;
        while(pattern.size()<b.size()){
            count++;
            pattern+=a;
        }
        if(pattern==b) return count;
        if(rabincarp(pattern,b)!=-1) return count;
        if(rabincarp(pattern+a,b)!=-1) return count+1;
        return -1;

    }
    int rabincarp(string text,string pattern){

        int m=pattern.size();
        int n=text.size();
        int patcode=0;
        int txtcode=0;
        int pow=1;

        for (int i=0;i<m;i++){
            pow=(pow*26)%prime;
        }

        for(int i=0;i<m;i++){
            patcode=(patcode*26+pattern[i])%prime;
        }

        for(int i=0;i<n;i++){
            txtcode=(txtcode*26+text[i])%prime;
            if(i<m-1) continue;
            if(i>=m){
                txtcode=(txtcode-text[i-m]*pow)%prime;
            }
            if(txtcode<0)txtcode+=prime;
            if(txtcode==patcode){
                if(text.substr(i-m+1,m)==pattern)
                return i-m+1;
            }
        }
        
        return -1;
    }
};
