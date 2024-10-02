#include <iostream>
using namespace std;

int main(){
    const int numCell = 3;
    char board[numCell][numCell]{};
    int x, y, times = 0; // 사용자에게 입력받는 x, y좌표를 저장할 변수, 횟수를 저장하는 변수

    // 보드판 초기화
    for(x = 0; x < numCell; x++){
        for(y = 0; y < numCell; y++){
            board[x][y] = ' ';
        }
    }
    // 게임하는 코드
    int k = 0; //누구 차례인지 체크하기 위한 변수
    char currentUser = 'X'; //햔재 유저의 돌을 저장하기 위한 문자 변수

    // 보드판의 생김새를 보여주고 어느 곳이 어느 좌표인지를 확인시킴
    cout << "---|---|---" << endl;
    for(int i = 0; i < numCell; i++){
        cout << "   |   |   " << endl;
        cout << "---|---|---" << endl;
    }
    cout << "왼쪽 위가 (0,0)이고 오른쪽 아래가 (2,2)입니다.";

    while (true) {
        //1. 누구 차례인지 출력
        switch(k % 2){
        case 0:{
            cout << "첫번째 유저(X)의 차례입니다 -> ";
            currentUser = 'X';
            break;
        }
        case 1:{
            cout << "두번째 유저(O)의 차례입니다 -> ";
            currentUser = 'O';
            break;
        }
        }

        //2. 좌표 입력 받기
        cout << "(x,y) 좌표를 입력하세요 : ";
        cin >> x >> y;

        //3. 입력받은 좌표의 유효성 체크
        if(x >= numCell || y >= numCell){
            cout << x << ", " << y << ": ";
            cout << " x 와 y 둘 중 하나가 칸을 벗어납니다." << endl;
            continue;
        }
        if(board[x][y] != ' '){
            cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
            continue;
        }

        //4. 입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        // 5. 현재 보드 판 출력
        for(int i = 0; i < numCell; i++){
            cout << "---|---|---" << endl;
            for(int j = 0; j < numCell; j++){
                cout << board[i][j];
                if(j == numCell - 1){
                    break;
                }
                cout << "  |";
            }
            cout << endl;
        }
        cout << "---|---|---" << endl;
        k++, times++;
        

        //6. 빙고 시 승자 출력 후 종료
        for(int i = 0; i < numCell; i++){
            if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
                if(board[i][0] == 'X'){
                    cout << "첫번째 유저(X)가 승리했습니다.";
                }
                else if(board[i][0] == 'O'){
                    cout << "두번째 유저(O)가 승리했습니다.";
                }
                else
                    continue;
            }
            if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
                if(board[0][i] == 'X'){
                    cout << "첫번째 유저(X)가 승리했습니다.";
                }
                else if(board[0][i] == 'O'){
                    cout << "두번째 유저(O)가 승리했습니다.";
                }
                else
                    continue;
            }
        }
        if((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || (board[0][2] == board[1][1] && board[0][2] == board[2][0])){
            if(board[1][1] == 'X'){
                cout << "첫번째 유저(X)가 승리했습니다.";
            }
            else if(board[1][1] == 'O'){
                cout << "두번째 유저(O)가 승리했습니다.";
            }
            else
                continue;
        break;
        }

        //7. 모든 칸이 찼으면 종료
        if(times == 9){
            cout << "남은 칸이 없어 종료하겠습니다.";
            break;
        }
    }
    return 0;
}