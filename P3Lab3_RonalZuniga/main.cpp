#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool contiene(char x, vector<char> arreglo);
vector<char> letrasUnicas(string cadena);
int* cuenta(string cadena, vector<char> vector);
int* posiciones(int* entrada, int size);

int main(int argc, char** argv) {
	int opcion = 0;
	while(opcion != 5) {
		cout << "----MENU----" << endl;
		cout << "1. Ejercicio 1" << endl;
		cout << "2. Ejercicio 2" << endl;
		cout << "3. Ejercicio 3" << endl;
		cout << "4. Ejercicio 4" << endl;
		cout << "5. Salir" << endl;
		cout << "Ingrese la opcion que desea: ";
		cin >> opcion;
		cout << endl;

		while(opcion < 0 || opcion > 5) {
			cout << "Ingrese una opcion dentro del rango" << endl;
			cout << "Ingrese la opcion que desea: ";
			cin >> opcion;
			cout << endl;
		}//fin while validacion

		if(opcion == 1) {
			cout << "EJERCICIO 1" << endl;
			string cadena;
			cout << "Ingrese la cadena a evaluar: ";
			cin >> cadena;
			vector<char> vector = letrasUnicas(cadena);
			cout << endl;
			cout << "La cadena Inicial es: " << cadena << endl;
			cout << "El vector con las letras unicas es: [";
			for(int i = 0; i < vector.size(); i++) {
				cout << vector.at(i) << "  ";
			}
			cout << "]";
			cout << endl;
			cout << endl;
		}//fin opcion 1

		if(opcion == 2) {
			cout << "EJERCICIO 2" << endl;
			string cadena;
			vector<char> vector;
			int contador = 0;
			cout << "Ingrese la cadena: ";
			cin >> cadena;
			char resp = 's';
			while(resp == 's' || resp == 'S') {
				cout << "Ingrese caracter para el vector: ";
				char x;
				cin >> x;
				cout << endl;
				if(vector.empty()) {
					vector.insert(vector.begin(), x);
					contador++;
				} else {
					vector.insert(vector.begin() + contador, x);
					contador++;
				}
				cout << "Desea agregar otro caracter? [s/n]: ";
				cin >> resp;
				cout << endl;
			}//fin while respuesta
			int* array = cuenta(cadena, vector);
			cout << "La cadena es: " << cadena << endl;
			cout << "El vector de caracteres es: [";
			for(int i = 0; i < vector.size(); i++) {
				cout << vector.at(i) << "  ";
			}
			cout << "]";
			cout << endl;
			cout << "La solucion es: [";
			for(int i = 0; i < vector.size(); i++){
				cout << array [i] << "  ";
			}
			cout << "]";
			cout << endl;
			cout << endl;
			delete []array;
		}//fin opcion 2

		if(opcion == 3) {
			cout << "EJERCICIO 3" << endl;
			int* entrada;
			int size;
			cout << "Ingrese el tamanho del arreglo: ";
			cin >> size;
			entrada = new int [size];
			for(int x = 0; x < size; x++){
				int n;
				cout << "Ingrese un numero entero: ";
				cin >> n;
				entrada[x] = n;
			}
			cout << endl;
			cout << "Arreglo Ingresado: [";
			for(int i = 0; i < size; i++){
				cout << entrada [i] << "  ";
			}
			cout << "]";
			cout << endl;
			int* array = posiciones(entrada, size);
			cout << endl;
			cout << "La solucion es: [";
			for(int j = 0; j < size; j++){
				cout << array [j] << "  ";
			}
			cout << "]";
			cout << endl;
			cout << endl;
			delete []array;
			delete []entrada;
		}//fin opcion 3

		if(opcion == 4) {
			cout << "EJERCICIO 4" << endl;
			string cadena;
			cout << "Ingrese la cadena: ";
			cin >> cadena;
			
		}//fin opcion 4

	}//fin while menu
	return 0;
}//fin de funcion main

bool contiene(char x, vector<char> arreglo) {
	bool cont = false;
	for(int i = 0; i < arreglo.size(); i++) {
		if( ((int)arreglo.at(i)) == ((int)x)) {
			cont = true;
			i = arreglo.size() + 1;
		} else {
			cont = false;
		}
	}
	return cont;
}

vector<char> letrasUnicas(string cadena) {
	vector<char> letras;
	int c = 0;
	for(int i = 0; i < cadena.length(); i++) {
		char x = cadena[i];
		if(letras.empty()) {
			letras.insert(letras.begin(), x);
			c++;
		} else {
			if(contiene(x, letras)) {

			} else {
				letras.insert(letras.begin() + c, x);
				c++;
			}
		}
	}
	return letras;
}//fin metodo letras unicas

int* cuenta(string cadena, vector<char> vector){
	int* array;
    int contador = 0;
    array = new int[vector.size()];
    for (int i = 0; i < vector.size(); i++) {
        char letra = vector[i];
        contador = 0;
        for (int j = 0; j < cadena.length(); j++) {
            if (letra == cadena[j]) {
                contador++;
            }
        }
        array[i] = contador;
        contador = 0;
    }
    return array;
}

int* posiciones(int* entrada, int size){
    int* array = new int[size];
    for(int i = 0; i < size; i++){
        int mayor = -1;
		int posicion = 0; 
        for(int j = 0; j < size; j++){
            if(entrada[j] > mayor){
                mayor = entrada[j];
                posicion = j;
            }
        }
        array[i] = posicion;
        entrada[posicion] = -1;
    }
    return array;
}

/*string ordenFrecuencia(string cadena){
	vector<char> letras = letrasUnicas(cadena);
	int* frecuencia = cuenta(cadena, vector);
	
	
}*/



