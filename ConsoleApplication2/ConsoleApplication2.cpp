
////F[N]-массив с исходными значениями функции, Result_F[N]-итоговый массив,
////a-начало отрезка,b-конец отрезка, dx-шаг изменения аргумента, x-аргумент, lastpx-последнее положительное значение функции в массиве F
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

int main() {
	setlocale(LC_ALL, "Ru");
	const int N = 30;
	double  F[N], a, b, Result_F[N];
	printf("Введите начало отрезка a=");
	scanf_s("%lf", &a);
	printf("Введите конец отрезка b=");
	scanf_s("%lf", &b);
	double dx = (b - a) / (N - 1);
	std::cout << "Шаг изменения dx=" << dx << std::endl;
	std::cout << "\nИсходные значения функции:" << std::endl;
	for (int i = 0; i < N; i++) {
		double x = a + i * dx;
		F[i] = exp(-x) * sin(6 * x);
		std::cout << F[i] << std::endl;
	}
	double lastpx = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (F[i] > 0) {
			lastpx = F[i];
			break;
		}
	}
	if (lastpx == 0) {
		std::cout << "\nОшибка!Не найдено положительных значений!" << std::endl;
		return 1;
	}
	std::cout << "\nПоследнее положительное значение:  " << lastpx << std::endl;
	std::cout << "\nИтоговый массив:" << std::endl;
	for (int i = 0; i < N; i++) {
		Result_F[i] = F[i] / lastpx;
		std::cout << Result_F[i] << "" << std::endl;
	}
	system("pause");
	return 0;
}


////text - строка для хранения всего введенного текста, result - строка для хранения ФИО героев ВОВ, p - переменная для отслеживания текущей позиции в тексте
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//	setlocale(LC_ALL, "Russian");
//	string text;
//	string result = "";
//	cout << "Введите текст (для завершения введите пустую строку) " << endl;
//	while (true) {
//		string line;
//		getline(cin, line);
//		if (line.empty()) {
//			break;
//		}
//		text += line + "\n";
//	}
//	int p = 0;
//	while (p < text.length()) {
//		int start_tag = text.find("<strong>", p);
//		if (start_tag == string::npos) {
//			break;
//		}
//		int end_tag = text.find("</strong>", start_tag + 8);
//		if (end_tag != string::npos) {
//			int name_start = start_tag + 8;
//			int name_length = end_tag - name_start;
//			string name = text.substr(name_start, name_length);
//			result += name + "\n";
//			p = end_tag + 9;
//		}
//		else {
//			p = start_tag + 8;
//		}
//	}
//	cout << "\nНайденные ФИО героев" << endl;
//	if (result.empty()) {
//		cout << "Ничего не найено" << endl;
//	}
//	else {
//		cout << result;
//	}
//	return 0;
//}