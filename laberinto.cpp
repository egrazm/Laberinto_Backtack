#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <windows.h>

using namespace std;

void generarlaberinto(char** lab, int n);
bool encontrarcamino(char** lab,int x, int y ,int n);
void crearcamino(char** lab, int x, int y, int n);
void imprimirlaberinto(char** lab, int n);


int main() {
    int n;
    cout << "Introduce un tamaño impar para el laberinto (>=5): ";
    cin >> n;

    // Validar que sea impar y suficientemente grande
    if (n < 5 || n % 2 == 0) {
        cout << "El tamaño debe ser un número impar y mayor o igual a 5." << endl;
        return 1;
    }

    // Crear matriz dinámica
    char** lab = new char*[n];
    for (int i = 0; i < n; i++)
        lab[i] = new char[n];

    srand(time(NULL)); // Semilla aleatoria

    generarlaberinto(lab, n);
    imprimirlaberinto(lab, n);
    system("pause");

    
    encontrarcamino(lab, 1, 1, n);
   
     cout<< "\nCamino encontrado\n";

    // Liberar memoria
    for (int i = 0; i < n; i++)
        delete[] lab[i];
    delete[] lab;

    return 0;
}

void generarlaberinto(char** lab, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            lab[i][j] = '#';

    lab[1][1] = ' ';
    crearcamino(lab, 1, 1, n);

    lab[1][1] = 'E';
    lab[n - 2][n - 2] = 'S';
}

void crearcamino(char** lab, int x, int y, int n) {
    int dx[] = {0, 0, -2, 2};
    int dy[] = {-2, 2, 0, 0};

    int dirs[] = {0, 1, 2, 3};
    random_shuffle(dirs, dirs + 4);

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[dirs[i]];
        int ny = y + dy[dirs[i]];

        if (nx > 0 && nx < n - 1 && ny > 0 && ny < n - 1) {
            if (lab[nx][ny] == '#') {
                lab[(x + nx) / 2][(y + ny) / 2] = ' ';
                lab[nx][ny] = ' ';
                crearcamino(lab, nx, ny, n);
            }
        }
    }
}

bool encontrarcamino(char** lab, int x, int y, int n){
    if (lab[x][y]=='S')
        return true;

    if (lab[x][y] == ' ' || lab[x][y] == 'E') {

        if (lab[x][y] !='E')
            lab[x][y]='+';

        
        system("cls");              // Limpia pantalla
        imprimirlaberinto(lab, n);  // Muestra el laberinto
        Sleep(300);                 

        if (encontrarcamino(lab, x + 1, y, n) ||
            encontrarcamino(lab, x - 1, y, n) ||
            encontrarcamino(lab, x, y + 1, n) ||
            encontrarcamino(lab, x, y - 1, n)) {
            return true;
        }

        if (lab[x][y] !='E')
            lab[x][y]=' ';
        
        // Mostrar retroceso
        system("cls");
        imprimirlaberinto(lab, n);
        Sleep(300);
    }

    return false;
}

void imprimirlaberinto(char** lab, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << lab[i][j] << ' ';
        cout << endl;
    }
}

