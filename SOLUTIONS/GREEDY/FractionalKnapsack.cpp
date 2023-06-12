//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,int>> v;
        for(int i = 0;i < n;i++)
        {
            v.push_back({(double)arr[i].value/arr[i].weight,i});
        }
        
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        
        double ans = 0;
        int i = 0;
        while(i < n && W > 0)
        {
            if(arr[v[i].second].weight <= W)
            {
                W -= arr[v[i].second].weight;
                ans += arr[v[i].second].value;
            }else{
                ans=ans+((double)W/arr[v[i].second].weight)*arr[v[i].second].value;
                W = 0;
            }
            i++;
        }
        
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends
