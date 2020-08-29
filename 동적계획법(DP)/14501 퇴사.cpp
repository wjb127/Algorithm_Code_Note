#include<iostream>
#include<cstdio>
#include<algorithm>
#include<memory.h>
using namespace std;


int dp[30];

int retire(int T[], int P[], int N) {

	int ans=0;

	if (dp[N - 1] != 0)
		return dp[N - 1];



	for (int i = 0; i < N; i++) {

		// 거꾸로 검색해서 Tj와 날짜 더했을때 N이하가 될떄
		if (T[N - i - 1] + (N - i - 1) <= N) {

			


			// Tj가 1의 경우
			if (T[N - i - 1] == 1) {

				// 답에 Pi 더하기
				ans += P[N - i - 1];
				//cout << ans << " " << N - i << endl;

			}
			else {

				if (N - i - 1 + T[N - i - 1] <= N) {

					if (ans == 0) {
						ans += P[N - i - 1];
					}
					ans = max(ans, dp[N - i - 1 + T[N - i - 1]] + P[N - i - 1]);

					//cout << ans << " " << N - i << endl;
					//cout << "추가 참조 : " << dp[N - i - 1 + T[N - i - 1]] << " " << P[N - i - 1] << endl;
				}


			}




			
		}
		
		dp[N - i - 1] = ans;

	}



	return ans;
}





int main() {

	memset(dp, 0, sizeof(dp));

	int N;
	int T[20];
	int P[20];
	int ans = 0;

	scanf("%d",&N);

	for (int i = 0; i < N; i++) {

		scanf("%d %d", &T[i], &P[i]);

	}

	ans = retire(T, P, N);

	printf("%d\n", ans);

	


	return 0;
}
