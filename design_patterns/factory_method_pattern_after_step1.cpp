#include <iostream>
#include <string>
using namespace std;

// 추상 클래스 Games
class Games {
public:
    string title, version;

    virtual void BootingGame() {
        cout << "게임명: " << title << endl;
        cout << "게임 버전: " << version << endl;
        cout << title << " 게임이 실행 준비되었습니다.\n" << endl;
    }

    virtual void RunGame() {
        cout << title << "을 시작합니다.\n" << endl;
    }

    virtual ~Games() {} // 가상 소멸자
};

// SuperMario 클래스
class SuperMario : public Games {
public:
    SuperMario() {
        title = "Super Mario";
        version = "v1.0";
    }
};

// Tetris 클래스
class Tetris : public Games {
public:
    Tetris() {
        title = "Tetris";
        version = "v1.3";
    }
};

// GameServerFactory 클래스
class GameServerFactory {
public:
    GameServerFactory() : supermario(new SuperMario()), tetris(new Tetris()) {}

    ~GameServerFactory() {
        delete supermario;
        delete tetris;
    }

    Games* chooseGame(const string& game) {
        if (game == "supermario") {
            return supermario;
        }
        else if (game == "tetris") {
            return tetris;
        }
        else {
            cout << "지원하지 않는 게임입니다." << endl;
            return nullptr;
        }
    }
private:
    SuperMario* supermario;
    Tetris* tetris;
};

// GameServer 클래스
class GameServer {
public:
    GameServer() {
        cout << "GameServer-정상 연결 완료\n" << endl;
    }

    GameServer(GameServerFactory* gsf) : gsf(gsf) {
        cout << "GameServer-정상 연결 완료\n" << endl;
    }

    ~GameServer() {
        if (gsf) {
            delete gsf;
        }
    }

    void execute(const string& game) {
        Games* games = gsf->chooseGame(game);
        if (games != nullptr) {
            games->BootingGame();
            games->RunGame();
        }
    }
private:
    GameServerFactory* gsf;
};

// Main 함수
int main() {
    GameServer* gs = new GameServer(new GameServerFactory());
    gs->execute("supermario");
    gs->execute("tetris");
    delete gs;
    return 0;
}