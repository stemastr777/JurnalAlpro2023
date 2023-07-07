#include <string>
#include <vector>

struct Ukuran
{
    float tinggi;  // dalam meter
    float panjang; // dalam meter
};

class Sepeda
{
public:
    std::string merk;     // Merk sepeda
    std::string tipe;     // Tipe sepeda berdasarkan manufaktur masing masing
    struct Ukuran ukuran; // ukuran besar sepeda
    float berat;          // (kg)
    std::string jenis;    // Jenis sepeda : listrik atau konvensional
    std::string warna;
    int max_gear; // Gear paling berat
    std::vector<float> v_max; // Kecepatan maksimum (km/jam) untuk setiap gear

    // Mengambil kecepatan maksimal dari sebuah sepeda(km)
    float getVMax(int gear)
    {
        return(v_max[v_max.size()-1]);
    }

    // Waktu tempuh minimal(jam)
    float waktuTempuh(float jarak, int gear) {
        return jarak / this->v_max[gear - 1];
    }

    // Menghitung jarak tempuh
    float jarakTempuh(int gear, int detik) {
        return(this->v_max[gear-1]*detik/3600);
    }

    // Menghitung gear yang dibutuhkan
    int gearMin(float jarak, int detik) {

        float v_need = jarak*3600/detik;
        for (int j = 0; j < v_max.size(); j++) {
            if (v_max[j] > v_need) {
                return j+1;
            }
        }

        std::cout << "Tidak mungkin!";
        return 0;
    }

};