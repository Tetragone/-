#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    int aize = a.size();
    int minvalue = 1000000009;
    int counter = 0;
    int standard = a[0];
    int position;
    
    for (int i = 0; i < aize; i++) {
        if (minvalue > a[i]) {
            minvalue = a[i];
            position = i;
        }
    }

    for (int i = 0; i < position; i++) {
        if (standard >= a[i]) {
            standard = a[i];
            counter++;
        }
    }
    
    standard = a.back();
    
    for (int i = aize - 1; i >= position; i--) {
        if (standard >= a[i]) {
            standard = a[i];
            counter++;
        }
    }
    
    answer = counter;
    return answer;
}
