#include <iostream>
#include <iomanip>
using namespace std;

const int jumlah_mahasiswa = 100;

struct Nilai
{
    float nilai[3];
    float nilai_akhir;
};

struct Mahasiswa
{
    string nama;
    string jurusan;
    string kelas;
    Nilai nilai;
};

Mahasiswa mhs[jumlah_mahasiswa];
int jumlah = 0;

void inputMahasiswa()
{
    cout << setw(40) << setfill('=') << "=" << endl;
    cout << "       NILAI AKHIR MAHASISWA       " << endl;
    cout << setw(40) << setfill('=') << "=" << endl;
    cout << "\nMasukan Jumlah Mahasiswa : ";
    cin >> jumlah;
    system("cls");

    for (int i = 0; i < jumlah; i++)
    {
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        cout << "Masukan Nama : ";
        cin >> mhs[i].nama;
        cout << "Masukan Jurusan : ";
        cin >> mhs[i].jurusan;
        cout << "Masukan Kelas : ";
        cin >> mhs[i].kelas;

        cout << "MASUKAN NILAI" << endl;
        cout << "Masukan Nilai Kuis : ";
        cin >> mhs[i].nilai.nilai[0];
        cout << "Masukan Nilai UTS : ";
        cin >> mhs[i].nilai.nilai[1];
        cout << "Masukan Nilai UAS : ";
        cin >> mhs[i].nilai.nilai[2];

        mhs[i].nilai.nilai_akhir = (mhs[i].nilai.nilai[0] + mhs[i].nilai.nilai[1] + mhs[i].nilai.nilai[2]) / 3;
        system("cls");
    }
}

void CetakHasil()
{
    if (jumlah == 0)
    {
        cout << "\nData mahasiswa belum diinput. Silakan input data terlebih dahulu." << endl;
        return;
    }

    cout << "\nData Mahasiswa: " << endl;

    for (int i = 0; i < jumlah; i++)
    {
        cout << setw(30) << setfill('=') << "=" << endl;
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama : " << mhs[i].nama << endl;
        cout << "Jurusan : " << mhs[i].jurusan << endl;
        cout << "Kelas : " << mhs[i].kelas << endl;
        cout << "NILAI : " << mhs[i].nilai.nilai[0] << " " << mhs[i].nilai.nilai[1] << " " << mhs[i].nilai.nilai[2] << endl;
        cout << "Nilai Akhir : " << mhs[i].nilai.nilai_akhir << endl;
        cout << setw(30) << setfill('=') << "=" << endl;
    }
}

void Keluar()
{
    cout << "Keluar dari program." << endl;
    cout << "MENU TIDAK ADA" << endl;
}

int main()
{
    int pilih;
    do
    {
        cout << "MENU" << endl;
        cout << "1. Input Data" << endl;
        cout << "2. Cetak Hasil" << endl;
        cout << "3. Keluar" << endl;
        cout << "PILIH MENU : ";
        cin >> pilih;
        system("cls");

        switch (pilih)
        {
        case 1:
            inputMahasiswa();
            break;
        case 2:
            CetakHasil();
            break;
        case 3:
            Keluar();
            break;
        }
    } while (pilih != 3);
    return 0;
}
