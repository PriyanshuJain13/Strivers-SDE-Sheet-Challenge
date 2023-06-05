#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>> arr;

  for(long long i = 1;i <= n;i++)
  {
    long long num = 1;
    vector<long long> temp(i);
    for(long long j = 1;j <= i;j++)
    {
      temp[j-1] = num;
      num = num * (i-j)/j;
    }
    arr.push_back(temp);
  }

  return arr;
}
