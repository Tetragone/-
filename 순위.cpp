#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int graph[109][109];
bool visited[109];
pair<int, int> inout[109];

int bfsIn(int, int);
int bfsOut(int ,int);

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int rize = results.size();
    
    for (int i = 0; i < rize; i++) 
        graph[results[i][0] - 1][results[i][1] - 1] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) visited[j] = false;
        int temp1 = bfsIn(i, n);
        for (int j = 0; j < n; j++) visited[j] = false;
        int temp2 = bfsOut(i, n);
        
        if (temp1 + temp2 == n - 1) answer++;
    }
    
    return answer;
}

int bfsIn(int start, int n) {
    queue<int> search;
    search.push(start);
    visited[start] = true;
    int counter = 0;
    
    while (!search.empty()) {
        int now = search.front();
        search.pop();
        
        for (int i = 0; i < n; i++) {
            if (graph[i][now] && !visited[i]) {
                search.push(i);
                visited[i] = true;
                counter++;
            }
        }
    }
    
    return counter;
}

int bfsOut(int start, int n) {
    queue<int> search;
    search.push(start);
    visited[start] = true;
    int counter = 0;
    
    while (!search.empty()) {
        int now = search.front();
        search.pop();
        
        for (int i = 0; i < n; i++) {
            if (graph[now][i] && !visited[i]) {
                search.push(i);
                visited[i] = true;
                counter++;
            }
        }
    }
    
    return counter;
}
