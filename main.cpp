#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

//untuk menambahkan delay pada thread.
void delay(int t) {
	this_thread::sleep_for(chrono::milliseconds(t));
}

//thread oddnumber / ganjil.
void oddnumber(int x) {
	for (int i = 1; i <= x; i++) {
		if (i % 2 != 0) {
			delay(1000);//delay 1 second
			cout << "pesanan No." << i << " (Oddnumber)" << endl;
			cout << "waktu delay 1 second" << endl << endl;
		}
	}
}

//thread evennumber / genap.
void evennumber(int y) {
	for (int i = 1; i <= y; i++) {
		if (i % 2 == 0) {
			delay(2500);//delay 2,5 second
			cout << "pesanan No." << i << " (evennumber)" << endl;
			cout << "waktu delay 2.5 seconds" << endl << endl;
		}
	}
}

int main() {
	//untuk print odd dan even.
	thread Charis(oddnumber,20);
	thread Ali(evennumber,20);

	//untuk synchronization thread.
	//dan memastikan thread hingga selesai.
	Charis.join();
	Ali.join();

	cout << "Semua pesanan sudah siap" << endl;
	return 0;
}
