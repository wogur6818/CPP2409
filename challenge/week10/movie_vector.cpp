#include <iostream>
#include <vector>
using namespace std;

struct Movie{
    string name;
    double rating;
};

int main(void){
    int numMovie;
    vector<Movie> movies;

    cout << "무비의 수를 입력하세요 : ";
    cin >> numMovie;
    for(int i = 0; i < numMovie; i++){
        Movie movie;
        cout << "무비" << i+1 << "의 이름을 입력하세요 : ";
        cin >> movie.name;
        cout << "무비" << i+1 << "의 평점을 입력하세요 : ";
        cin >> movie.rating;
        movies.push_back(movie);
    }
    for(int i = 0; i < movies.size(); i++){
        cout << movies[i].name << ": " << movies[i].rating << endl;
    }
    return 0;
}