#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
#include <cstdio>

using namespace std;

int M[17][17];
int visited[17];
int cities;//순회 도시 수 
int N;
int cost;
vector<int> v;

void dfs(int cur) {

	//모든 도시를 지나왔고 마지막으로 원점으로 돌아가는 edge가 있다면 지금까지의 cost에 1로가는 cost를 더한 후 저장 및 종료
	if (cities == N && M[cur][1] != 0) {
		v.push_back(cost + M[cur][1]); return;
	}

	for (int i = 2; i <= N; ++i) {
		if (i == cur)
			continue;//현재 도시는 무시한다 ex)a[i][i]
		if (M[cur][i] != 0 && visited[i] == 0) {
			visited[i] = 1;//방문한 것으로 표시
			cities++;//방문한 도시 수 증가
			cost += M[cur][i];//i도시로 가는 비용을 cost에 추가
			dfs(i);//i도시 방문한다.

				   //이 밑은 방문끝내고 돌아온 경우니까 다 원래대로 돌려야 한다
			cities--;//다시 나왔으면 도시 갯수 감소
			visited[i] = 0;//다시 나왔으면 방문안한거로 처리
			cost -= M[cur][i];//다시 나왔으니 cost 더했던거 다시 빼기

		}
	}
}

int minimum()
{
	int min = v[0];
	for (int i = 1; i < v.size(); i++)
		if (v[i] < min)
			min = v[i];

	return min;
}
int main() {

		memset(M, 0, sizeof(M));
		memset(visited, 0, sizeof(visited));
		v.clear();//vector clear()함수로 reset해주어야 한다.
		cin >> N;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				cin >> M[i][j];
			}
		}
		//cities와 cost 초기화
		cities = 1;
		cost = 0;
		// 시작 시간 저장
		clock_t start = clock();
		dfs(1);//current 1

		//출력부
		// 모든 도시를 순회하고 다시 원점으로 돌아오는 경우가 없으면 -1 출력
		if (v.empty())
			cout << -1 << endl;
		else {
			//만약 있다면 그 경로들의 비용들 중 최소값을 찾아서 출력
			cout << "최소 비용 : "<< minimum() << endl; // 최소값 출력
		}
		// 입력 후 최소값 출력까지 걸리는 시간 출력 (단위 : 초)
		printf("소요 시간 : %0.5f\n", (float)(clock() - start) / CLOCKS_PER_SEC);
	return 0;
}