#include <iostream>
#include <string>
using namespace std;

// �߻� Ŭ���� Games
class Games {
public:
    string title, version;

    virtual void BootingGame() {
        cout << "���Ӹ�: " << title << endl;
        cout << "���� ����: " << version << endl;
        cout << title << " ������ ���� �غ�Ǿ����ϴ�.\n" << endl;
    }

    virtual void RunGame() {
        cout << title << "�� �����մϴ�.\n" << endl;
    }

    virtual ~Games() {} // ���� �Ҹ���
};

// SuperMario Ŭ����
class SuperMario : public Games {
public:
    SuperMario() {
        title = "Super Mario";
        version = "v1.0";
    }
};

// Tetris Ŭ����
class Tetris : public Games {
public:
    Tetris() {
        title = "Tetris";
        version = "v1.3";
    }
};

// GameServerFactory Ŭ����
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
            cout << "�������� �ʴ� �����Դϴ�." << endl;
            return nullptr;
        }
    }
private:
    SuperMario* supermario;
    Tetris* tetris;
};

// GameServer Ŭ����
class GameServer {
public:
    GameServer() {
        cout << "GameServer-���� ���� �Ϸ�\n" << endl;
    }

    GameServer(GameServerFactory* gsf) : gsf(gsf) {
        cout << "GameServer-���� ���� �Ϸ�\n" << endl;
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

// Main �Լ�
int main() {
    GameServer* gs = new GameServer(new GameServerFactory());
    gs->execute("supermario");
    gs->execute("tetris");
    delete gs;
    return 0;
}