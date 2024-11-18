#include <iostream>
#include <string>
#include <vector>
#include "user.h"

using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(const vector<vector<int>> &map, int user_x, int user_y);
bool checkGoal(const vector<vector<int>> &map, int user_x, int user_y);
void interactWithTile(vector<vector<int>> &map, int user_x, int user_y, User &user);
bool CheckUser(const User &user);

// 메인 함수
int main() {
    vector<User> users; // 여러 유저 객체를 관리할 벡터
    int num_users;
    
    // 유저 수 입력
    cout << "게임에 참여할 유저 수를 입력하세요: ";
    cin >> num_users;
    
    // 유저 수 만큼 유저 객체 생성
    for (int i = 0; i < num_users; ++i) {
        users.push_back(User());
    }
    
    // 맵을 2차원 벡터로 선언
    vector<vector<int>> map = {
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}
    };

    // 각 유저의 위치를 저장할 변수들
    vector<int> user_x(num_users, 0); // 각 유저의 x 좌표 초기화
    vector<int> user_y(num_users, 0); // 각 유저의 y 좌표 초기화

    // 게임 시작 
    bool game_over = false;
    while (!game_over) {
        for (int i = 0; i < num_users; ++i) {
            // 현재 유저가 게임을 계속할 수 있는지 확인
            if (!CheckUser(users[i])) {
                cout << "유저 " << i + 1 << "의 HP가 0이 되어 게임에서 탈락했습니다." << endl;
                continue;
            }

            // 현재 유저의 HP와 명령어 입력
            cout << "\n유저 " << i + 1 << "의 차례입니다." << endl;
            cout << "현재 HP: " << users[i].GetHP() << endl;
            cout << "명령어를 입력하세요 (up, down, left, right, map, info, exit): ";
            string user_input;
            cin >> user_input;

            if (user_input == "info") {
                cout << users[i] << endl;
                continue;
            }

            if (user_input == "up") {
                user_y[i] -= 1;
                if (!checkXY(user_x[i], mapX, user_y[i], mapY)) {
                    cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                    user_y[i] += 1;
                } else {
                    users[i].DecreaseHP(1);
                    displayMap(map, user_x[i], user_y[i]);
                    interactWithTile(map, user_x[i], user_y[i], users[i]);
                }
            } else if (user_input == "down") {
                user_y[i] += 1;
                if (!checkXY(user_x[i], mapX, user_y[i], mapY)) {
                    cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                    user_y[i] -= 1;
                } else {
                    users[i].DecreaseHP(1);
                    displayMap(map, user_x[i], user_y[i]);
                    interactWithTile(map, user_x[i], user_y[i], users[i]);
                }
            } else if (user_input == "left") {
                user_x[i] -= 1;
                if (!checkXY(user_x[i], mapX, user_y[i], mapY)) {
                    cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                    user_x[i] += 1;
                } else {
                    users[i].DecreaseHP(1);
                    displayMap(map, user_x[i], user_y[i]);
                    interactWithTile(map, user_x[i], user_y[i], users[i]);
                }
            } else if (user_input == "right") {
                user_x[i] += 1;
                if (!checkXY(user_x[i], mapX, user_y[i], mapY)) {
                    cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                    user_x[i] -= 1;
                } else {
                    users[i].DecreaseHP(1);
                    displayMap(map, user_x[i], user_y[i]);
                    interactWithTile(map, user_x[i], user_y[i], users[i]);
                }
            } else if (user_input == "map") {
                displayMap(map, user_x[i], user_y[i]);
            } else if (user_input == "exit") {
                cout << "유저 " << i + 1 << "이(가) 게임을 종료했습니다." << endl;
                game_over = true;
                break;
            } else {
                cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
                continue;
            }

            // 목적지 도달 여부 확인
            if (checkGoal(map, user_x[i], user_y[i])) {
                cout << "유저 " << i + 1 << "이(가) 목적지에 도착했습니다! 축하합니다!" << endl;
                game_over = true;
                break;
            }
        }
    }

    cout << "게임이 종료되었습니다." << endl;
    return 0;
}

void displayMap(const vector<vector<int>> &map, int user_x, int user_y) {
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (i == user_y && j == user_x) {
                cout << " USER |";
            } else {
                switch (map[i][j]) {
                    case 0: cout << "      |"; break;
                    case 1: cout << "아이템|"; break;
                    case 2: cout << "  적  |"; break;
                    case 3: cout << " 포션 |"; break;
                    case 4: cout << "목적지|"; break;
                }
            }
        }
        cout << endl << " -------------------------------- " << endl;
    }
}


bool CheckUser(const User &user) {
    return user.GetHP() > 0;
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
    return (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY);
}

// 유저가 목적지에 도착했는지 확인하는 함수
bool checkGoal(const vector<vector<int>> &map, int user_x, int user_y) {
    return map[user_y][user_x] == 4;
}


// 타일과 상호작용하는 함수
void interactWithTile(vector<vector<int>> &map, int user_x, int user_y, User &user) {
    int tileType = map[user_y][user_x];
    switch (tileType) {
        case 1: // 아이템을 먹음
            cout << "아이템을 발견했습니다!" << endl;
            user.IncreaseItemCount();
            break;
        case 2: // 적과 조우
            cout << "적이 나타났습니다! 전투 시작!" << endl;
            user.DecreaseHP(2);
            cout << "적과 싸우는 중 체력이 2 감소했습니다. 현재 HP: " << user.GetHP() << endl;
            break;
        case 3: // 포션 발견
            cout << "포션을 발견했습니다! 체력 회복!" << endl;
            user.IncreaseHP(2);
            cout << "포션 사용 후 현재 HP: " << user.GetHP() << endl;
            break;
        default:
            cout << "이곳에는 아무것도 없습니다." << endl;
            break;
    }
}
