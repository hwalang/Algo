#include <iostream>
#include <climits>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

#define MAX_N 1000
#define INF INT_MAX

using namespace std;

int N, M, X;
vector<pair<int, int>> homes[MAX_N + 1];
vector<int> dist;							// 거리 정보 저장
int reverse_dist[MAX_N + 1];
int ans;

void Input()
{
	int a, b, t;

	cin >> N >> M >> X;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b >> t;
		homes[a].push_back(make_pair(t, b));
	}
}

void Dijstra(int start)
{
	dist.clear();
	dist.resize(N + 1, INF);
	dist[start] = 0;			// 시작 정점의 최단거리를 0으로 설정
	
	// pair<int, int>: 데이터를 저장한다. - <min_cost, now_home>
	// vector<pair<int, int>>: 위 데이터를 저장하는 방식이다.
	// greater<pair<int, int>>: 벡터에 저장된 데이터를 first 값을 기준에 맞게 내림차순으로 정렬한다.
	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	pq.push({ 0, start });
	
	while (!pq.empty()) {
		// 현재 집까지의 최단거리와 집 번호를 가져온다.
		int min_cost = pq.top().first;
		int now_home = pq.top().second;
		pq.pop();

		// 현재 집까지 갈 수 있는 경우 중 최단 거리가 이미 있는 경우 해당 경로를 무시
		if (min_cost > dist[now_home])
			continue;

		// 현재 집의 인접한 집들까지 최단 거리를 구한다.
		for (int i = 0; i < homes[now_home].size(); ++i) {
			int next_home = homes[now_home][i].second;
			int next_cost = min_cost + homes[now_home][i].first;

			if (next_cost < dist[next_home]) {
				dist[next_home] = next_cost;
				pq.push({ next_cost, next_home });
			}
		}
	}
}

int main() 
{
	Input();
	// 1. 각 마을에서 X로 가는 최단 거리를 구한다.
	for (int i = 1; i <= N; ++i) {
		Dijstra(i);
		reverse_dist[i] = dist[X];
	}

	// 2. X에서 각 마을로 가는 최단 거리를 구한다.
	Dijstra(X);

	for (int i = 1; i <= N; ++i) {
		reverse_dist[i] += dist[i];
		ans = max(ans, reverse_dist[i]);
	}

	cout << ans;

	return 0;
}