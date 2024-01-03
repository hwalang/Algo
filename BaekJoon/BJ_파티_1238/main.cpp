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
vector<int> dist;							// �Ÿ� ���� ����
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
	dist[start] = 0;			// ���� ������ �ִܰŸ��� 0���� ����
	
	// pair<int, int>: �����͸� �����Ѵ�. - <min_cost, now_home>
	// vector<pair<int, int>>: �� �����͸� �����ϴ� ����̴�.
	// greater<pair<int, int>>: ���Ϳ� ����� �����͸� first ���� ���ؿ� �°� ������������ �����Ѵ�.
	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	pq.push({ 0, start });
	
	while (!pq.empty()) {
		// ���� �������� �ִܰŸ��� �� ��ȣ�� �����´�.
		int min_cost = pq.top().first;
		int now_home = pq.top().second;
		pq.pop();

		// ���� ������ �� �� �ִ� ��� �� �ִ� �Ÿ��� �̹� �ִ� ��� �ش� ��θ� ����
		if (min_cost > dist[now_home])
			continue;

		// ���� ���� ������ ������� �ִ� �Ÿ��� ���Ѵ�.
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
	// 1. �� �������� X�� ���� �ִ� �Ÿ��� ���Ѵ�.
	for (int i = 1; i <= N; ++i) {
		Dijstra(i);
		reverse_dist[i] = dist[X];
	}

	// 2. X���� �� ������ ���� �ִ� �Ÿ��� ���Ѵ�.
	Dijstra(X);

	for (int i = 1; i <= N; ++i) {
		reverse_dist[i] += dist[i];
		ans = max(ans, reverse_dist[i]);
	}

	cout << ans;

	return 0;
}