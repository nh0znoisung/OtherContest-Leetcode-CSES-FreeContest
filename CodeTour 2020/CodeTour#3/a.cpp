#include <bits/stdc++.h>
using namespace std;

double norm(pair<int,int> a, pair<int,int> b){
    double ans = 0;
   // cout<<a.first-b.first<<endl;
    ans = sqrt((double)(a.first-b.first)*(a.first-b.first) + (double)(a.second-b.second)*(a.second-b.second));
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>a;
    vector<pair<int,int>>b;
    for(int i =0; i<n;i ++){
        int x,y;
        cin>>x>>y;
        a.push_back(make_pair(x,y));
    }
    for(int i =0; i<m;i ++){
        int x,y;
        cin>>x>>y;
        b.push_back(make_pair(x,y));
    }
   // cout<<a[0].first<<a[0].second<<endl;
    double ans1 = norm(a[0],b[0]);
    double ans2 = norm(a[0],b[0]);
  //  cout<<ans1<<endl;
    for(int i =0 ; i<n;i++){
        for(int j = 0; j<m; j++){
            double k = norm(a[i],b[j]);
            ans1 = max(ans1, k);
            ans2 = min(ans2, k);
        }
    }


    cout << fixed << setprecision(4) << ans1<<endl;
    cout << fixed << setprecision(4) << ans2<<endl;
    return 0;
}
