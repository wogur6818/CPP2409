#include <iostream>
#include <string>
using namespace std;

string toLowerStr(string str){
    for (char &c : str){
        c = tolower(c);    
    }
    return str;
}

int calcHammingDist(string s1, string s2, string s3){
    int count = 0;
    s1 = toLowerStr(s1);
    s2 = toLowerStr(s2);
	s3 = toLowerStr(s3);
    for(int i = 0; i < s1.length(); i++){
        if (s1[i] != s2[i] || s2[i] != s3[i])
            count += 1;
    }
    return count;
}

int main() {
	cout << "문자열 3개에 대한 hamming distance를 구하는 프로그램입니다. " << endl;
	int count = 0; // distance 계산을 위한 변수

	string s1, s2, s3;
	cout << "1번 문자열을 입력하세요. (공백 없이): ";
	cin >> s1;
	cout << "2번 문자열을 입력하세요. (공백 없이): ";
	cin >> s2;
	cout << "3번 문자열을 입력하세요. (공백 없이): ";
	cin >> s3;

	if(s1.length() != s2.length() || s2.length() != s3.length()) // TODO1: 문자열 길이를 비교하고 에러를 체크하는 코드 블록 작성
        cout << "세 문자열의 길이가 다릅니다. 프로그램을 종료합니다." << endl;
	else // TODO2: 대소문자 구분없이 해밍 거리를 계산하기 위한 코드 블록 작성
	{
        int count = calcHammingDist(s1, s2, s3);
        cout << "해밍 거리는 " << count << "입니다." << endl; // 해밍 거리 출력 코드
    }

	return 0;
}