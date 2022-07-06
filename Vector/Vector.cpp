#include <iostream>
#include <vector>

using namespace std;

//Заполняет вектор
void Fill_array(vector<int>& myVector, int length)
{
	int n;
	for (int i = 0; i < length; i++)
	{
		cin >> n;
		myVector.push_back(n);
	}
}

//Вывод все элементы вектора
void Show_array(vector<int> myVector)
{
	for (int i = 0; i < myVector.size(); i++)
	{
		cout << myVector[i] << " ";
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
int Search_key(vector<int> myVector)
{
	for (int i = 0; i < myVector.size(); i++)
	{
		if (Digital_root(myVector[i])) return i;
	}
	return -1;
}

//Копирование массива и вставка числа перед корнем
int Array_copy_and_insert(vector<int>& myVector, int value)
{
	int flag = 0;
	for (int i = 0; i < myVector.size(); i++)
	{
		if (Digital_root(myVector[i])) flag++;
	}

	if (flag < 2)
	{
		auto iter = myVector.begin();
		for (int i = 0; i < myVector.size(); i++)
		{
			if (Digital_root(myVector[i]))
			{
				myVector.insert(iter + i, value);
				return 1;
			}
		}
	}
	else return 2;
}

//Удаление всех чисел с цифровым корнем = 7
void Delete_roots(vector <int>& myVector)
{
	auto iter = myVector.begin();
	for (int i = 0; i < myVector.size(); i++)
	{
		if (Digital_root(myVector[i]))
		{
			myVector.erase(iter + i);
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	vector<int> myVector;

	//Задание 1.1
	int size;
	cout << "Размер контейнера >>> ";
	cin >> size;
	cout << "Введите элементы вектора >>> ";
	Fill_array(myVector, size);
	cout << "Первое вхождение: " << Search_key(myVector) << endl;

	//Задание 1.2
	cout << "Введите число для вставки >> ";
	int number;
	cin >> number;
	if (Array_copy_and_insert(myVector, number) < 2)
	{
		Show_array(myVector);
	}
	else cout << "Массив не может быть обработан из-за излишнего количество цифровых корней" << endl;

	//Задание 1.3
	Delete_roots(myVector);
	cout << "Полученный вектор: ";
	Show_array(myVector);
}
