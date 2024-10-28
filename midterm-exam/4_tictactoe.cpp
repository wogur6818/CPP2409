#include <iostream>
using namespace std;

int isValid(int x, int y, int numCell){
	int valid = 0;
	if (x >= numCell || y >= numCell) {// 좌표 범위를 벗어날때
		cout << x << "," << y << ": x와 y둘중 하나가 칸을 벗어납니다. " << endl;
		valid++;
	}

	return valid;
}

bool checkWin(char board[][], int currentUser, bool isWin){
	int check1 = 0,check2 = 0,check3 = 0, check4 =0;
	for (int i = 0; i < numCell; i++) {
		for(int j = 0; j < numCell; j++){
			if(board[j][i] == currentUser){
			check1++;
			}
		}
		for(int j = 0; j < numCell; j++){
			if(board[i][j] == currentUser){
			check2++;
			}
		}
		for(int i = 0; i < numCell; i++){
			int check2 = 0;
			if(board[i][i] == currentUser){
				check2++;
			}
		}
		for(int i = 0; i < numCell; i++){
			int check3 = 0;
			if(board[i][numCell - i - 1] == currentUser){
				check3++;
			}
		}	
	}
	if(check1 == numCell){
		cout << "가로에 모두 돌이 놓였습니다!!";
		iswin = true;
	}
	if(check2 == numCell){
		cout << "세로에 모두 돌이 놓였습니다!!";
		iswin = true;
	}
	if(check3 == numCell){
		cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!";
		iswin = true;
	}
	if(check3 == numCell){
		cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!";
		iswin = true;
	}
}

int main() {
	// 게임을 진행하는 데 필요한 변수 선언

	const int numCell = 5; // 보드판의 가로 세로 길이
	int k = 0; // 누구 차례인지 체크하기 위한 변수
	char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 변수
	char board[numCell][numCell]{}; // 보드판을 나타내는 2차원 배열
	int x, y = 0; // 사용자에게 xy좌표값을 입력받기 위한 변수

	// 보드판 초기화
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			board[i][j] = ' ';
		}
	}

	// 게임을 무한 반복
	while (true) {
		// 1. 누구 차례인지 출력
		// TODO 1.1: 3인용 게임으로 변경
		switch (k % 3) {
		case 0:
			currentUser = 'X';
			break;
		case 1:			
			currentUser = 'O';
			break;
		case 3:
			currentUser = 'H';
			break;
		}
		cout << k % 3 + 1 << "번 유저("<< currentUser <<")의 차례입니다. -> ";

		// 2. 좌표 입력 받기
		cout << "(x, y) 좌표를 입력하세요: ";
		int x, y;
		cin >> x >> y;

		// 3. 입력받은 좌표의 유효성 체크
		// TODO FUNC 1: isValid 함수 생성 후 호출
		if(isValid(x, y, numCell, board[x][y])== 1)
			continue;

		// 4. 입력받은 좌표에 현재 유저의 돌 놓기
		board[x][y] = currentUser;

		// 5. 현재 보드 판 출력
		// TODO 1.2: numCell 숫자에 맞춘 보드판 출력
		for (int i = 0; i < numCell; i++) {
			cout << "---|---|---|---|---" << endl;
			for (int j = 0; j < numCell; j++)
			{
				cout << board[i][j];
				if (j == numCell - 1) {
					break;
				}
				cout << "  |";
			}
			cout << endl;
		}
		cout << "---|---|---|---|---" << endl;



		bool isWin = false; // 승리 여부
		// TODO FUNC2: 6.1부터 6.2까지 checkWin 함수 생성 후 호출
		// 6.1. 가로/세로 돌 체크하기
		isWin = checkWin(char board[numCell][numCell]{}, currentUser, bool isWin);

		// 승리자가 결정되었으면 해당 플레이어를 출력하고 게임을 종료한다.
		if (isWin == true) {
			cout << k % 3 + 1<< "번 유저(" << currentUser << ")의 승리입니다!" << endl;
			break;
		}

		// 7. 모든 칸 다 찼는지 체크하기
		int checked = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		if (checked == 0) {
			cout << "모든 칸이 다 찼습니다.  종료합니다. " << endl;
			break;
		}

		k++;
	}

	return 0;
}