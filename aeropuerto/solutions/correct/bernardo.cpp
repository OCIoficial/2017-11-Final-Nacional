#include<bits/stdc++.h>

using namespace std;

// Temporary Edge's structue
struct TE {
	int origin, destiny, starting_time, length;
	TE(int u, int v, int t, int w) : 
		origin(u), destiny(v), starting_time(t), length(w) {}
};

// Temporary dijkstra method
void temporary_dijkstra(vector<int> &distances, vector<vector<temporary_edge>> &tes, int start) {
	
	while(!q.empty()){

	} 	
}

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
	vector<vector<temporary_edge>> tes;
	int P; cin >> P;
	for(int i = 0; i < P; ++i){
		int u, v, t, w;	
		TE temporary_edge(u, v, t, w);
		tes[u].push_back(temporary_edge);
	}

	vector<int> distances(N, 1e9); // initialized to infinity
	// fill the distance array	
	temporary_dijkstra(distances, tes, S);
	// answer
	cout << distances[T] << endl;
	return 0;
}
