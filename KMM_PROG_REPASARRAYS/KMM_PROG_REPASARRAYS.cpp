#include <iostream>
#include <string>

using namespace std;

// Declaració de constants
const int MAX_INVENTARI = 10;

// Declaració de funcions
void entrar_objecte(string inventari[], int& ocupats);
void eliminar_objecte(string inventari[], int& ocupats);
void entra_num_objectes(string inventari[], int& ocupats);

int main() {
    // Inicialitzar l'inventari buit
    string inventari[MAX_INVENTARI];
    int ocupats = 0;

    // Menú principal
    char opcio;
    do {
        cout << "\nMenu:\n";
        cout << "1. Entrar objecte a l'inventari\n";
        cout << "2. Eliminar objecte de l'inventari\n";
        cout << "3. Entrar una quantitat determinada d'objectes\n";
        cout << "4. Buidar tot l'inventari\n";
        cout << "5. Sortir\n";
        cout << "Selecciona una opcio (1-5): ";
        cin >> opcio;

        switch (opcio) {
        case '1':
            entrar_objecte(inventari, ocupats);
            break;
        case '2':
            eliminar_objecte(inventari, ocupats);
            break;
        case '3':
            entra_num_objectes(inventari, ocupats);
            break;
        case '4':
            ocupats = 0; // Buidar l'inventari
            cout << "L'inventari ha estat buidat.\n";
            break;
        case '5':
            cout << "Adeu!\n";
            break;
        default:
            cout << "Opcio no valida. Torna a intentar.\n";
        }

        // Mostrar l'estat de l'inventari
        cout << "\nInventari de l'heroi:\n";
        for (int i = 0; i < ocupats; ++i) {
            cout << "- " << inventari[i] << "\n";
        }

    } while (opcio != '5');

    return 0;
}

void entrar_objecte(string inventari[], int& ocupats) {
    if (ocupats < MAX_INVENTARI) {
        cout << "Entra el nom de l'objecte: ";
        cin >> inventari[ocupats];
        cout << inventari[ocupats] << " ha estat afegit a l'inventari.\n";
        ++ocupats;
    }
    else {
        cout << "L'inventari està ple. No es pot afegir més objectes.\n";
    }
}

void eliminar_objecte(string inventari[], int& ocupats) {
    if (ocupats > 0) {
        cout << "Entra el nom de l'objecte a eliminar: ";
        string nom_objecte;
        cin >> nom_objecte;

        // Buscar i eliminar l'objecte de l'inventari
        for (int i = 0; i < ocupats; ++i) {
            if (inventari[i] == nom_objecte) {
                cout << nom_objecte << " ha estat eliminat de l'inventari.\n";
                for (int j = i; j < ocupats - 1; ++j) {
                    inventari[j] = inventari[j + 1];
                }
                --ocupats;
                return;
            }
        }

        cout << nom_objecte << " no es troba a l'inventari.\n";
    }
    else {
        cout << "L'inventari esta buit. No es pot eliminar cap objecte.\n";
    }
}

void entra_num_objectes(string inventari[], int& ocupats) {
    int num_objectes;
    cout << "Entra el nombre d'objectes que vols afegir:";
    cin >> num_objectes;

    for (int i = 0; i < num_objectes; ++i) {
        entrar_objecte(inventari, ocupats);
    }
}
