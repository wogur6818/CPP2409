#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class TempData{
public:
    int hour;
    double temperature;
};

int main()
{
    ifstream is( "temp.txt" );
    if(!is){
        cerr << "파일 오픈에 실패하였습니다" << endl;
        exit(1);
    }

    vector<TempData> Temps;
    int hour;
    double temperature;
    while(is >> hour >> temperature) {
        Temps.push_back(TempData{ hour, temperature });
    }
    for (TempData t : Temps){
        cout << t.hour << "시: 온도 " << t.temperature << endl;
    }
    return 0;
}