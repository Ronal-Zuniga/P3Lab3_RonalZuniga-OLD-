#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char** argv) {
	char cadena[100];
	cout << "Cadena: ";
	cin.getline(cadena, 100, '\n');
	cout << cadena << endl;
	return 0;
}
