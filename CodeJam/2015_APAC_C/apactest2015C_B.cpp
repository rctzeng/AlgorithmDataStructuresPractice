#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	int run = 1;
	for(run = 1; run <= t; run++) {
		int n; 
		cin >> n;
		int i;
		double rangeMin = 0.0, rangeMax = 1e16;
		int flag = 0;
		long long int finalans = -1;
		for(i = 0; i < n; i++) {
			int x;
			long long int y;
			cin >> x;
			cin >> y;
			y = y * 100;
			double ans1 = 0.0;
			double ans2 = rangeMax;
			if(x == 100) {
				ans2 = (double) y / x;
				finalans = y / 100;
			} else if(x == 0) {
				ans1 = (double) y / (x + 1);
			} else {
				ans2 = (double) y / x;
				ans1 = (double) y / (x + 1);
			}
			if(ans2 < rangeMin || ans1 > rangeMax) {
				flag = 1;
				break;
			}
			rangeMin = max(rangeMin, ans1);
			rangeMax = min(rangeMax, ans2);
		}
		cout << "Case #" << run << ": ";
		if(flag) {
			cout << "-1" << endl;
		} else {
			long long int temp1 = rangeMax;
			long long int temp2 = rangeMin;
			//cout << temp1 << " " << temp2 << " " << finalans << endl;
			if(temp1 - temp2 == 0 || temp1 - temp2 == 1) {
				cout << temp1 << endl;
			} else if(finalans != -1 && finalans <= temp1 && finalans >= temp2) {
				cout << finalans << endl;
			} else {
				cout << "-1" << endl;
			}
		}
	}
	return 0;
}