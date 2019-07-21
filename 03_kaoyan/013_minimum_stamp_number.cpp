
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;
	vector<int> stampValues(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> stampValues[i];
	}

	vector<vector<int> > dp(N+1, vector<int>(M + 1, INT_MAX - 1));
	for (int i = 0; i <= N; i++) dp[i][0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (j >= stampValues[i-1]) {
				dp[i][j] = std::min(dp[i][j], dp[i - 1][j]);
				dp[i][j] = std::min(dp[i][j], 1 + dp[i - 1][j - stampValues[i-1]]);
			}
		}
	}

	if (dp[N][M] > N) {
		cout << 0 << endl;
	}
	else {
		cout << dp[N][M] << endl;
	}
	
    return 0;
}

