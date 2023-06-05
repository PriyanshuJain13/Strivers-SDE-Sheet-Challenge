#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   unordered_map<int,int> mp;
   for(int i = 0;i < n;i++)
   {
      mp[arr[i]]++;
   }
   int i = 0;
   while(mp[0]--)
   {
      arr[i] = 0;
      i++;
   }
   while(mp[1]--)
   {
      arr[i] = 1;
      i++;
   }
   while(mp[2]--)
   {
      arr[i] = 2;
      i++;
   }
}
