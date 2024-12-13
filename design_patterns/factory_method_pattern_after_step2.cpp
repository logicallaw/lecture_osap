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

  virtual void RunGame() { cout << title << "�� �����մϴ�.\n" << endl; }

  virtual ~Games() {} // ���� �Ҹ���
};

// Korean SuperMario Ŭ����
class KRSuperMario : public Games {
public:
  KRSuperMario() {
    title = "Super Mario_Korean";
    version = "v1.0";
  }
};

// Korean Tetris Ŭ����
class KRTetris : public Games {
public:
  KRTetris() {
    title = "Tetris_Korean";
    version = "v1.3";
  }
};

// Japanese SuperMario Ŭ����
class JPSuperMario : public Games {
public:
  JPSuperMario() {
    title = "Super Mario_Japanese";
    version = "v1.1";
  }
};

// Japanese Tetris Ŭ����
class JPTetris : public Games {
public:
  JPTetris() {
    title = "Tetris_Japanese";
    version = "v1.12";
  }
};

// GameServer Ŭ����
class GameServer {
public:
  GameServer() { cout << "GameServer-���� ���� �Ϸ�\n" << endl; }

  void execute(const string &game) {
    Games *games = chooseGame(game);
    if (games != nullptr) {
      games->BootingGame();
      games->RunGame();
    }
  }

protected:
  virtual Games *chooseGame(const string &game) = 0;
};

// KRGameServer Ŭ����
class KRGameServer : public GameServer {
public:
  KRGameServer() : supermario(new KRSuperMario()), tetris(new KRTetris()) {}

  ~KRGameServer() {
    delete supermario;
    delete tetris;
  }

  Games *chooseGame(const string &game) override {
    if (game == "supermario") {
      return supermario;
    } else if (game == "tetris") {
      return tetris;
    } else {
      cout << "�������� �ʴ� �����Դϴ�." << endl;
      return nullptr;
    }
  }

private:
  KRSuperMario *supermario;
  KRTetris *tetris;
};

// JPGameServer Ŭ����
class JPGameServer : public GameServer {
public:
  JPGameServer() : supermario(new JPSuperMario()), tetris(new JPTetris()) {}

  ~JPGameServer() {
    delete supermario;
    delete tetris;
  }

  Games *chooseGame(const string &game) override {
    if (game == "supermario") {
      return supermario;
    } else if (game == "tetris") {
      return tetris;
    } else {
      cout << "�������� �ʴ� �����Դϴ�." << endl;
      return nullptr;
    }
  }

private:
  JPSuperMario *supermario;
  JPTetris *tetris;
};

// Main �Լ�
int main() {
  GameServer *gs = new KRGameServer();
  gs->execute("supermario");
  delete gs;

  gs = new JPGameServer();
  gs->execute("tetris");
  delete gs;

  return 0;
}
