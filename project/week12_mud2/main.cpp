#include <iostream>
#include <string>
#include <vector>
#include "user.h"

using namespace std;

const int map_x = 5;
const int map_y = 5;

// 사용자 정의 함수
bool CheckXY(int user_x, int map_x, int user_y, int map_y);
void DisplayMap(const vector<vector<int>> &map, const vector<int> &user_x, const vector<int> &user_y, const vector<User*> &users);
bool CheckGoal(const vector<vector<int>> &map, int user_x, int user_y);
void InteractWithTile(vector<vector<int>> &map, int user_x, int user_y, User &user);
bool CheckUser(const User &user);

// 메인 함수
int main() {
    string magician_name, warrior_name;

    cout << "Magician의 이름을 입력하세요 : ";
    cin >> magician_name;
    Magician magician(magician_name);

    cout << "Warrior의 이름을 입력하세요 : ";
    cin >> warrior_name;
    Warrior warrior(warrior_name);

    vector<User*> users = {&magician, &warrior};

    vector<vector<int>> map = {
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}
    };

    vector<int> user_x(users.size(), 0); // 각 유저의 x 좌표 초기화
    vector<int> user_y(users.size(), 0); // 각 유저의 y 좌표 초기화

    bool game_over = false;
    while (!game_over) {
        for (size_t i = 0; i < users.size(); ++i) {
            if (!CheckUser(*users[i])) {
                cout << users[i]->GetName() << "의 HP가 0이 되어 게임에서 탈락했습니다." << endl;
                continue;
            }

            cout << users[i]->GetName() << "의 차례입니다." << endl; 
            cout << "현재 HP: " << users[i]->GetHP() << endl;
            cout << "명령어를 입력하세요 (up, down, left, right, attack, map, info, exit): ";
            string user_input;
            cin >> user_input;

            if (user_input == "info") {
                cout << *users[i] << endl;
                continue;
            } else if (user_input == "attack") {
                users[i]->DoAttack();
            } else if (user_input == "up") {
                user_y[i] -= 1;
                if (!CheckXY(user_x[i], map_x, user_y[i], map_y)) {
                    cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                    user_y[i] += 1;
                    i--;
                    continue;
                } else {
                    users[i]->DecreaseHP(1);
                    DisplayMap(map, user_x, user_y, users);
                    InteractWithTile(map, user_x[i], user_y[i], *users[i]);
                }
            } else if (user_input == "down") {
                user_y[i] += 1;
                if (!CheckXY(user_x[i], map_x, user_y[i], map_y)) {
                    cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                    user_y[i] -= 1;
                    i--;
                    continue;
                } else {
                    users[i]->DecreaseHP(1);
                    DisplayMap(map, user_x, user_y, users);
                    InteractWithTile(map, user_x[i], user_y[i], *users[i]);
                }
            } else if (user_input == "left") {
                user_x[i] -= 1;
                if (!CheckXY(user_x[i], map_x, user_y[i], map_y)) {
                    cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                    user_x[i] += 1;
                    i--;
                    continue;
                } else {
                    users[i]->DecreaseHP(1);
                    DisplayMap(map, user_x, user_y, users);
                    InteractWithTile(map, user_x[i], user_y[i], *users[i]);
                }
            } else if (user_input == "right") {
                user_x[i] += 1;
                if (!CheckXY(user_x[i], map_x, user_y[i], map_y)) {
                    cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                    user_x[i] -= 1;
                    i--;
                    continue;
                } else {
                    users[i]->DecreaseHP(1);
                    DisplayMap(map, user_x, user_y, users);
                    InteractWithTile(map, user_x[i], user_y[i], *users[i]);
                }
            } else if (user_input == "map") {
                DisplayMap(map, user_x, user_y, users);
            } else if (user_input == "exit") {
                cout << users[i]->GetName() << "이(가) 게임을 종료했습니다." << endl;
                game_over = true;
                break;
            } else {
                cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
                continue;
            }

            if (CheckGoal(map, user_x[i], user_y[i])) {
                cout << users[i]->GetName() << "이(가) 목적지에 도착했습니다! 축하합니다!" << endl;
                game_over = true;
                break;
            }
        }
    }

    cout << "게임이 종료되었습니다." << endl;
    return 0;
}


void DisplayMap(const vector<vector<int>> &map, const vector<int> &user_x, const vector<int> &user_y, const vector<User*> &users) {
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            string players_here = "";  // 같은 장소에 있는 플레이어를 기록

            // 각 플레이어의 위치 확인
            for (size_t k = 0; k < users.size(); ++k) {
                if (user_x[k] == j && user_y[k] == i) {
                    if (dynamic_cast<Magician*>(users[k])) {
                        players_here += "M";  // Magician은 M
                    } else if (dynamic_cast<Warrior*>(users[k])) {
                        players_here += "W";  // Warrior는 W
                    }
                }
            }

            // 플레이어가 있는 경우 표시
            if (!players_here.empty()) {
                if (players_here.size() == 1) {
                    // 한 명만 있는 경우
                    cout << "  " << players_here << "   |";
                } else {
                    // 유저 둘 다 같은 장소에 있을 경우
                    cout << " " << players_here << "  |";
                }
            } else {
                // 플레이어가 없는 경우 기본 타일 출력
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
bool CheckXY(int user_x, int map_x, int user_y, int map_y) {
    return (user_x >= 0 && user_x < map_x && user_y >= 0 && user_y < map_y);
}

// 유저가 목적지에 도착했는지 확인하는 함수
bool CheckGoal(const vector<vector<int>> &map, int user_x, int user_y) {
    return map[user_y][user_x] == 4;
}


// 타일과 상호작용하는 함수
void InteractWithTile(vector<vector<int>> &map, int user_x, int user_y, User &user) {
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
