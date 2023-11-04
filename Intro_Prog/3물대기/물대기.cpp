#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

// 런타임 에러( OutOfBounds )

#define MAX_N 300

int N;
int W[MAX_N + 1];
int P[MAX_N + 1][MAX_N + 1];				// 가상의 노드 0번이 우물을 파는데 드는 비용으로 각 노드와 연결된다.
std::tuple<int, int, int> edge[MAX_N + 1];  // cost, v1, v2

void Input()
{
	std::cin >> N;
	for (int i = 1; i <= N; ++i)
		std::cin >> W[i];

	for (int i = 0; i <= N; ++i)
	{
		for (int j = 0; j <= N; ++j)
		{
			if (i == 0 && j == 0) P[i][j] = 0;
			else if (i == 0) P[i][j] = W[j];
			else if (j == 0) P[i][j] = W[i];
			else std::cin >> P[i][j];
		}
	}
}
void MakeEdge()
{
	int idx = 0;
	for (int i = 0; i <= N; ++i)
	{
		for (int j = 0; j <= N; ++j)
		{
			if (i >= j) continue;
			edge[idx++] = std::make_tuple(P[i][j], i, j);
		}
	}
}

// Union Find 알고리즘
std::vector<int> parents(MAX_N + 1, -1);	// -1로 초기화
int Find(int x)
{
	if (parents[x] < 0) return x;
	return parents[x] = Find(parents[x]);
}
bool IsDiffGroup(int v1, int v2)
{
	v1 = Find(v1);
	v2 = Find(v2);
	if (v1 == v2) return 0;
	if (parents[v1] == parents[v2]) parents[v1]--;

	if (parents[v1] < parents[v2]) parents[v2] = v1;
	else parents[v1] = v2;

	return true;
}


int main()
{
	Input();
	MakeEdge();
	int edgeCnt = (N + 1) * 2;	// 간선의 수 = 정점의 수( 논 + 가상의 논 ) * 2

	// kruskal
	std::sort(edge, edge + edgeCnt);
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < edgeCnt; ++i)
	{
		int cost, v1, v2;
		std::tie(cost, v1, v2) = edge[i];
		if (!IsDiffGroup(v1, v2))
			continue;

		ans += cost;
		++cnt;
		if (cnt == N)
			break;
	}

	std::cout << ans;

	return 0;
}