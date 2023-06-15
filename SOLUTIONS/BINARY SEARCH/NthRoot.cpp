
int NthRoot(int n, int m) {

    int ans = -1;
    int s = 1, e = m;
    
    while (s <= e) {
        int mid = (s + e) / 2;
        
        long long x = 1;

        for (int i = 1; i <= n; ++i) {
            x *= mid;
   
            if (x > 1LL * m) {
                break;
            }
        }

        if (x == 1LL * m) {
            ans = mid;
            break;
        }
        if (x > m) {
            e = mid - 1;
        } else
            s = mid + 1;
    }
    return ans;
}
