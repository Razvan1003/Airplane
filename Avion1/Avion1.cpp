#include <iostream>
#include <map>
#include <string>

#include <cstdlib>

using namespace std;

class Zbor {
private:
    map<string, int> locuriDisponibile;

public:
    Zbor() : locuriDisponibile{ {"Antalya", 250}, {"Belgrade", 250}, {"Zaragoza", 250} } {}

    void tabel() {
        int choice;
        do {
            cout << "Alege destinatia dorita:\n";
            cout << "1. ANTALYA -- 02:50 -- TAROM\n";
            cout << "2. BELGRADE -- 05:00 -- WIZ AIR\n";
            cout << "3. ZARAGOZA -- 05:55 -- CARGO AIR\n";
            cin >> choice;

            switch (choice) {
            case 1:
                cout << "Ati ales zborul BUCURESTI-ANTALYA\n";
                break;
            case 2:
                cout << "Ati ales zborul BUCURESTI-BELGRAD\n";
                break;
            case 3:
                cout << "Ati ales zborul BUCURESTI-ZARAGOZA\n";
                break;
            default:
                cout << "Va rog sa alegeti unul din zborurile disponibile\n";
            }
        } while (choice < 1 || choice > 3);
    }

    void check() {
        int optiune;

        cout << "Numar locuri disponibile: 250" << endl;

        do {
            cout << "Aveti 3 optiuni:\n"
                << "1. Vizualizarea locului dumneavoastra.\n"
                << "2. Alte zboruri.\n"
                << "3. Iesi din pagina.\n";
            cin >> optiune;

            switch (optiune) {
            case 1: {
                int num = rand() % 400;
                if (num <= 250) {
                    cout << "Doriti sa faceti check-in? (da=1, nu=0): ";
                    cin >> optiune;

                    cout << "Locul dumneavoastra este: " << num << endl;
                    break;
                }
                else {
                    cout << "Ne pare rau, nu mai avem locuri disponibile.\n";
                    break;
                }
            }
            case 2:
                tabel();
                break;
            case 3:
                cout << "O zi buna!\n";
                break;
            default:
                cout << "Alege una din optiunile disponibile.\n";
            }

        } while (optiune != 3);
    }
};

class Airline {
public:
    static void raportStare(const string& numeAvion, const string& tip) {
        cout << "Raport de stare pentru " << tip << " \"" << numeAvion << "\":\n"
            << "  - Altitudine: 10000m\n"
            << "  - Viteza: 900 km/h\n"
            << "  - Combustibil ramas: 2000 litri\n";
    }

    static void decolare(const string& numeAvion) {
        cout << "Avionul \"" << numeAvion << "\" a decolat cu succes.\n";
    }
};

int main() {
    Zbor zbor;
    zbor.check();

    cout << "Lista avioanelor disponibile:\n";
    cout << "   1. AvionPasageri \"AirbusA320\"\n";
    cout << "   2. AvionCargo \"Boeing747\"\n";

    Airline::raportStare("AirbusA320", "AvionPasageri");
    Airline::decolare("AirbusA320");

    return 0;
}
