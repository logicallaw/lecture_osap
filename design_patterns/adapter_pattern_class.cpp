// class adpater pattern
#include <iostream>
using namespace std;

class AirPods {
public:
	AirPods() { cout << "\n새로 구입한 Apple AirPods입니다." << endl; }
	void playing() { cout << "Apple AirPods 음악 재생 중…" << endl; }
	void stopping() { cout << "Apple AirPods 음악을 중지합니다!" << endl; }
};

class Buds {
public:
	Buds() { cout << "무선 이어폰 호환 시스템." << endl; }
	void play() { // 음악을 재생하는 표준 API
		cout << "삼성 Buds 음악 재생 중…" << endl;
	}
	void stop() { // 음악을 정지하는 표준 API
		cout << "삼성 Buds 음악을 중지합니다!" << endl;
	}
};

class AirPodsInterface {
public:
	virtual void play() = 0;
	virtual void stop() = 0;
};

class AirPodsAdapter : public AirPods, public AirPodsInterface {
public:
	AirPodsAdapter() { cout << "AirPods이 SamsungPhone과 호환됩니다." << endl; }
	void play() override { playing(); }
	void stop() override { stopping(); }
};

class SamsungPhone {
	Buds *buds;
	AirPodsAdapter *airpodsadapter;

public:
	SamsungPhone() : buds(new Buds()), airpodsadapter(nullptr) {
		installAirPods();
		cout << endl;
		testBuds();
		cout << endl;
		testAirPods();
	}

	~SamsungPhone() {
		delete buds;
		if (airpodsadapter)
			delete airpodsadapter;
	}

	void installAirPods() {
		airpodsadapter = new AirPodsAdapter();
		cout << "Buds와 새로 구입한 AirPods을 연결합니다." << endl;
	}

	void testBuds() {
		buds->play();
		buds->stop();
	}

	void testAirPods() {
		if (airpodsadapter) {
			airpodsadapter->play();
			airpodsadapter->stop();
		}
	}
};

int main() {
	SamsungPhone samsungphone;
	return 0;
}
