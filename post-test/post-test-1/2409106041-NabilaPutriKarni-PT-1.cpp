#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk login
bool login()
{
    string nama;
    int nim;
    const string valid_nama = "bila";
    const int valid_nim = 41;
    int percobaan_masuk = 0;

    while (percobaan_masuk < 3)
    {
        cout << "Masukkan Nama : ";
        cin >> nama;
        cout << "Masukkan NIM : ";
        cin >> nim;

        if (nama == valid_nama && nim == valid_nim)
        {
            cout << "Login Berhasil\n";
            return true;
        }
        else
        {
            cout << "Username atau password salah, silahkan coba lagi. \n";
            percobaan_masuk++;
        }
    }

    cout << "Terlalu banyak percobaan, Program dihentikan. " << endl;
    return false;
}

// fungsi untuk mengkonversi Celcius ke Fahrenheit, Reamur, dan Kelvin
void konversi_celcius(double celcius)
{
    cout << "Fahrenheit: " << (celcius * 9 / 5) + 32 << endl;
    cout << "Reamur: " << (celcius * 4 / 5) << endl;
    cout << "kelvin: " << celcius + 273.15 << endl;
}

// fungsi untuk mengkonversi Fahrenheit ke Celcius, Reamur, dan Kelvin
void konversi_fahrenheit(double fahrenheit)
{
    double celcius = (fahrenheit - 32) * 5 / 9;
    cout << "Celcius: " << celcius << endl;
    cout << "Reamur: " << (fahrenheit - 32) * 4 / 9 << endl;
    cout << "kelvin: " << celcius + 273.15 << endl;
}

// fungsi untuk mengkonversi Reamur ke Celcius, Fahrenheit, dan Kelvin
void konversi_reamur(double reamur)
{
    double celcius = reamur * 5 / 4;
    cout << "Celcius: " << celcius << endl;
    cout << "Fahrenheit: " << (celcius * 9 / 5) + 32 << endl;
    cout << "kelvin: " << celcius + 273.15 << endl;
}

// fungsi untuk mengkonversi  Kelvin ke Celcius, Fahrenheit, dan Reamur
void konversi_kelvin(double kelvin)
{
    double celcius = kelvin - 273.15;
    cout << "Celcius: " << celcius << endl;
    cout << "Fahrenheit: " << (celcius * 9 / 5) + 32 << endl;
    cout << "Reamur: " << celcius * 4 / 5 << endl;
}

int main()
{
    if (!login())
    {
        return 0; // jika login gagal maka akan keluar
    }

    int pilihan;
    do
    {
        cout << "\n==== Menu konversi Suhu ==== " << endl;
        cout << "1. konversi Celcius ke Fahrenheit, Reamur, dan Kelvin" << endl;
        cout << "2. konversi Fahrenheit ke Celcius, Reamur, dan Kelvin" << endl;
        cout << "3. konversi Reamur ke Celcius, Fahrenheit, dan Kelvin" << endl;
        cout << "4. konversi Kelvin ke Celcius, Fahrenheit, dan Reamur" << endl;
        cout << "5. Keluar program" << endl;
        cout << "Silahkan memilih salah satu opsi (1-5): ";
        cin >> pilihan;

        double suhu;
        switch (pilihan)
        {
        case 1:
            cout << "Masukkan suhu Celcius: ";
            cin >> suhu;
            konversi_celcius(suhu);
            break;
        case 2:
            cout << "Masukkan suhu Fahrenheit: ";
            cin >> suhu;
            konversi_fahrenheit(suhu);
            break;
        case 3:
            cout << "Masukkan suhu Reamur: ";
            cin >> suhu;
            konversi_reamur(suhu);
            break;
        case 4:
            cout << "Masukkan suhu Kelvin: ";
            cin >> suhu;
            konversi_kelvin(suhu);
            break;
        case 5:
            cout << "Terimakasih telah menggunakan program ini, program selesai. " << endl;
            break;
        default:
            cout << "Pilihan salah, silahkan mencoba lagi. " << endl;
        }
    } while (pilihan != 5);

    return 0;
}
