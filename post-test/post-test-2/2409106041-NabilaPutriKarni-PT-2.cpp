#include <iostream>
using namespace std;

const int limit_hewan = 100;
string id_hewan[limit_hewan];
string jenis_hewan[limit_hewan];
string nama_hewan[limit_hewan];
int umur_hewan[limit_hewan];
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
        cout << "\n======================\n";
        cout << "|    MENU PET SHOP    |\n";
        cout << "=======================\n";
        cout << "|  1. TAMBAH HEWAN    |\n";
        cout << "|  2. TAMPILKAN HEWAN |\n";
        cout << "|  3. UBAH HEWAN      |\n";
        cout << "|  4. HAPUS HEWAN     |\n";
        cout << "|  5. KELUAR PROGRAM  |\n";
        cout << "=======================\n";
        cout << "Pilih (1/2/3/4/5): ";
        int pilihan;
        cin >> pilihan;

        if (pilihan == 1)
        {
            if (jumlah_hewan < limit_hewan)
            {
                cout << "Masukkan ID Hewan: ";
                cin >> id_hewan[jumlah_hewan];
                cout << "Masukkan jenis hewan: ";
                cin >> jenis_hewan[jumlah_hewan];
                cout << "Masukkan Nama Hewan: ";
                cin >> nama_hewan[jumlah_hewan];
                cout << "Masukkan Umur Hewan: ";
                cin >> umur_hewan[jumlah_hewan];
                jumlah_hewan++;
                cout << "Data hewan telah berhasil ditambahkan.\n ";
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
                cout << "ID\tJenis \tNama\tUmur\n";
                cout << "--------------------------------\n";
                for (int i = 0; i < jumlah_hewan; i++)
                {
                    cout << id_hewan[i] << "\t" << jenis_hewan[i] << "\t" << nama_hewan[i] << "\t" << umur_hewan[i] << "tahun\n";
                }
                cout << "--------------------------------\n";
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
                if (id_hewan[i] == id)
                {
                    cout << "Masukkan jenis baru: ";
                    cin >> jenis_hewan[i];
                    cout << "Masukkan nama baru: ";
                    cin >> nama_hewan[i];
                    cout << "Masukkan umur baru hewan: ";
                    cin >> umur_hewan[i];
                    terverifikasi = true;
                    cout << "Data hewan berhasil diperbarui.\n";
                    break;
                }
            }
            if (!terverifikasi)
                cout << "Hewan tidak terverifikasi!\n";
        }
        else if (pilihan == 4)
        {
            string id;
            cout << "Masukkan ID hewan yang ingin dihapus: ";
            cin >> id;
            bool terverifikasi = false;
            for (int i = 0; i < jumlah_hewan; i++)
            {
                if (id_hewan[i] == id)
                {
                    for (int j = 1; j < jumlah_hewan - 1; j++)
                    {
                        jenis_hewan[j] = jenis_hewan[j + 1];
                        id_hewan[j] = id_hewan[j + 1];
                        nama_hewan[j] = nama_hewan[j + 1];
                        umur_hewan[j] = umur_hewan[j + 1];
                    }
                    jumlah_hewan--;
                    terverifikasi = true;
                    cout << "Data hewan berhasil dihapus.\n";
                    break;
                }
            }
            if (!terverifikasi)
                cout << "Hewan tidak terverifikasi!\n";
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