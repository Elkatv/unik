#include <iostream>
#include <cmath>
#include <vector>
#include <clocale>
#include <algorithm>

using namespace std;

static const int NEG_INF = -1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, NEG_INF));
    dp[0][0] = 0;

    for (int c = 0; c <= k; c++) {

        // Обычные шаги и прыжки
        for (int i = 0; i <= n; i++) {
            if (dp[i][c] == NEG_INF) continue;

            if (i + 1 <= n) {
                dp[i + 1][c] = max(dp[i + 1][c], dp[i][c] + a[i + 1]);
            }
            if (i + 2 <= n) {
                dp[i + 2][c] = max(dp[i + 2][c], dp[i][c] + a[i + 2]);
            }
        }

        // Абстрагирование
        if (c < k) {
            int best = NEG_INF;
            for (int i = 0; i < n; i++) {
                best = max(best, dp[i][c]);
                dp[i + 1][c + 1] =
                    max(dp[i + 1][c + 1], best + a[i + 1]);
            }
        }
    }

    int ans = NEG_INF;
    for (int c = 0; c <= k; c++) {
        ans = max(ans, dp[n][c]);
    }

    cout << ans << "\n";
    return 0;
}
