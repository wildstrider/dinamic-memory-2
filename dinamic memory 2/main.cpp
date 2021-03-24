#include <iostream> 
using namespace std;
#define tab "\t"

void fillrand(int** arr, int rows, int cols);
void Print(int** arr, int rows, int cols);

void push_rows_front(int**& arr, int& rows, int cols);
void push_rows_back(int**& arr, int& rows, int cols);
void insert_rows(int**& arr, int& rows, int cols);
void Add_rows(int**& arr, int& rows, int cols);

void pop_rows_front(int**& arr, int& rows, int cols);
void pop_rows_back(int**& arr, int& rows, int cols);
void erase_rows(int**& arr, int& rows, int cols);
void Delete_rows(int**& arr, int& rows, int cols);

int main()
{
	setlocale(LC_ALL, "rus");
	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество колонок: "; cin >> cols;
	int** arr = new int* [rows] {};
	for (int i = 0; i < rows; i++) {

		arr[i] = new int[cols] {};
	}

	fillrand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Выберите действие" << endl;
	cout << "1 - Добавление строки"
		"\n2 - Удаление строки" << endl;
	int choice; cin >> choice;
	switch (choice)
	{
	case 1:
		Add_rows(arr,rows,cols);
		break;
	case 2:
		Delete_rows(arr, rows, cols);
	}
	Print(arr, rows, cols);

	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;

	int rep;
	cout << "Для повтора 1(выход 0): "; cin >> rep;
	switch (rep)
	{
	case 1:
		main();
		break;
	case 0:
		return 0;
	}
}

void fillrand(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			arr[i][j] = rand() % 100;
		}
	}

}
void Print(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			cout << arr[i][j] << tab;
		}
		cout << endl;
    }
	cout << endl;
}

void push_rows_front(int**& arr, int &rows, int cols)
{
	int r = rows + 1;
	int** buffer = new int* [r] {};
	for (int i = 0; i < r; i++) {

		buffer[i] = new int[cols] {};
	}

	for (int i = 0; i < r; i++) {

		for (int j = 0; j < cols; j++) {

			if (i == 0) {
				buffer[i][j] = 1;
			}
			else
			buffer[i][j] = arr[i-1][j];
		}
		
	}

	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows = r;

 
}
void push_rows_back(int**& arr, int& rows, int cols)
{
	int r = rows + 1;
	int** buffer = new int* [r] {};
	for (int i = 0; i < r; i++) {

		buffer[i] = new int[cols] {};
	}

	for (int i = 0; i < r; i++) {

		for (int j = 0; j < cols; j++) {

			if (i == r - 1) {
				buffer[i][j] = 1;
			}
			else
			buffer[i][j] = arr[i][j];
		}

	}

	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows = r;
}
void insert_rows(int**& arr, int& rows, int cols)
{
	int index, temp = 0;
	cout << "Введите куда встваить строку: "; cin >> index;
	int r = rows + 1;
	int** buffer = new int* [r] {};
	for (int i = 0; i < r; i++) {

		buffer[i] = new int[cols] {};
	}

	for (int i = 0; i < r; i++) {

		for (int j = 0; j < cols; j++) {

			if (i == index) {
				buffer[i][j] = 1;
			}
			else
			buffer[i][j] = arr[temp][j];
			
		}
		if (i != index)
			temp++;
	}

	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows = r;
}
void Add_rows(int**& arr, int& rows, int cols)
{
	int choice;
	cout << "Выберите куда добавить строку." << endl;
	cout << "1 - первую строку"
		"\n2 - последнюю строку"
		"\n3 - по индексу" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		push_rows_front(arr,rows,cols);
		break;
	case 2:
		push_rows_back(arr, rows, cols);
		break;
	case 3:
		insert_rows(arr, rows, cols);
	}
}

void pop_rows_front(int**& arr, int& rows, int cols)
{
	int r = rows - 1;
	int** buffer = new int* [r] {};
	for (int i = 0; i < r; i++) {

		buffer[i] = new int[cols] {};
	}

	for (int i = 0; i < r; i++) {

		for (int j = 0; j < cols; j++) {

			buffer[i][j] = arr[i + 1][j];
		}

	}

	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows = r;

}
void pop_rows_back(int**& arr, int& rows, int cols)
{
	int r = rows - 1;
	int** buffer = new int* [r] {};
	for (int i = 0; i < r; i++) {

		buffer[i] = new int[cols] {};
	}

	for (int i = 0; i < r; i++) {

		for (int j = 0; j < cols; j++) {

			buffer[i][j] = arr[i][j];
		}

	}

	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows = r;
}
void erase_rows(int**& arr, int& rows, int cols)
{
	int index, temp = 0;
	cout << "Введите какую строку удалить: "; cin >> index;
	int r = rows - 1;
	int** buffer = new int* [r] {};
	for (int i = 0; i < r; i++) {

		buffer[i] = new int[cols] {};
	}

	for (int i = 0; i < r; i++) {
		 
           if (i == index) {
				temp++;
		   }
		for (int j = 0; j < cols; j++) {

				buffer[i][j] = arr[temp][j];
		}
		temp++;
	}

	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows = r;
}
void Delete_rows(int**& arr, int& rows, int cols) 
{
	int choice;
	cout << "Выберите какую строку удалить." << endl;
	cout << "1 - первую строку"
		"\n2 - последнюю строку"
		"\n3 - по индексу" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		pop_rows_front(arr, rows, cols);
		break;
	case 2:
		pop_rows_back(arr, rows, cols);
		break;
	case 3:
		erase_rows(arr, rows, cols);
	}
}