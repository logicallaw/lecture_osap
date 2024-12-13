#include <iostream>
using namespace std;

class Attack {
public:
    virtual void motion() = 0;
};

class Sing : public Attack {
public:
    void motion() override {
        cout << "공격 스킬 - 노래하기: 노래를 불러 상대를 잠재움\n";
    }
};

class Flame : public Attack {
public:
    void motion() override {
        cout << "공격 스킬 - 불꽃: 뜨거운 불꽃을 쏘아 공격\n";
    }
};

class millionVolt : public Attack {
public:
    void motion() override {
        cout << "공격 스킬 - 백만 볼트: 백만 볼트의 강력한 전압으로 공격\n";
    }
};

class Passive {
public:
    virtual void detail() = 0;
};

class Defensibility : public Passive {
public:
    void detail() override {
        cout << "패시브 스킬 - 방어: 받는 피해 40% 감소시킴\n\n";
    }
};

class Avoidability : public Passive {
public:
    void detail() override {
        cout << "패시브 스킬 - 회피: 30% 확률로 공격 회피\n\n";
    }
};

class Speedability : public Passive {
public:
    void detail() override {
        cout << "패시브 스킬 - 스피드: 한 번에 두 번 공격\n\n";
    }
};

class Pokemon {
public:
    Attack* attack;
    Passive* passive;
    Pokemon() {}

    void introduce() {
        name();
        attack->motion();
        passive->detail();
    }
    virtual void name() {}
    void setAttack(Attack* attack) {
        this->attack = attack;
    }
    void setPassive(Passive* passive) {
        this->passive = passive;
    }
};

class Pairi : public Pokemon {
public:
    Pairi() {
        attack = new Flame();
        passive = new Defensibility();
    }
    void name() {
        cout << "이름: 파이리, 속성: 불\n";
    }
};

class Purin : public Pokemon {
public:
    Purin() {
        attack = new Sing();
        passive = new Avoidability();
    }
    void name() {
        cout << "이름: 푸린, 속성: 노멀\n";
    }
};

class Pikachu : public Pokemon {
public:
    Pikachu() {
        attack = new millionVolt();
        passive = new Speedability();
    }
    void name() {
        cout << "이름: 피카츄, 속성: 번개\n";
    }
};

int main() {
    Pokemon* pikachu = new Pikachu();
    pikachu->introduce();

    Pokemon* pairi = new Pairi();
    pairi->introduce();

    Pokemon* purin = new Purin();
    purin->introduce();

    purin->setAttack(new millionVolt());
    purin->setPassive(new Defensibility());
    purin->introduce();
    return 0;
}