#include<bits/stdc++.h>

using namespace std;

int main() {
	int N, M, S, T; cin >> N >> M >> S >> T;
	
// Graph building
	vector<vector<pair<int, int>>> graph(N, vector<pair<int,int>>());	

	for(int  i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}	

// Temporary edges
	int P; cin >> P;
	for(int i = 0; i < P; ++i){
	
	}
	
	return 0;
}
