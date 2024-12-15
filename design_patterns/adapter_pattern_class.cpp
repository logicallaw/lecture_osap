// class adpater pattern
#include <iostream>
using namespace std;

class AirPods {
public:
	AirPods() { cout << "\n���� ������ Apple AirPods�Դϴ�." << endl; }
	void playing() { cout << "Apple AirPods ���� ��� �ߡ�" << endl; }
	void stopping() { cout << "Apple AirPods ������ �����մϴ�!" << endl; }
};

class Buds {
public:
	Buds() { cout << "���� �̾��� ȣȯ �ý���." << endl; }
	void play() { // ������ ����ϴ� ǥ�� API
		cout << "�Ｚ Buds ���� ��� �ߡ�" << endl;
	}
	void stop() { // ������ �����ϴ� ǥ�� API
		cout << "�Ｚ Buds ������ �����մϴ�!" << endl;
	}
};

class AirPodsInterface {
public:
	virtual void play() = 0;
	virtual void stop() = 0;
};

class AirPodsAdapter : public AirPods, public AirPodsInterface {
public:
	AirPodsAdapter() { cout << "AirPods�� SamsungPhone�� ȣȯ�˴ϴ�." << endl; }
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
		cout << "Buds�� ���� ������ AirPods�� �����մϴ�." << endl;
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
