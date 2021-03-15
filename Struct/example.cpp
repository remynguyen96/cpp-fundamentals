/**
 * Struct 2/12/2020
 * Note: print to console if you don't know what exactly the value of any variabale.
 */

#include <iostream>
#include <string>

#define MAX_N 100

using namespace std;

struct Student
{
    string name;
    string fullName;
    int id;
    bool sex;
    // constructor

    // Option 1
    // Student(string _name = "", string _fullName = "", int _id = 0, bool _sex = true)
    // {
    //     // NOTE 1: _name, _fullName,.. used to distinguish with name, fullName,..
    //     // NOTE 2: when pass parameter with _name ="", _id=0, it means DEFAULT VALUE if you not pass parameter with a VALUE.
    //     name = _name;
    //     fullName = _fullName;
    //     id = _id;
    //     sex = _sex;
    // }

    // Option 2
    Student(string name = "", string fullName = "", int id = 0, bool sex = true) : name(name), fullName(fullName), id(id), sex(sex)
    {
        // TODO: Handle other logic here. If not, please let's it empty!
    }

    void addToID(int k)
    {
        id += k;
    }

    int getId()
    {
        return id;
    }
};

struct Rectangle
{
    int width;
    int height;

    Rectangle(int _width = 0, int _height = 0)
    {
        width = _width;
        height = _height;
    }

    int calculateSquare()
    {
        return width * height;
    }
};

void inputStudent(Student &);
void printStudent(const Student);

int main()
{
    // Example 1
    Student students[MAX_N];
    // int n;
    // cout << "Enter N: ";
    // cin >> n;

    // for (int i = 0; i < n; i++)
    // {
    //     inputStudent(students[i]);
    // }

    // cout << "Print " << n << " students\n";
    // for (int i = 0; i < n; i++)
    // {
    //     printStudent(students[i]);
    // }

    // Example 2
    // Student s = Student("truong", "Hoang Xuan Truong", 99, 1);
    // printStudent(s);

    // s.addToID(10000);
    // printStudent(s);

    // cout << "\nGet ID: " << s.getId() << endl;

    // Example 3
    Student s; // create a Student struct with DEFAULT VALUE
    printStudent(s);

    // Example 4
    // Rectangle rect = Rectangle(4, 8);
    // cout << "W: " << rect.width << " | H: " << rect.height << endl;
    // cout << "Square: " << rect.calculateSquare() << endl;

    return 0;
}

void inputStudent(Student &s)
{
    cout << "Enter name: ";
    cin >> s.name;

    cout << "Enter full name: ";
    cin.ignore();
    getline(cin, s.fullName);

    cout << "Enter id: ";
    cin >> s.id;

    cout << "Enter gender: ";
    cin >> s.sex;
}

void printStudent(const Student s)
{
    cout << endl;
    cout << "Print student: " << endl;
    cout << "Id: " << s.id << endl;
    cout << "Name: " << s.name << endl;
    cout << "Full name: " << s.fullName << endl;
    cout << "Gender: ";
    if (s.sex)
        cout << "Male" << endl;
    else
        cout << "Female" << endl;
}