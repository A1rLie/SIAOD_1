#include <iostream>

using namespace std;

//Заполняет массив
void Fill_array(int array[], int length) 
{
	for (int i = 0; i < length; i++)
	{
		cin >> array[i];
		if (array[i] < 0)
		{
			cout << "Число не может быть меньше 0, для данного элементо будет выбрано значение 0" << endl;
			array[i] = 0;
		}
	}
}

//Вывод все элементы массива
void Show_array(int array[], int length) 
{
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

//Проверка числа на цифровой корень
bool Digital_root(int x) 
{
	if (x / 10 <= 0 && x == 7) return true; //Если число однозначное и равно 7, то вовзрат истины
	else if (x / 10 <= 0 && x != 7) return false; //Если число однозначное и не равно 7, то возврат лжи
	else
	{
		int sum = 0;
		while (x > 0)
		{
			sum += x % 10;
			x /= 10;
		}
		return Digital_root(sum); //Рекурсивное определение цифрового корня
	}
}

//Поиск индекса
int Search_key(int array[],int length) 
{
	for (int i = 0; i < length; i++)
	{
		if (Digital_root(array[i])) return i;
	}
	return -1;
}

//Копирование массива и вставка числа перед корнем
int Array_copy_and_insert(int array[], int& length, int numNew)
{
	int flag = 0; //Флаг для определения наличия цифрового корня
	for (int i = 0; i < length; i++)
	{
		if (Digital_root(array[i]))
		{
			flag++;
			if (flag > 1) return flag;
		}
	}
	if (flag == 0) return 0;

	for (int i = 0; i < length; i++)
	{
		if (Digital_root(array[i]))
		{
			int numOld;
			for (int j = i; j < length; j++)
			{
				numOld = array[j];
				array[j] = numNew;
				numNew = numOld;
			}
			array[length] = numOld;
			length++;
			return flag;
		}
	}
}

//Удаление всех чисел с цифровым корнем = 7
void Delete_roots(int array[], int& length)
{
	for (int i = 0; i < length; i++)
	{
		while (Digital_root(array[i]))
		{
			for (int j = i; j < length; j++)
			{
				swap(array[j], array[j + 1]);
			}
			length--;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	const int LENGTH = 100; //Формальный размер массива
	int size; //Неформальный размер массива
	int array[LENGTH] = { 0 };

	//Задание 1.1
	cout << "Введите размер массива >>> ";
	cin >> size;
	if (size > 100) return -1;
	cout << "Заполните массив на " << size << " элементов >> ";
	Fill_array(array, size);
	cout << "Первое вхождение: " << Search_key(array, size) << endl;

	//Задание 1.2
	cout << "Введите число для вставки >> ";
	int number;
	cin >> number;
	int res = Array_copy_and_insert(array, size, number);
	if (res == 1) Show_array(array, size); //Если цифровой корень обнаружен, то выводится весь массив 
	else if (res == 0)
	{
		Show_array(array, size);
	}
	else
	{
		cout << "Массив не может быть обработан из-за излишнего количество цифровых корней" << endl;
		return 0;
	}

	//Задание 1.3
	Delete_roots(array, size);
	cout << "Обработанный массив: ";
	Show_array(array, size);
}
