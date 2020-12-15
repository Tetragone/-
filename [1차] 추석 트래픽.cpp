#include <string>
#include <vector>
#include <iostream>

using namespace std;

pair<int, int> startAndEnd(string);

int solution(vector<string> lines) {
    int answer = 0;
    int total_amount = lines.size();
    vector<pair<int, int>> traffic;
    
    for (auto x : lines) traffic.push_back(startAndEnd(x));

    for (int i = 0; i < total_amount; i++) {
        int counter = 0;
        
        for (int j = 0; j < total_amount; j++) {
            if (traffic[i].first < traffic[j].first) ;
            else if (traffic[i].first - 999 <= traffic[j].second) counter++;
        }
        
        answer = max(answer, counter);
    }
    return answer;
}

pair<int, int> startAndEnd(string input) {
    int start;
    int end;
    
    end = stoi(input.substr(11, 2)) * 3600000 + stoi(input.substr(14, 2)) * 60000 + stoi(input.substr(17, 2)) * 1000 + stoi(input.substr(20, 3));
    start = end - stoi(input.substr(24)) * 1000 + 1;
    if (input.size() > 26) start -= stoi(input.substr(26));
    cout << start << " " << end << endl;
    return pair<int, int>(start, end);    
}
