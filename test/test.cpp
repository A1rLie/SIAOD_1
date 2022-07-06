#include <iostream>

using namespace std;

void Show(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

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


//Удаление всех чисел с цифровым корнем = 7
void Delete_roots(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        while (Digital_root(array[i]))
        {
            for (int j = i; j < 5; j++)
            {
                swap(array[j], array[j + 1]);
            }
            length--;
        }
    }
}

int main()
{
    int array[10] = { 1,2,25,3,4,0,0,0,0,0 };
    Show(array, 10);
    int size = 5;
  // Show(array, size);
    //Передвижение
   /* for (int i = 0; i < size; i++)
    {
        cout << Digital_root(array[i]) << endl;
        int res = Digital_root(array[i]);
        while (res == 7)
        {
            for (int j = i; j < 5; j++)
            {
                swap(array[j], array[j + 1]);
            }
            size--;
        }
    }
    Show(array, size);*/
    cout << Digital_root(25) << endl;
}

