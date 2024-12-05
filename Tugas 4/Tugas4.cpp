#include <iostream>
using namespace std;

struct Penulis
{
    string nama;
};

struct Buku
{
    int Id;
    string Judul;
    Penulis pengarang;
    int harga;
};

const int JUMLAH_MAKS = 100;
Buku daftarBuku[JUMLAH_MAKS];
int jumlah = 0;

void TampilkanMenu()
{
    cout << "Menu :" << endl;
    cout << "1. Tambah Buku " << endl;
    cout << "2. Tampilkan Daftar Buku " << endl;
    cout << "3. Ubah Data Buku " << endl;
    cout << "4. Hapus Buku " << endl;
    cout << "5. Hitung Total Harga Pembelian dengan Diskon " << endl;
    cout << "6. Keluar " << endl;
    cout << "Pilih opsi :";
}

void TambahBuku()
{
    int jumlahInput;
    cout << "Masukkan jumlah buku yang ingin diinput: ";
    cin >> jumlahInput;
    cout << " " << endl;

    for (int i = 0; i < jumlahInput; i++)
    {
        if (jumlah >= JUMLAH_MAKS)
        {
            cout << "Kapasitas maksimal buku tercapai." << endl;
            break;
        }

        Buku buku;
        cout << "Masukkan ID buku: ";
        cin >> buku.Id;
        cin.ignore();
        cout << "Judul Buku: ";
        getline(cin, buku.Judul);
        cout << "Nama Pengarang: ";
        getline(cin, buku.pengarang.nama);
        cout << "Harga: ";
        cin >> buku.harga;
        cout << "  " << endl;

        daftarBuku[jumlah] = buku;
        jumlah++;
    }
}

void DaftarBuku()
{
    if (jumlah == 0)
    {
        cout << "\nData Buku Belum dimasukkan. Silahkan Input Data Buku!!" << endl;
        return;
    }

    cout << "\nDaftar Buku: " << endl;
    for (int i = 0; i < jumlah; i++)
    {
        cout << "ID Buku: " << daftarBuku[i].Id << endl;
        cout << "Judul: " << daftarBuku[i].Judul << endl;
        cout << "Pengarang: " << daftarBuku[i].pengarang.nama << endl;
        cout << "Harga: Rp" << daftarBuku[i].harga << endl;
        cout << "  " << endl;
    }
}

void UbahDataBuku()
{
    Buku buku;
    cout << "Masukan ID buku yang ingin diubah :";
    cin >> buku.Id;

    bool ditemukan = false;
    for (int i = 0; i < jumlah; i++)
    {
        if (daftarBuku[i].Id == buku.Id)
        {
            cout << "Judul Baru: ";
            cin.ignore();
            getline(cin, daftarBuku[i].Judul);
            cout << "Nama Pengarang Baru: ";
            getline(cin, daftarBuku[i].pengarang.nama);
            cout << "Harga Baru: ";
            cin >> daftarBuku[i].harga;
            cout << "Data berhasil diperbarui\n";
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan)
    {
        cout << "Buku dengan ID " << buku.Id << " tidak ditemukan\n";
    }
}

void HapusBuku()
{
    Buku buku;
    cout << "Masukan ID buku yang ingin dihapus :";
    cin >> buku.Id;

    for (int i = 0; i < jumlah; i++)
    {
        if (daftarBuku[i].Id == buku.Id)
        {
            for (int j = i; j < jumlah - 1; j++)
            {
                daftarBuku[j] = daftarBuku[j + 1];
            }
            jumlah--;
            cout << "Buku berhasil dihapus\n";
            break;
        }
    }
}

void Diskon()
{
    Buku buku;
    if (jumlah == 0)
    {
        cout << "Tidak ada buku dalam daftar\n";
        return;
    }

    int jumlah_beli;
    cout << "Masukkan jumlah buku yang ingin dibeli :";
    cin >> jumlah_beli;

    int idBuku;
    double total = 0;
    string pengarang_sama;
    bool diskonPengarang = false;

    for (int i = 0; i < jumlah_beli; i++)
    {
        cout << "Masukkan ID buku yang ingin dibeli: " << endl;
        cin >> idBuku;

        bool ditemukan = false;
        for (int j = 0; j < jumlah; j++)
        {
            if (daftarBuku[j].Id == idBuku)
            {
                total += daftarBuku[j].harga;
                if (i == 0)
                {
                    pengarang_sama = daftarBuku[j].pengarang.nama;
                }
                else if (pengarang_sama == daftarBuku[j].pengarang.nama)
                {
                    diskonPengarang = true;
                }
                ditemukan = true;
                break;
            }
        }
        if (!ditemukan)
        {
            cout << "Buku dengan ID " << buku.Id << " tidak ditemukan.\n";
        }
    }

    if (diskonPengarang)
    {
        cout << "Diskon 5% diterapkan karena Anda membeli minimal dua buku dari pengarang yang sama.\n";
        total *= 0.95;
    }

    string kodeVoucher;
    cout << "Masukkan kode voucher (Kosongkan jika tidak ada): ";
    cin.ignore();
    getline(cin, kodeVoucher);

    if (kodeVoucher == "JPYUM")
    {
        cout << "Diskon 10% dari voucher 'JPYUM' diterapkan.\n";
        total *= 0.9;
    }

    cout << "Total Harga Setelah Diskon (jika ada): Rp" << total << endl;
}

int main()
{
    int opsi;
    do
    {
        TampilkanMenu();
        cin >> opsi;
        switch (opsi)
        {
        case 1:
            TambahBuku();
            break;
        case 2:
            DaftarBuku();
            break;
        case 3:
            UbahDataBuku();
            break;
        case 4:
            HapusBuku();
            break;
        case 5:
            Diskon();
            break;
        case 6:
            cout << "Keluar dari program\n";
            break;
        default:
            cout << "Opsi salah. Silakan pilih lagi\n";
        }

    } while (opsi != 6);
}
