#include <iostream>
using namespace std;

const int limit_hewan = 100;

struct Hewan
{
    string id;
    string jenis;
    string nama;
    int umur;
};

Hewan daftar_hewan[limit_hewan];
int jumlah_hewan = 0;

int main()
{
    string Nama, NIM;
    bool login = false;
    int percobaan_login = 0;

    while (percobaan_login < 3 && !login)
    {
        cout << "Masukkan Nama : ";
        cin >> Nama;
        cout << "Masukkan NIM : ";
        cin >> NIM;

        if (Nama == "bila" && NIM == "041")
        {
            login = true;
            cout << "Login berhasil, Welcome " << Nama << "!\n";
        }
        else
        {
            percobaan_login++;
            cout << "Nama atau NIM salah, Silahkan coba lagi!\n";
        }
    }
    if (!login)
    {
        cout << "Terlalu banyak percobaan login, program dihentikan !\n";
        return 0;
    }

    while (true)
    {
        cout << "\n======================";
        cout << "\n|    MENU PET SHOP    |";
        cout << "\n=======================";
        cout << "\n|  1. TAMBAH HEWAN    |";
        cout << "\n|  2. TAMPILKAN HEWAN |";
        cout << "\n|  3. UBAH HEWAN      |";
        cout << "\n|  4. HAPUS HEWAN     |";
        cout << "\n|  5. KELUAR PROGRAM  |";
        cout << "\n=======================";
        cout << "\nPilih (1/2/3/4/5): ";
        int pilihan;
        cin >> pilihan;

        if (pilihan == 1)
        {
            if (jumlah_hewan < limit_hewan)
            {
                cout << "Masukkan ID Hewan: ";
                cin >> daftar_hewan[jumlah_hewan].id;
                cout << "Masukkan jenis hewan: ";
                cin >> daftar_hewan[jumlah_hewan].jenis;
                cout << "Masukkan Nama Hewan: ";
                cin >> daftar_hewan[jumlah_hewan].nama;
                cout << "Masukkan Umur Hewan: ";
                cin >> daftar_hewan[jumlah_hewan].umur;
                jumlah_hewan++;
                cout << "Data hewan telah berhasil ditambahkan.\n";
            }
            else
            {
                cout << "Maaf, tidak dapat menambahkan hewan lagi\n";
            }
        }
        else if (pilihan == 2)
        {
            if (jumlah_hewan == 0)
            {
                cout << "Tidak ada data hewan.\n";
            }
            else
            {
                cout << "\n========= DATA HEWAN =========\n";
                cout << "ID\tJenis\tNama\tUmur\n";
                cout << "------------------------------------\n";
                for (int i = 0; i < jumlah_hewan; i++)
                {
                    cout << daftar_hewan[i].id << "\t"
                         << daftar_hewan[i].jenis << "\t"
                         << daftar_hewan[i].nama << "\t"
                         << daftar_hewan[i].umur << " tahun\n";
                }
                cout << "------------------------------------\n";
            }
        }
        else if (pilihan == 3)
        {
            string id;
            cout << "Masukkan ID hewan yang ingin diubah: ";
            cin >> id;
            bool terverifikasi = false;
            for (int i = 0; i < jumlah_hewan; i++)
            {
                if (daftar_hewan[i].id == id)
                {
                    cout << "Masukkan jenis baru: ";
                    cin >> daftar_hewan[i].jenis;
                    cout << "Masukkan nama baru: ";
                    cin >> daftar_hewan[i].nama;
                    cout << "Masukkan umur baru hewan: ";
                    cin >> daftar_hewan[i].umur;
                    terverifikasi = true;
                    cout << "Data hewan berhasil diperbarui.\n";
                    break;
                }
            }
            if (!terverifikasi)
                cout << "Hewan tidak ditemukan!\n";
        }
        else if (pilihan == 4)
        {
            string id;
            cout << "Masukkan ID hewan yang ingin dihapus: ";
            cin >> id;
            bool terverifikasi = false;
            for (int i = 0; i < jumlah_hewan; i++)
            {
                if (daftar_hewan[i].id == id)
                {
                    for (int j = i; j < jumlah_hewan - 1; j++)
                    {
                        daftar_hewan[j] = daftar_hewan[j + 1];
                    }
                    jumlah_hewan--;
                    terverifikasi = true;
                    cout << "Data hewan berhasil dihapus.\n";
                    break;
                }
            }
            if (!terverifikasi)
                cout << "Hewan tidak ditemukan!\n";
        }
        else if (pilihan == 5)
        {
            cout << "Terima kasih telah menggunakan program petshop ini.\n";
            return 0;
        }
        else
        {
            cout << "Pilihan tidak valid.\n";
        }
    }
    return 0;
}
