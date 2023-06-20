
int minCharsforPalindrome(string str) {
	int n = str.length();
	int l = 0;
	int r = n-1;
	int ans = 0;
	while(l < r)
	{	
		if(str[l] == str[r])
		{
			l++;
			r--;
		}else{
			ans++;
			l = 0;
			r = n - ans - 1;
		}
	}	
	return ans;
}
