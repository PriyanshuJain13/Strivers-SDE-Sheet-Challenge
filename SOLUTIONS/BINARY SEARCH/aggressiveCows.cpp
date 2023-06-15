
bool check(int x, int k, vector<int> &stalls)
{

    int cowsPlaced = 1, lastPos = stalls[0];
    int n = stalls.size();
    for (int i = 1; i < n; i++)
    {
        if ((stalls[i] - lastPos) >= x)
        {
            cowsPlaced = cowsPlaced + 1;

            if (cowsPlaced == k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    long long int low = 0, high = 1000000000, mid, pos = 0;

    while (high >= low)
    {
        mid = (high + low) / 2;

        if (check(mid, k, stalls))
        {
            low = mid + 1;
            pos = mid;
        }
        else
        {
            high = mid - 1;
        }
    }

    return pos;
}

