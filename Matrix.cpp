#include <iostream>
#define MAX 10
using namespace std;

void InputMatrix(int [][MAX], int&, int&);
void OutputMatrix(const int [][MAX], const int, const int);

int main()
{
    int a[MAX][MAX];
    int n; 
    int m;

    InputMatrix(a, n, m);
    OutputMatrix(a, n, m);

    return 0;
}

void InputMatrix(int a[][MAX], int& n, int& m)
{
    cout << "Enter number of row n = ";
    cin >> n;

    cout << "Enter number of column m = ";
    cin >> m;

    // int temp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            // cin >> temp;
            // a[i][j] = temp;
            // a[i][j] = temp;
            cin >> a[i][j];
        }
    }
}

void OutputMatrix(const int a[][MAX], const int n, const int m)
{
    cout << endl << "---- Print Matrix ----" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << a[i][j] << "\t";
        }
        
        cout << endl;
    }
}