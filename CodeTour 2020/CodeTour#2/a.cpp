#include <bits/stdc++.h>
#define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i) // 1 based indexing
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i) // reverse 1 based

//short hand for usual tokens
#define pb push_back
#define fi first
#define se second

// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal

// traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)

// find if a given value is present in a container. Container version. Runs in log(n) for set and map
#define present(c,x) ((c).find(x) != (c).end())

//find version works for all containers. This is present in std namespace.
#define cpresent(c,x) (find(all(c),x) != (c).end())

// Avoiding wrap around of size()-1 where size is a unsigned int.
#define sz(a) int((a).size())

using namespace std;

// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

bool winnerSquareGame(int n) {
    vector<bool>dp(n+1);
    for (int i = 0; i < n + 1; i++) {
        for (int k = 1; k * k <= i; k++) {
            if (dp[i - k * k] == false) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

int kadane1d(vector<int> a)
{
    int size = a.size();
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int kadane2D(vector<vector<int>> array){
    int N = array.size();
    if(N == 0) return 0;
    int M = array[0].size();
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++){
            array[i][j] += array[i-1][j];
        }
    }
    int ans = 0;
    for(int bottom = 0; bottom < N; bottom++){
        for(int top = bottom; top < N; top++){
            vector<int>sums(N);
            for(int i = 0; i < M; i++){
                if (bottom > 0) {
                    sums[i] = array[top][i] - array[bottom-1][i];
                } else {
                    sums[i] = array[top][i];
                }
            }
            ans = max(ans, kadane1d(sums));
        }
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        if(winnerSquareGame(x) == 1) cout<<"A"<<endl;
        else cout<<"B"<<endl;
    }
    return 0;
}
