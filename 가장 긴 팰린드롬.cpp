#include <string>

using namespace std;

int solution(string s) {
    int answer = 0;
    int slin = s.length();
    
    for (int i = 0; i < slin; i++) {
        int index = 1;
        int counter = 0;
        
        while (0 <= i - index && i + index < slin) {
            if (s.at(i - index) == s.at(i + index)) {
                counter++;
                index++;
            }
            else break;
        }
        
        counter = counter * 2 + 1;
        answer = max(answer, counter);
        
        index = 1;
        counter = 0;
        
        while (0 <= i - index + 1 && i + index < slin) {
            if (s.at(i - index + 1) == s.at(i + index)) {
                counter++;
                index++;
            }
            else break;
        }
        
        counter = counter * 2;
        answer = max(answer, counter);
    }
    
    return answer;
}
