// Code by Brandon Austin ( brandon.austin@oit.edu ) 
// and Tyler Tenny ( tyler.tenny@oit.edu )

#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 3;

void Menu(float matrix1[SIZE][SIZE], float matrix2[SIZE][SIZE], float matrix3[SIZE][SIZE]);
void GetMatrices(float matrix1[SIZE][SIZE], float matrix2[SIZE][SIZE]);
void Multiply(float matrix1[SIZE][SIZE], float matrix2[SIZE][SIZE], float matrix3[SIZE][SIZE]);
void Add(float matrix1[SIZE][SIZE], float matrix2[SIZE][SIZE], float matrix3[SIZE][SIZE]);
void Results(float matrix1[SIZE][SIZE], float matrix2[SIZE][SIZE], float matrix3[SIZE][SIZE], char symbol);

int main()
{
    char loop = 'y';
    float matrix1[SIZE][SIZE], matrix2[SIZE][SIZE], matrix3[SIZE][SIZE];
    
    // Get initial matrices
    GetMatrices(matrix1, matrix2);

    do
    {
        Menu(matrix1, matrix2, matrix3);

        // Allow program looping
        cout << endl << "Repeat program? (y/n): ";
        cin >> loop;
    } while (tolower(loop) == 'y');
}

// Display menu and process choices
void Menu(float matrix1[SIZE][SIZE], float matrix2[SIZE][SIZE], float matrix3[SIZE][SIZE])
{
    int choice;
    char symbol;

    retry:
    cout << endl << "Please select an option from the menu below: " << endl << endl;
    cout << "\t(1): Enter new matrices" << endl;
    cout << "\t(2): Multiply matrices" << endl;
    cout << "\t(3): Add matrices" << endl << endl;
    cout << "Choice: ";
    cin >> choice;
    cout << endl;

    switch (choice)
    {
        case 1:
            cout << endl;
            GetMatrices(matrix1, matrix2);
            break;
        case 2:
            symbol = '*';
            Multiply(matrix1, matrix2, matrix3);
            Results(matrix1, matrix2, matrix3, symbol);
            break;
        case 3:
            symbol = '+';
            Add(matrix1, matrix2, matrix3);
            Results(matrix1, matrix2, matrix3, symbol);
            break;
        default:
            cout << "Invalid Menu choice." << endl << endl;
            goto retry;
    }
}

// Get user input for both matrices
void GetMatrices(float matrix1[SIZE][SIZE], float matrix2[SIZE][SIZE])
{
    cout << "Please enter your first 3x3 matrix in left-to-right, top-to-bottom order. Hit enter after each number: " << endl << endl;

    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            cout << "Row " << r + 1 << ", Column " << c + 1 << ": ";
            cin >> matrix1[r][c];
        }
    }

    cout << endl << "Please enter your second 3x3 matrix in left-to-right, top-to-bottom order. Hit enter after each number: " << endl << endl;

    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            cout << "Row " << r + 1 << ", Column " << c + 1 << ": ";
            cin >> matrix2[r][c];
        }
    }
}

// Multiply matrices and store in new matrix
void Multiply(float matrix1[SIZE][SIZE], float matrix2[SIZE][SIZE], float matrix3[SIZE][SIZE])
{
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
            matrix3[r][c] = (matrix1[r][0] * matrix2[0][c]) + (matrix1[r][1] * matrix2[1][c]) + (matrix1[r][2] * matrix2[2][c]);
    }
}

// Add matrices and store in new matrix
void Add(float matrix1[SIZE][SIZE], float matrix2[SIZE][SIZE], float matrix3[SIZE][SIZE])
{
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
            matrix3[r][c] = matrix1[r][c] + matrix2[r][c];
    }
}

// Print all 3 matrices as well as operation used
void Results(float matrix1[SIZE][SIZE], float matrix2[SIZE][SIZE], float matrix3[SIZE][SIZE], char symbol)
{
    for (int r = 0; r < SIZE; r++)
    {
        if (r == 1)
        {
            cout << setw(10) << matrix1[r][0] << setw(10) << matrix1[r][1] << setw(10) << matrix1[r][2];
            cout << setw(10) << symbol << setw(10) << matrix2[r][0] << setw(10) << matrix2[r][1] << setw(10) << matrix2[r][2]; 
            cout << setw(10) << "=" << setw(10) << matrix3[r][0] << setw(10) << matrix3[r][1] << setw(10) << matrix3[r][2] << endl;
        }
        else
        {
            cout << setw(10) << matrix1[r][0] << setw(10) << matrix1[r][1] << setw(10) << matrix1[r][2];
            cout << setw(20) << matrix2[r][0] << setw(10) << matrix2[r][1] << setw(10) << matrix2[r][2];
            cout << setw(20) << matrix3[r][0] << setw(10) << matrix3[r][1] << setw(10) << matrix3[r][2] << endl;
        }
    }
}