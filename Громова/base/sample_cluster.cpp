#include <iostream>
#include <string>
#include "cluster.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int tacts, size_queue, proccesor;
	cout << "Введите число тактов от 10 до 100;"<< endl;
	do {
		cin >> tacts;
	} while (tacts < 10 || tacts > 100);
	cout << "Введите количество процессоров в кластере:"<< endl;
	cin >> proccesor;
	cout << "Введите размер очереди от 10 до 30:" << endl;
	do {
		cin >> size_queue;
	} while (size_queue < 10 || size_queue > 30);
	Cluster m;
	m.Start(tacts, proccesor, size_queue);
	system("pause");
	return 0;
}