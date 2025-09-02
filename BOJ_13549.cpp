#include <iostream>  
#include <queue>  
  
using namespace std;  
  
int main () {  
    int start, end; cin >> start >> end;  
    // 처음부터 동생과 수빈이의 위치가 같으면 바로 0 출력  
    if (start == end) { cout << 0; return 0; }  
  
    // 좌표, 시간  
    pair<int, int> p[100001];  
    for (int i = 0; i < 100001; i++) { p[i].first = i; p[i].second = -1; }  
  
    // 출발 위치 초기 설정  
    queue<pair<int,int>> q;  
    q.push({start, 0});  
    p[start].second = 0;  
  
    while (!q.empty()) {  
       start = q.front().first; int time = q.front().second; q.pop();  
  
       // 순간이동 하는 경우를 위해, 현재 위치를 담은 배열 생성  
       int next[3] = {start, -1, 1};  
       for (int i = 0; i < 3; i++) {  
          // 범위 예외 처리  
          if (start + next[i] < 0 || start + next[i] > 100000) continue;  
  
          // 1) 아직 가보지 않은 경우 및 2) 간 경우라도, 지금 가는 경우가 더 빠를 때 방문  
          if (p[start + next[i]].second == -1 || p[start + next[i]].second > time) {  
             // i == 0 일 때는, 순간이동 하는 경우이므로, 시간 추가 안함  
             if (i == 0) { q.push({start + next[i], time}); p[start + next[i]].second = time; }  
             else { q.push({start + next[i], time + 1}); p[start + next[i]].second = time + 1; }  
          }  
       }  
    }  
  
    cout << p[end].second;  
  
    return 0;  
}
