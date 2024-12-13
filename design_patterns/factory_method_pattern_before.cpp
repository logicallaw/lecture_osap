#include <iostream>
#include <string>
using namespace std;

class SuperMario {
public:
    string returnTitle() { return "Super Mario"; }
    string returnVersion() { return "v1.0"; }
};

class Tetris {
public:
    string returnTitle() { return "Tetris"; }
    string returnVersion() { return "v1.3"; }
};

class GameServer {
public:
    SuperMario* supermario;
    Tetris* tetris;
    string title;
    string version;

    GameServer() : supermario(new SuperMario()), tetris(new Tetris()) {
        cout << "GameServer - 정상 연결 완료\n" << endl;
    }
    ~GameServer() {
        delete supermario;
        delete tetris;
    }

    void Game_Play(const string& game) {
        choiceGame(game);
        Start();
    }

private:
    void Start() {
        BootingGame();
        RunGame();
    }

    void BootingGame() {
        cout << "게임명: " << title << endl;
        cout << "게임 버전: " << version << endl;
        cout << title << " 게임이 실행 준비되었습니다.\n" << endl;
    }

    void RunGame() {
        cout << title << "을 시작합니다.\n" << endl;
    }

    void choiceGame(const string& game) {
        if (game == "supermario") {
            title = supermario->returnTitle();
            version = supermario->returnVersion();
        }
        else if (game == "tetris") {
            title = tetris->returnTitle();
            version = tetris->returnVersion();
        }
        else {
            cout << "지원하지 않는 게임입니다." << endl;
        }
    }
};

int main() {
    GameServer* server = new GameServer();
    server->Game_Play("supermario");
    server->Game_Play("tetris");
    delete server;
    return 0;
}