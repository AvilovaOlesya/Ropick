// Ropick.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;
struct STUD {
    string name;
    string group;
    double ses[4];
};
double calculateAverage(const double ses[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += ses[i];
    }
    return sum / size;
}
int main() {
    setlocale(LC_ALL, "RUS");
    const int size = 2;
    STUD students[size];
    for (int i = 0; i < size; ++i) 
    {
        cout << "Введите данные о студенте " << i + 1 << ":\n";
        cout << "Фамилия и инициалы (без пробелов): ";
        cin >> students[i].name;
        cout << "Группа: ";
        cin >> students[i].group;
        for (int j = 0; j < 4; ++j) {
            cout << "Оценка " << j + 1 << ": ";
            cin >> students[i].ses[j];
        }
    }
    bool found = false;
    for (int i = 0; i < size; ++i) 
    {
        if (calculateAverage(students[i].ses, 4) > 4.2) 
        {
            found = true;
            cout << students[i].name << ", Группа: " << students[i].group
                << ", Средний балл: " << calculateAverage(students[i].ses, 4) << "\n";
        }
    }
    if (!found) {
        cout << "Студентов с средним баллом выше 4.2 нет." << endl;
    }
    return 0;
}