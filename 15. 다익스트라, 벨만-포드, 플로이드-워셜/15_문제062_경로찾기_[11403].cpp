#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;

vector<vector<long>> dist;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N;

	dist.resize(N, vector<long> (N));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> dist[i][j];

	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (dist[i][k] == 1 && dist[k][j] == 1)
					dist[i][j] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << dist[i][j] << " ";
		cout << "\n";
	}

}