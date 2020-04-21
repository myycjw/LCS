#include<map>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<string>
#include<cstdio>
#include <iomanip>
using namespace std;
const int maxn = 1e5 + 10;
#define ll long long
int i, j, k;
int n, m, q;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
map<ll, ll> mp[30];
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}
const int maxm = 1010;
char a[maxm], b[maxm], x[maxm], y[maxm];
int dp[maxm][maxm], c[maxm][maxm];
int vals[maxm][maxm];
void Print(int i, int j) {
	if (i == 0 || j == 0) {
		return;
	}
	if (c[i][j] == 1) {
		Print(i - 1, j - 1);
		printf("%c ", a[i - 1]);
	}
	else if (c[i][j] == 2) {
		Print(i - 1, j);
	}
	else if (c[i][j] == 3) {
		Print(i, j - 1);
	}
}
int main() {
	while (cin >> x >> y) {
		memset(dp, 0, sizeof dp);
		memset(c, 0, sizeof c);
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		a[0] = x[1];
		for (i = 1; i < strlen(x) / 2; i++) {
			a[i] = x[2 * i+1];
		}
		b[0] = y[1];
		for (i = 1; i < strlen(y) / 2; i++) {
			b[i] = y[2 * i+1];
		}
		int lena = strlen(a);
		int lenb = strlen(b);
		for (i = 1; i <= lena; i++) {
			for (j = 1; j <= lenb; j++) {
				if (a[i - 1] == b[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
					c[i][j] = 1;
				}
				else {
					if (dp[i - 1][j] > dp[i][j - 1]) {
						dp[i][j] = dp[i - 1][j];
						c[i][j] = 2;
					}
					else {
						dp[i][j] = dp[i][j - 1];
						c[i][j] = 3;
					}
				}
				if (a[i-1] == b[j-1]) {
					vals[i][j] = vals[i - 1][j - 1] + 1;
				}
				else if (a[i - 1] != b[j - 1]) {
					vals[i][j] = max(vals[i - 1][j], vals[i][j - 1]);
				}
			}
		}
		for (i = 0; i < lena; i++) {
			for (j = 0; j < lenb; j++) {
				printf("%d ", vals[i][j]);
			}
			printf("\n");
		}
		Print(lena, lenb);
		memset(x, 0, sizeof x);
		memset(y, 0, sizeof y);
	}
	return 0;
}
/*
<A,B,D,C,A,C>
<A,C,D,B>

<A,B,C,B,D,A,B>
<B,D,C,A,B,A>
*/

