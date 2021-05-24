
#include <iostream>
using namespace std;

template <typename T>
class Array {
    int n;
    T* array;
public:
    Array(int n) { this->n = n; array = new T[n];}
    ~Array() {}
    void EnterData(const char mes[]);
    void PrintData(const char mes[]);
    void Concatenation(Array object);
    void Merger(Array object);
};

template <typename T>
void Array<T>::EnterData(const char mes[])
{
    cout << mes;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    cout << "End.\n";

}

template <typename T>
void Array<T>::PrintData(const char mes[])
{
    cout << mes << endl;
    for (int i = 0; i < n; i++) {
        cout << '\n' << array[i];
    }

}



template <typename T>
void Array<T>::Concatenation(Array obj) {
    T* save = array;
    array = new T[n + obj.n];
    std::copy(save, save +n, array);
    std::copy(obj.array, obj.array + obj.n, array + n);
    n = n + obj.n;
}

template <typename T>
void Array<T>::Merger(Array obj) {
    int n2 = obj.n;
    int size = (n > n2) ? n:n2;
    T* save = this->array;
    this->array = new T[n + obj.n];
    for (int i = 0; i < size; i++) {
        if (i > n) { array[i] = obj.array[i]; continue; }
        if (i > n2) { array[i] = save[i]; continue; }
        array[i] = obj.array[i] > save[i] ? obj.array[i] : save[i];
    }
    n = size;
}



int main() {
    Array <int> obj(3);
    obj.EnterData("Enter first array:");
    Array <int> obj2(3);
    obj2.EnterData("Enter second array:");
    Array <int> obj3(6);
    obj3.EnterData("Enter third array:");

    obj.Concatenation(obj2);
    
    obj.PrintData("\nFirst and second arrays concatented");
    obj.Merger(obj3);
    obj.PrintData("\nModified first and third arrays merged");

    Array <double> obj4(3);
    obj4.EnterData("Enter Fifth array:");
    Array <double> obj5(3);
    obj5.EnterData("Enter Sixth array:");
    obj5.Concatenation(obj4);
    obj5.PrintData("\Fifth and Forth arrays merged");
    return 0;
}

/*Створити шаблонний клас – впорядкований одновимірний динамічний масив. 
Тип елементів масиву визначається параметром шаблона 
(цілі числа, дійсні числа, символи або символьні рядки). 
Передбачити функції для виконання таких операцій: введення елементів у масив, 
конкатенація двох масивів, злиття двох впорядкованих масивів зі збереженням впорядкованості, 
виведення масиву на екран.*/