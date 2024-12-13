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

  virtual void RunGame() { cout << title << "을 시작합니다.\n" << endl; }

  virtual ~Games() {} // 가상 소멸자
};

// Korean SuperMario 클래스
class KRSuperMario : public Games {
public:
  KRSuperMario() {
    title = "Super Mario_Korean";
    version = "v1.0";
  }
};

// Korean Tetris 클래스
class KRTetris : public Games {
public:
  KRTetris() {
    title = "Tetris_Korean";
    version = "v1.3";
  }
};

// Japanese SuperMario 클래스
class JPSuperMario : public Games {
public:
  JPSuperMario() {
    title = "Super Mario_Japanese";
    version = "v1.1";
  }
};

// Japanese Tetris 클래스
class JPTetris : public Games {
public:
  JPTetris() {
    title = "Tetris_Japanese";
    version = "v1.12";
  }
};

// GameServer 클래스
class GameServer {
public:
  GameServer() { cout << "GameServer-정상 연결 완료\n" << endl; }

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

// KRGameServer 클래스
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
      cout << "지원하지 않는 게임입니다." << endl;
      return nullptr;
    }
  }

private:
  KRSuperMario *supermario;
  KRTetris *tetris;
};

// JPGameServer 클래스
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
      cout << "지원하지 않는 게임입니다." << endl;
      return nullptr;
    }
  }

private:
  JPSuperMario *supermario;
  JPTetris *tetris;
};

// Main 함수
int main() {
  GameServer *gs = new KRGameServer();
  gs->execute("supermario");
  delete gs;

  gs = new JPGameServer();
  gs->execute("tetris");
  delete gs;

  return 0;
}
