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
        cout << "GameServer - ���� ���� �Ϸ�\n" << endl;
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
        cout << "���Ӹ�: " << title << endl;
        cout << "���� ����: " << version << endl;
        cout << title << " ������ ���� �غ�Ǿ����ϴ�.\n" << endl;
    }

    void RunGame() {
        cout << title << "�� �����մϴ�.\n" << endl;
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
            cout << "�������� �ʴ� �����Դϴ�." << endl;
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