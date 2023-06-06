#include <bits/stdc++.h> 

long long merge(long long arr[], long long temp[], int left, int mid,
		int right)
{
	int i, j, k;
	long long ans = 0;

	i = left;
	j = mid;
	k = left;
	while ((i <= mid - 1) && (j <= right)) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
			ans = ans + (mid - i);
		}
	}

	while (i <= mid - 1)
		temp[k++] = arr[i++];


	while (j <= right)
    {
        temp[k++] = arr[j++];
    }

	for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
		

	return ans;
}

long long mergeSort(long long arr[], long long temp[], int left, int right)
{
	long long mid, ans = 0;
	if (right > left) {
		mid = (right + left) / 2;
		ans += mergeSort(arr, temp, left, mid);
		ans += mergeSort(arr, temp, mid + 1, right);
		ans += merge(arr, temp, left, mid + 1, right);
	}
	return ans;
}

long long getInversions(long long *arr, int n){
    long long temp[n];
    return mergeSort(arr,temp,0,n-1);
}
