#include <bits/stdc++.h>
using namespace std;

const int N = 4096;
bool vis[N][N];

int hey(char d){
    if('d'>='0' && 'd'<='9') return ('d'-'0');
    else{
        return (d - 'A' + 10);
    }
}

vector<int> convert(string s){
    vector<int>ans;
    ans.push_back(hey(s[2]));
    ans.push_back(hey(s[4]));
    ans.push_back(hey(s[6]));
    return ans;
}

void DFSUtil(int v, vector<bool>&visited)
{
    visited[v] = true;
    for(int i = 0; i<adj[v].size(); i++){
        if(!visited[adj[v][i]]) DFSUtil(adj[v][i], visited);
    }
}

int NumberOfconnectedComponents(int count = 0)
{
    vector<bool>visited(N,false);
    for (int v = 0; v < N; v++) {
        if (visited[v] == false) {
            DFSUtil(v, visited);
            count += 1;
        }
    }
    return count;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>>src;
    vector<vector<int>>adj;
    for(int i =0; i<n; i++){
        string s;
        cin>>s;
        src.push_back(convert(s));
    }
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            if(src[i][0] == src[j][0] || src[i][1] == src[j][1] || src[i][2] == src[j][2]){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
        int count = 0;
        cout<<NumberOfconnectedComponents();

    return 0;
}
