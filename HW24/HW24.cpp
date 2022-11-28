#include <iostream>

void fill_arr(int* const arr, const int length, int value) {
	for (int i = 0; i < length; i++)
		arr[i] = rand() % value;
}


void show_arr(int arr[], const int length) {
	std::cout << "[";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}

// Задание 2. Изменение длинны массива.
void resize_arr(int*& arr, const int length, int newlength) {
	
	if (newlength <= 0) {
		std::cout << " Ошибка: длинна массива должнабыть больше нуля!\n";
		return;
	}
	int* newArr = new int[length + newlength]{};

	for (int i = 0; i < length; i++)
		newArr[i] = arr[i];

	delete[] arr;

	arr = newArr;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int x, y;

	// Задание 1. Объединение массивов.
	
	std::cout << "\t\tЗадание 1.\n Объединение массивов.\n";
	
	std::cout << " Введите размер первого массива --> ";
	std::cin >> x;
	std::cout << " Введите размер второго массива --> ";
	std::cin >> y;

	int* arr1 = new int[x];
	int* arr2 = new int[y];
	int* arr3 = new int[x + y];

	std::cout << " Изначальный первый массив -->\t";
	fill_arr(arr1, x, 10);
	show_arr(arr1, x);

	std::cout << " Изначальный второй массив -->\t";
	fill_arr(arr2, y, 25);
	show_arr(arr2, y);

	for (int i = 0; i < x; i++)
		arr3[i] = arr1[i];
	for (int i = x; i < (x + y); i++)
		arr3[i] = arr2[i - x];
	std::cout << " Новый массив -->\t";
	show_arr(arr3, (x + y));


	delete[] arr1;
	arr1 = nullptr;
	delete[] arr2;
	arr2 = nullptr;


	// Задание 2. Изменение длинны массива.

	std::cout << "\t\tЗадание 2.\n Изменение длинны массива.\n";
	std::cout << " Введите размер массива -->\t";
	std::cin >> x;
	int* arr4 = new int[x];

	std::cout << " Изначальный массив -->\t";
	fill_arr(arr4, x, 25);
	show_arr(arr4, x);

	std::cout << " Введите новую длину массива -->\t";
	std::cin >> y;

	resize_arr(arr4, x, y);
	x = y;
	std::cout << " Увеличенный массив -->\t";
	show_arr(arr4, x);

	delete[] arr4;
	arr4 = nullptr;

	return 0;
}