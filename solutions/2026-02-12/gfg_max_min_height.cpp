class Solution {
public:
    int maxMinHeight(vector<int> &arr, int k, int w) {
        int n = arr.size();
        using ll = long long;

        ll l = 0, h = 1e14;
        ll ans = 0;

        while (l <= h) {
            ll mid = l + (h - l) / 2;

            vector<ll> diff(n + 1, 0);
            ll currWater = 0;
            ll operations = 0;

            for (int i = 0; i < n; i++) {
                currWater += diff[i];
                ll height = arr[i] + currWater;

                if (height < mid) {
                    ll need = mid - height;
                    operations += need;

                    if (operations > k) break;

                    currWater += need;
                    if (i + w < n)
                        diff[i + w] -= need;
                }
            }

            if (operations <= k) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        return ans;
    }
};
