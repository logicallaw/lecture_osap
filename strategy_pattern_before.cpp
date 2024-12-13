#include <iostream>
using namespace std;

class Pokemon {
public:
    void introduce() {
        name();
        attack();
        passive();
    }
    virtual void name() {};
    virtual void attack() {};
    virtual void passive() {};
};

class Purin : public Pokemon {
public:
    void passive() override {
        cout << "패시브 스킬: 회피\n\n";
        // 회피: 30% 확률로 공격 회피 
    }
    void attack() override {
        cout << "공격 스킬: 노래하기\n";
        // 노래하기: 노래를 불러 상대를 잠재움
    }
    void name() override {
        cout << "이름: 푸린, 속성: 노멀\n";
    }
};

class Pairi : public Pokemon {
public:
    void passive() override {
        cout << "패시브 스킬: 방어\n\n";
        // 방어: 받는 피해를 40% 감소시킴 
    }
    void attack() override {
        cout << "공격 스킬: 불꽃\n";
        // 불꽃: 뜨거운 불꽃을 상대한테 쏨
    }
    void name() override {
        cout << "이름: 파이리, 속성: 불\n";
    }
};

class Pikachu : public Pokemon {
public:
    void passive() override {
        cout << "패시브 스킬: 스피드\n\n";
        // 스피드: 한 번에 두 번 공격함 
    }
    void attack() override {
        cout << "공격 스킬: 백만 볼트\n";
        // 백만 볼트: 백만 볼트의 강력한 전압으로 공격함
    }
    void name() override {
        cout << "이름: 피카츄, 속성: 번개\n";
    }
};

int main() {
    Pokemon* pikachu = new Pikachu();
    pikachu->introduce();

    Pokemon* purin = new Purin();
    purin->introduce();

    Pokemon* pairi = new Pairi();
    pairi->introduce();
    return 0;
}