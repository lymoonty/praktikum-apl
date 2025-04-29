#include <iostream>
using namespace std;

const int limit_hewan = 100;

struct hewan
{
    string id;
    string jenis;
    string nama;
    int umur;
};

hewan daftar_hewan[limit_hewan];
int jumlah_hewan = 0;

bool login_program(string Nama, string NIM)
{
    return (Nama == "bila" && NIM == "041");
}

void tambah_hewan_ptr(hewan *daftar, int *jumlah)
{
    if (*jumlah < limit_hewan)
    {
        cout << "Masukkan ID Hewan: ";
        cin >> (daftar[*jumlah]).id;
        cout << "Masukkan jenis hewan: ";
        cin >> (daftar[*jumlah]).jenis;
        cout << "Masukkan Nama Hewan: ";
        cin >> (daftar[*jumlah]).nama;
        cout << "Masukkan Umur Hewan: ";
        cin >> (daftar[*jumlah]).umur;

        (*jumlah)++;
        cout << "Data hewan telah berhasil ditambahkan.\n";
    }
    else
    {
        cout << "Maaf, tidak dapat menambahkan hewan lagi.\n";
    }
}

void tampilkan_hewan(const hewan daftar[], int jumlah)
{
    if (jumlah == 0)
    {
        cout << "Tidak ada data hewan.\n";
    }
    else
    {
        cout << "\n========= DATA HEWAN =========\n";
        cout << "ID\tJenis\tNama\tUmur\n";
        cout << "------------------------------------\n";
        for (int i = 0; i < jumlah; i++)
        {
            cout << daftar[i].id << "\t"
                 << daftar[i].jenis << "\t"
                 << daftar[i].nama << "\t"
                 << daftar[i].umur << " tahun\n";
        }
        cout << "------------------------------------\n";
    }
}

void ubah_hewan_ptr(hewan *daftar, int jumlah)
{
    string id;
    cout << "Masukkan ID hewan yang ingin diubah: ";
    cin >> id;
    bool ditemukan = false;

    for (int i = 0; i < jumlah; i++)
    {
        if ((daftar + i)->id == id)
        {
            cout << "Masukkan jenis baru: ";
            cin >> (daftar + i)->jenis;
            cout << "Masukkan nama baru: ";
            cin >> (daftar + i)->nama;
            cout << "Masukkan umur baru hewan: ";
            cin >> (daftar + i)->umur;
            ditemukan = true;
            cout << "Data hewan berhasil diperbarui.\n";
            break;
        }
    }

    if (!ditemukan)
        cout << "Hewan tidak ditemukan!\n";
}

void hapus_hewan_ptr(hewan *daftar, int *jumlah)
{
    string id;
    cout << "Masukkan ID hewan yang ingin dihapus: ";
    cin >> id;
    bool ditemukan = false;

    for (int i = 0; i < *jumlah; i++)
    {
        if ((daftar + i)->id == id)
        {
            for (int j = i; j < *jumlah - 1; j++)
            {
                *(daftar + j) = *(daftar + j + 1);
            }
            (*jumlah)--;
            ditemukan = true;
            cout << "Data hewan berhasil dihapus.\n";
            break;
        }
    }

    if (!ditemukan)
        cout << "Hewan tidak ditemukan\n";
}

void sort_nama_ascending(hewan *daftar, int jumlah)
{
    for (int i = 0; i < jumlah - 1; i++)
    {
        for (int j = i + 1; j < jumlah; j++)
        {
            if ((daftar + i)->nama > (daftar + j)->nama)
            {
                swap(*(daftar + i), *(daftar + j));
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan Nama (A-Z).\n";
}

void sort_umur_descending(hewan *daftar, int jumlah)
{
    for (int i = 0; i < jumlah - 1; i++)
    {
        for (int j = i + 1; j < jumlah; j++)
        {
            if ((daftar + i)->umur < (daftar + j)->umur)
            {
                swap(*(daftar + i), *(daftar + j));
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan Umur ( dari yang terbesar ke yang terkecil).\n";
}

void sort_jenis_ascending(hewan *daftar, int jumlah)
{
    for (int i = 0; i < jumlah - 1; i++)
    {
        for (int j = i + 1; j < jumlah; j++)
        {
            if ((daftar + i)->jenis > (daftar + j)->jenis)
            {
                swap(*(daftar + i), *(daftar + j));
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan Jenis Hewan (A-Z).\n";
}

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

        if (login_program(Nama, NIM))
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
        cout << "Terlalu banyak percobaan login, program dihentikan!\n";
        return 0;
    }

    while (true)
    {
        cout << "\n======================";
        cout << "\n|    MENU PET SHOP   |";
        cout << "\n=======================";
        cout << "\n| 1. TAMBAH HEWAN     |";
        cout << "\n| 2. TAMPILKAN HEWAN  |";
        cout << "\n| 3. UBAH HEWAN       |";
        cout << "\n| 4. HAPUS HEWAN      |";
        cout << "\n| 5. SORTING DATA     |";
        cout << "\n| 6. KELUAR PROGRAM   |";
        cout << "\n=======================";
        cout << "\nPilih (1/2/3/4/5/6): ";
        int pilihan;
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambah_hewan_ptr(daftar_hewan, &jumlah_hewan);
            break;
        case 2:
            tampilkan_hewan(daftar_hewan, jumlah_hewan);
            break;
        case 3:
            ubah_hewan_ptr(daftar_hewan, jumlah_hewan);
            break;
        case 4:
            hapus_hewan_ptr(daftar_hewan, &jumlah_hewan);
            break;
        case 5:
            int pilihan_sort;
            cout << "\n== PILIHAN SORTING ==";
            cout << "\n1. Berdasarkan Nama (A-Z)";
            cout << "\n2. Berdasarkan Umur (Tua ke Muda)";
            cout << "\n3. Berdasarkan Jenis (A-Z)";
            cout << "\nPilih metode sorting (1/2/3): ";
            cin >> pilihan_sort;

            if (pilihan_sort == 1)
                sort_nama_ascending(daftar_hewan, jumlah_hewan);
            else if (pilihan_sort == 2)
                sort_umur_descending(daftar_hewan, jumlah_hewan);
            else if (pilihan_sort == 3)
                sort_jenis_ascending(daftar_hewan, jumlah_hewan);
            else
                cout << "Pilihan sorting tidak valid.\n";
            break;
        case 6:
            cout << "Terima kasih telah menggunakan program petshop ini.\n";
            return 0;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    }

    return 0;
}
