#include <iostream>
#include <vector>
using namespace std;

int main(void){
    double sum,score, average;
    vector<double> scores;
    while(true){
        cout << "성적을 입력하시오(종료는 -1) : ";
        cin >> score;
        if(score == -1)
            break;
        scores.push_back(score);
        sum += score;
    }
    average = sum/scores.size();
    cout << "성적 평균 = " << average;
    return 0;
}