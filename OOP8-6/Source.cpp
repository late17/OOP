#include <iostream>
#include <vector>
using namespace std;

template <typename T, typename U>
class Iterator {
private:
    U* objclass;
    T data;
    int n;
public:
    Iterator(U* obj) {
        objclass = obj;
        n = 0;
        data = objclass->GetData(0);
    }
    bool IsDone() {
        return (n == objclass->n);
    }
    void First() {
        data = objclass->GetData(0);
    }
    void Next() {
        n++;
        data = objclass->GetData(n);
    }
    T Current() {
        return data;
    }
};




template <typename T>
class Array {
    friend class Iterator<T, Array>;
    int n;
    T* data;
public:

    Iterator<T, Array>* CreateIterator() {
        return new Iterator<T, Array>(this);
    }


    Array(int n) { this->n = n; data = new T[n]; }
    ~Array() {}
    T GetData(int n) { return data[n]; }

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
        cin >> data[i];
    }
    cout << "End.\n";

}

template <typename T>
void Array<T>::PrintData(const char mes[])
{
    cout << mes << endl;
    for (int i = 0; i < n; i++) {
        cout << '\n' << data[i];
    }

}



template <typename T>
void Array<T>::Concatenation(Array obj) {
    T* save = data;
    data = new T[n + obj.n];
    std::copy(save, save + n, data);
    std::copy(obj.data, obj.data + obj.n, data + n);
    n = n + obj.n;
}

template <typename T>
void Array<T>::Merger(Array obj) {
    int n2 = obj.n;
    int size = (n > n2) ? n : n2;
    T* save = this->data;
    this->data = new T[n + obj.n];
    for (int i = 0; i < size; i++) {
        if (i > n) { data[i] = obj.data[i]; continue; }
        if (i > n2) { data[i] = save[i]; continue; }
        data[i] = obj.data[i] > save[i] ? obj.data[i] : save[i];
    }
    n = size;
}



int main() {
    Array <int> obj(3);
    obj.EnterData("Enter first array:");
    //Array <int> obj2(3);
    //obj2.EnterData("Enter second array:");
    //Array <int> obj3(6);
    //obj3.EnterData("Enter third array:");

    Iterator <int, Array<int>>* it = obj.CreateIterator();

    for (it->First(); !it->IsDone(); it->Next()) {
        std::cout << it->Current() << std::endl;
    }

    //obj.Concatenation(obj2);

    //obj.PrintData("\nFirst and second arrays concatented");
    //obj.Merger(obj3);
    //obj.PrintData("\nModified first and third arrays merged");

    Array <double> obj4(3);
    obj4.EnterData("\nEnter Fifth array:");

    Iterator <double, Array<double>>* it2 = obj4.CreateIterator();

    for (it2->First(); !it2->IsDone(); it2->Next()) {
        std::cout << it2->Current() << std::endl;
    }
    //Array <double> obj5(3);
    //obj5.EnterData("\nEnter Sixth array:");
    //obj5.Concatenation(obj4);
    //obj5.PrintData("\nFifth and Forth arrays merged");
    return 0;
}

/*Створити шаблонний клас – впорядкований одновимірний динамічний масив.
Тип елементів масиву визначається параметром шаблона
(цілі числа, дійсні числа, символи або символьні рядки).
Передбачити функції для виконання таких операцій: введення елементів у масив,
конкатенація двох масивів, злиття двох впорядкованих масивів зі збереженням впорядкованості,
виведення масиву на екран.*/