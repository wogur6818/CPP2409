#include <iostream>
#include <string>
#include <vector>
#include "user.h"

using namespace std;

// 맵 크기
const int map_x = 5;
const int map_y = 5;

// 사용자 정의 함수
bool CheckXY(int user_x, int map_x, int user_y, int map_y);
void DisplayMap(const vector<vector<int>> &map, int user_x, int user_y, const string &player_icon);
bool CheckGoal(const vector<vector<int>> &map, int user_x, int user_y);
void InteractWithTile(vector<vector<int>> &map, int user_x, int user_y, User &user);

// 메인 함수
int main() {
    User *player = null_ptr;

    // 직업 선택
    cout << "직업(숫자)을 선택하세요 (1: Magician, 2: Warrior): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        string name;
        cout << "Magician의 이름을 입력하세요: ";
        cin >> name;
        player = new Magician(name);
    } else if (choice == 2) {
        string name;
        cout << "Warrior의 이름을 입력하세요: ";
        cin >> name;
        player = new Warrior(name);
    } else {
        cout << "잘못된 선택입니다. 프로그램을 종료합니다." << endl;
        return 1;
    }

    // 맵 초기화
    vector<vector<int>> map = {
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}
    };

    int user_x = 0; // 플레이어의 x 좌표
    int user_y = 0; // 플레이어의 y 좌표

    bool game_over = false;
    while (!game_over) {
        // 현재 맵 표시
        DisplayMap(map, user_x, user_y, player->GetIcon());

        // 플레이어 상태 표시
        cout << "현재 HP: " << player->GetHP() << endl;
        cout << "명령어를 입력하세요 (up, down, left, right, attack, exit): ";
        string command;
        cin >> command;

        if (command == "up") {
            user_y -= 1;
            if (!CheckXY(user_x, map_x, user_y, map_y)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_y += 1;
            } else {
                player->DecreaseHP(1);
                InteractWithTile(map, user_x, user_y, *player);
            }
        } else if (command == "down") {
            user_y += 1;
            if (!CheckXY(user_x, map_x, user_y, map_y)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_y -= 1;
            } else {
                player->DecreaseHP(1);
                InteractWithTile(map, user_x, user_y, *player);
            }
        } else if (command == "left") {
            user_x -= 1;
            if (!CheckXY(user_x, map_x, user_y, map_y)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_x += 1;
            } else {
                player->DecreaseHP(1);
                InteractWithTile(map, user_x, user_y, *player);
            }
        } else if (command == "right") {
            user_x += 1;
            if (!CheckXY(user_x, map_x, user_y, map_y)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_x -= 1;
            } else {
                player->DecreaseHP(1);
                InteractWithTile(map, user_x, user_y, *player);
            }
        } else if (command == "attack") {
            player->DoAttack();
        } else if (command == "exit") {
            cout << "게임을 종료합니다." << endl;
            game_over = true;
        } else {
            cout << "잘못된 명령어입니다. 다시 입력하세요." << endl;
        }

        if (CheckGoal(map, user_x, user_y)) {
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            game_over = true;
        }
    }

    delete player;
    return 0;
}

// 맵 표시 함수
void DisplayMap(const vector<vector<int>> &map, int user_x, int user_y, const string &player_icon) {
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (i == user_y && j == user_x) {
                cout << "  " << player_icon << "   |";
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

// 좌표 유효성 확인 함수
bool CheckXY(int user_x, int map_x, int user_y, int map_y) {
    return (user_x >= 0 && user_x < map_x && user_y >= 0 && user_y < map_y);
}

// 목표 확인 함수
bool CheckGoal(const vector<vector<int>> &map, int user_x, int user_y) {
    return map[user_y][user_x] == 4;
}

// 타일 상호작용 함수
void InteractWithTile(vector<vector<int>> &map, int user_x, int user_y, User &user) {
    int tileType = map[user_y][user_x];
    switch (tileType) {
        case 1:
            cout << "아이템을 발견했습니다!" << endl;
            user.IncreaseItemCount();
            break;
        case 2:
            cout << "적을 만났습니다! 전투를 시작합니다." << endl;
            user.DecreaseHP(2);
            break;
        case 3:
            cout << "포션을 발견했습니다! 체력을 회복합니다." << endl;
            user.IncreaseHP(5);
            break;
        case 4:
            break;
        default:
            cout << "아무것도 없습니다." << endl;
            break;
    }
}
