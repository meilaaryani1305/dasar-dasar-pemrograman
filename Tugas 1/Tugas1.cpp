#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string username, password;
    int pilihan;
    int angka_tebak;
    int angka_benar = 7;

    cout << setw(40) << setfill('=') << "=" << endl;
    cout << "       MASUKAN USERNAME DAN PASSWORD       " << endl;
    cout << setw(40) << setfill('=') << "=" << endl;
    do
    {
        cout << "USERNAME : ";
        cin >> username;

        cout << "PASSWORD : ";
        cin >> password;

        if (username == "meila" && password == "143")
        {
            cout << setw(30) << setfill('=') << "=" << endl;
            cout << "   ANDA BERHASIL MASUK DALAM GAME  " << endl;
            cout << setw(30) << setfill('=') << "=" << endl;
            break;
        }
        else
        {
            cout << "username atau password salah \n";
        }
    } while (true);

    cout << "BERHASIL LOGIN" << endl;

    cout << "menu" << endl;
    cout << "1. Masuk Dalam Game" << endl;
    cout << "Masukan Pilihan" << endl;
    cin >> pilihan;

    switch (pilihan)
    {
    case 1:
    {
        system("cls");

        cout << setw(40) << setfill('=') << "=" << endl;
        cout << "       SELAMAT DATANG DI GAME      " << endl;
        cout << setw(40) << setfill('=') << "=" << endl;

        cout << "MASUKAN ANGKA YANG ANDA TEBAK (1-10)" << endl;

        do
        {
            cout << " TEBAK ANGKA (1- 10) : ";
            cin >> angka_tebak;

            if (angka_tebak > angka_benar)
            {
                cout << "Angka terlalu besar" << endl;
            }
            else if (angka_tebak < angka_benar)
            {
                cout << "Angka terlalu kecil" << endl;
            }
            else
            {
                cout << setw(40) << setfill('=') << "=" << endl;
                cout << "SELAMAT ANDA BENAR, ANGKANYA ADALAH : " << angka_benar << endl;
                cout << setw(40) << setfill('=') << "=" << endl;
                break;
            }

        } while (angka_tebak != angka_benar);
    }
    }
}