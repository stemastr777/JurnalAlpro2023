#include <iostream>

class Fotokopi {

    public:

        int jml_kertas;
        int total;

        // Masukkan dari pengguna
        void inputData()
        {
            std::cout << "Jumlah kertas: ";
            std::cin >> jml_kertas;
        }

        // Menghitung total harga untuk layanan fotokopi
        int hitungHarga() {
            this->total = jml_kertas * 200;
            return total;
        }

};

class Jilid
{

    public:
        int mika = 0;
        int total = 0;

        // Masukkan dari pengguna
        void inputData()
        {
            std::cout << "Pakai mika: ";
            std::cin >> this->mika;
        }

        // Menghitung total harga untuk layanan jilid
        int hitungHarga()
        {   
            if (mika == 1) {
                this->total = 2000;
            } else {
                this->total = 1000;
            }
            return total;
        }
};

class Print
{

    public:
        int warna;
        int jml_kertas;
        int total;

        // Masukkan dari pengguna
        void inputData()
        {
            std::cout << "Berwarna: ";
            std::cin >> this->warna;
            std::cout << "Jumlah kertas: ";
            std::cin >> this->jml_kertas;
        }

        // Menghitung total harga untuk layanan print
        int hitungHarga()
        {
            if (warna == 1)
            {
                this->total = this->jml_kertas * 500;
            } else {
                this->total = this->jml_kertas * 300;
            }
            return total;
        }
};