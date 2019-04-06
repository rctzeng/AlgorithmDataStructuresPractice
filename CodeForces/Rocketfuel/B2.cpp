# include <stdio.h>
# include <deque>

using namespace std;

int main() {
    long long int n,m;
    scanf("%I64d%I64d", &n, &m);
    deque<int> num;
    num.push_back(n);
    m--;
    for(int i=n-1;i>0;i--) {
        if(m%2) num.push_back(i);
        else    num.push_front(i);
        m/=2;
    }

    for(int i=0;i<n;i++) printf("%d ", num[i]);

    return 0;
}
