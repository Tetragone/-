#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int visited[20009];
bool graph[20009][20009];

int bfs(int, int);

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int eize = edge.size();
    
    for (int i = 0; i < eize; i++) {
        graph[edge[i][0] - 1][edge[i][1] - 1] = true;
        graph[edge[i][1] - 1][edge[i][0] - 1] = true;
    }
    
    memset(visited, -0x01, sizeof(visited));
    cout << endl;
    answer = bfs(0, n);
    return answer;
}
// 그냥 bfs이다
int bfs(int start, int n) {
    queue<int> search;
    int now = 0;
    int rank = 0;
    int counter = 0;
    
    search.push(start);
    visited[start] = 0;
    
    while (!search.empty()) {
        now = search.front();
        search.pop();

        if (visited[now] != rank) {
            rank++;
            counter = 1;
        }
        else counter++;
        
        for (int i = 0; i < n; i++) {
            if (graph[i][now] && visited[i] == -1) {
                visited[i] = rank + 1;
                search.push(i);
            }
        }
    }
    
    return counter;
}
