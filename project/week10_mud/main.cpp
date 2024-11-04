#include <iostream>
#include <string>
#include "user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void interactWithTile(int map[][mapX], int user_x, int user_y, User &user); // User 객체 참조 추가
bool CheckUser(const User &user); // const 참조로 전달

// 메인 함수
int main() {
    User user;
    // 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
    int map[mapY][mapX] = { {0, 1, 2, 0, 4},
                            {1, 0, 0, 2, 0},
                            {0, 0, 0, 0, 0},
                            {0, 2, 3, 0, 0},
                            {3, 0, 0, 0, 2} };

    // 유저의 위치를 저장할 변수
    int user_x = 0; // 가로 번호
    int user_y = 0; // 세로 번호

    // 게임 시작 
    while (true) { // 사용자에게 계속 입력받기 위해 무한 루프
        // HP가 0이면 종료
        if (!CheckUser(user)) {
            cout << "HP가 0이 되어 게임에 실패했습니다." << endl;
            break;
        }

        // 현재 HP출력과 다음 명령어 입력
        cout << "현재 HP: " << user.GetHP() << endl;
        cout << "명령어를 입력하세요 (up, down, left, right, map, exit): ";
        string user_input;
        cin >> user_input;

        if (user_input == "up") {
            // 위로 한 칸 올라가기
            user_y -= 1;
            bool inMap = checkXY(user_x, mapX, user_y, mapY);
            if (!inMap) { // 맵을 벗어났을 경우
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_y += 1;
            } else {
                cout << "위로 한 칸 올라갑니다." << endl;
                user.DecreaseHP(1); // 체력 감소
                displayMap(map, user_x, user_y);
                interactWithTile(map, user_x, user_y, user); // 타일과 상호작용
            }
        } else if (user_input == "down") {
            // 아래로 한 칸 내려가기
            user_y += 1;
            bool inMap = checkXY(user_x, mapX, user_y, mapY);
            if (!inMap) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_y -= 1;
            } else {
                cout << "아래로 한 칸 내려갑니다." << endl;
                user.DecreaseHP(1); // 체력 감소
                displayMap(map, user_x, user_y);
                interactWithTile(map, user_x, user_y, user); // 타일과 상호작용
            }
        } else if (user_input == "left") {
            // 왼쪽으로 이동하기
            user_x -= 1;
            bool inMap = checkXY(user_x, mapX, user_y, mapY);
            if (!inMap) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_x += 1;
            } else {
                cout << "왼쪽으로 이동합니다." << endl;
                user.DecreaseHP(1); // 체력 감소
                displayMap(map, user_x, user_y);
                interactWithTile(map, user_x, user_y, user); // 타일과 상호작용
            }
        } else if (user_input == "right") {
            // 오른쪽으로 이동하기
            user_x += 1;
            bool inMap = checkXY(user_x, mapX, user_y, mapY);
            if (!inMap) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_x -= 1;
            } else {
                cout << "오른쪽으로 이동합니다." << endl;
                user.DecreaseHP(1); // 체력 감소
                displayMap(map, user_x, user_y);
                interactWithTile(map, user_x, user_y, user); // 타일과 상호작용
            }
        } else if (user_input == "map") {
            // 지도 보여주기 함수 호출하는 명령어
            displayMap(map, user_x, user_y);
        } else if (user_input == "exit") {
            cout << "게임을 종료합니다." << endl;
            break;
        } else {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }

        // 목적지에 도달했는지 체크
        bool finish = checkGoal(map, user_x, user_y);
        if (finish) {
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }
    }
    return 0;
}

// 현재 상태의 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == user_y && j == user_x) {
                cout << " USER |"; // 양 옆 1칸 공백
            } else {
                int posState = map[i][j];
                switch (posState) {
                case 0:
                    cout << "      |"; // 6칸 공백
                    break;
                case 1:
                    cout << "아이템|";
                    break;
                case 2:
                    cout << "  적  |"; // 양 옆 2칸 공백
                    break;
                case 3:
                    cout << " 포션 |"; // 양 옆 1칸 공백
                    break;
                case 4:
                    cout << "목적지|";
                    break;
                }
            }
        }
        cout << endl;
        cout << " -------------------------------- " << endl;
    }
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
    return (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY);
}

// 유저가 목적지에 도착했는지 확인하는 함수
bool checkGoal(int map[][mapX], int user_x, int user_y) {
    return map[user_y][user_x] == 4;
}

// 타일과 상호작용하는 함수
void interactWithTile(int map[][mapX], int user_x, int user_y, User &user) {
    int tileType = map[user_y][user_x];
    switch (tileType) {
    case 1: // 무기 또는 갑옷을 발견
        cout << "아이템(무기/갑옷)을 발견했습니다!" << endl;
        break;
    case 2: // 적을 마주쳤을 경우
        cout << "적이 있습니다! 전투를 시작합니다!" << endl;
        user.DecreaseHP(2); // 적과 전투로 체력 감소
        cout << "적과 싸우는 중 체력이 2 감소했습니다. 현재 HP: " << user.GetHP() << endl;
        break;
    case 3: // 포션을 발견했을 경우
        cout << "포션을 발견하여 체력을 회복합니다!" << endl;
        user.IncreaseHP(2); // 체력 회복
        cout << "포션 사용 후 현재 HP: " << user.GetHP() << endl;
        break;
    case 4: // 목적지 (별도 메시지 필요 없음)
        break;
    default:
        cout << "이곳에는 아무것도 없습니다." << endl;
        break;
    }
}

bool CheckUser(const User &user){
    return user.GetHP() > 0;
}