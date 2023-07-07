/*
    Author : Steven Adi Suryanto
    NIM : A11.2022.14623
    Judul : Program menganalisis bangun ruang tabung
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

//Kamus global
const float phi = 3.14;
float r, t, L, V;
int jml_tabung;
float daftar_tabung[5][6]; // { {[jari jari], [tinggi], [luas alas], [luas selimut], [luas permukaan], [volume]}, ... }
float daftar_luas[5];       // menyimpan daftar luas permukaan tabung
float daftar_volume[5];    // menyimpan daftar volume tabung

// Menghitung jari jari apabila diketahui volume dan tinggi tabung
double cariJari1(float V, float t) {
    return(sqrt(V/(phi*t)));
}

//Menghitung tinggi apabila diketahui volume dan jari jari tabung
float cariTinggi(float V, float r) {
    return(V/(phi*r*r));
}

//Menghitung jari jari apabila diketahui luas selimut dan tinggi tabung
float cariJari2(float selimut, float t) {
    return(selimut/(2*phi*t));
}

// Menghitung tinggi apabila diketahui luas selimut dan jari jari tabung
float cariTinggi2(float selimut, float r) {
    return(selimut/(2*phi*r));
}

// Menghitung luas lingkaran berdasarkan jari jari(r)
float luasLingkaran(float jari) {
    return(phi*jari*jari);
}

// Menghitung jumlah luas tutup dan alas tabung
float luasAlasTutup(float luasLingkaran) {
    return(luasLingkaran*2);
}

// Menghitung luas selimut
float luasSelimut(float jari, float tinggi) {
    return(2*phi*jari*tinggi);
}

//Menghitung luas tabung
float luasTabung(float luasSelimut, float luasAlasTutup) {
    return(luasSelimut + luasAlasTutup);
}

//Menghitung volume tabung
float volumeTabung(float luasAlas, float tinggi) {
    return (luasAlas*tinggi);
}

//Mencari index setiap elemen di array akhir terhadap array awal
int *cariIndex(float awal[], float akhir[], int akhir_size, bool ubah_awal = false) {
    int *index = new int[5];
    float copy_awal[5];

    if (ubah_awal == false) {
        //Buat copy an dari array awal
        for (int i = 0; i < 5; i++) {
            copy_awal[i] = awal[i];
        }

        int i = 0 , j = 0;
        while (i < akhir_size) {
            while (j < jml_tabung) {
                index[i] = -1;
                if (akhir[i] == copy_awal[j]) {
                    index[i] = j;
                    copy_awal[j] = -1; //Menandakan bahwa index sudah diambil
                    break;
                }
                //Apabila elemen pada array akhir tidak ditemukan pada array awal
                j += 1;
            }
            j = 0;
            i += 1;
        }

        /* for (int i = 0; i < akhir_size; i++)
        {
            index[i] = -1;
            for (int j = 0; j < jml_tabung; j++)
            {
                if (akhir[i] == awal[j])
                {
                    index[i] = j;
                    break;
                }
            }
        } */
    } else{
        int i = 0, j = 0;
        while (i < akhir_size)
        {
            while (j < jml_tabung)
            {
                index[j] = -1;
                if (akhir[i] == awal[j])
                {
                    index[i] = j;
                    awal[j] = -1; // Menandakan bahwa index sudah diambil
                    break;
                }
                j += 1;
            }
            j = 0;
            i += 1;
        }
        /* for (int i = 0; i < akhir_size; i++)
        {
            index[i] = -1;
            for (int j = 0; j < 5; j++)
            {
                if (akhir[i] == awal[j])
                {
                    index[i] = j;
                    break;
                }
            }
        } */
    }

    return(index);
}

//Mencari nilai terbesar dari sebuah array
float *nilaiTerbesar(float arr[]) {
    float *terbesar = new float[1];
    terbesar[0] = 0;
    int i = 0;
    while (i < jml_tabung) {
        if (terbesar[0] < arr[i]) {
            terbesar[0] = arr[i];
        }
        i += 1;
    }
    return(terbesar);
}

//Mengurutkan sebuah array secara ascending
float *ascendArray(float arr[]) {
    int l = 0, r = jml_tabung-1; //both inclusive
    float *sorted = new float[jml_tabung];
    std::copy(arr, arr + jml_tabung, sorted);

    while (r >= 0) {
        while (l < r) {
            if (sorted[l] > sorted[l+1]) {        
                float temp = sorted[l];
                sorted[l] = sorted[l+1];           
                sorted[l+1] = temp;   
            }
            l += 1;
        }
        l = 0;
        r -= 1;
    }

    return(sorted);
}

//Menghitung jumlah element suatu array
float totalNilai(float arr[]) {
    int i = 0;
    float total = 0;
    while (i < jml_tabung) {
        total += arr[i];
        i += 1;
    }
    return total;
}

//Mencari pasangan tabung yang sama
float** cariSama(float arr[]) {

    // Allocate memory for the rows
    float **equal = new float *[5];

    // Allocate memory for the columns in each row
    for (int i = 0; i < 5; i++) {
        equal[i] = new float[5];
    }

    // Initialize all pointers to null
    for (int i = 0; i < 5; i++) {
        equal[i] = nullptr;
    }

    float recorded[5];
    float copy_arr[5];
    

    for (int k = 0; k < 5; k++) {
        copy_arr[k] = arr[k];
    }

    int i = 0;
    while (i < 5) {
        
        //Jika merupakan nilai baru pada recorded
        if (*cariIndex(recorded, &copy_arr[i], false) == -1) {
            int j = 0;
            recorded[i] = copy_arr[i];
            equal[i][j] = *cariIndex(copy_arr, &copy_arr[i], 1, true);

            for (int k = i+1; k < jml_tabung; k++) {
                if (copy_arr[k] == recorded[i]) {
                    j += 1;
                    equal[i][j] = *cariIndex(copy_arr, &copy_arr[k], 1, true);
                }
            }
            i++;
        }

        //Jika sudah ada maka di skip saja karena sudah tercatat ke dalam equal 
        else {
            i++;
        }
    }

    return equal;
}

//Program utama
int main() {
    int i = 0;

    //Input
    std::cout << "Mau bikin berapa tabung?(max, 5) ";
    cin >> jml_tabung;
    while ( i < jml_tabung) {
        int r,t;
        std::cout << "Masukkan jari jari(tabung " << i+1 << "): " ;
        cin >> daftar_tabung[i][0];
        std::cout << "Masukkan tinggi(tabung " << i+1 << "): ";
        cin >> daftar_tabung[i][1];
        r = daftar_tabung[i][0];
        t = daftar_tabung[i][1];
        daftar_tabung[i][2] =  luasLingkaran(r);
        daftar_tabung[i][3] =  luasSelimut(r, t);
        daftar_tabung[i][4] =  luasTabung(luasSelimut(r, t), luasAlasTutup(luasLingkaran(r)));
        daftar_tabung[i][5] =  volumeTabung(luasLingkaran(r), t);

        daftar_luas[i] = luasTabung(luasSelimut(r, t), luasAlasTutup(luasLingkaran(r)));
        daftar_volume[i] = volumeTabung(luasLingkaran(r), t);

        i = i + 1; // berhenti saat i = jml_tabung
    }

    //Preview tabung
    while ( i > 0) { 
        std::cout << endl << "=================================================================================" << endl;
        std::cout << "Tabung " << jml_tabung-i+1 << endl;
        std::cout << "Jari-jari: " << daftar_tabung[jml_tabung-i][0] << endl;
        std::cout << "Tinggi: " << daftar_tabung[jml_tabung - i][1] << endl;
        std::cout << "Luas alas: " << daftar_tabung[jml_tabung - i][2] << endl;
        std::cout << "Luas selimut: " << daftar_tabung[jml_tabung - i][3] << endl;
        std::cout << "Luas permukaan: " << daftar_tabung[jml_tabung - i][4] << endl;
        std::cout << "Volume tabung: " << daftar_tabung[jml_tabung - i][5] << endl;
        i = i - 1;
    }
    
    //Analisis
    if (jml_tabung > 1) {
        std::cout << endl << "=================================================================================" << endl; 
        std::cout << "Total luas permukaan tabung: " << totalNilai(daftar_luas) << endl;
        std::cout << "Total volume tabung: " << totalNilai(daftar_volume) << endl;


        std::cout << "Tabung dengan volume terbesar: tabung " << cariIndex(daftar_volume, nilaiTerbesar(daftar_volume), 1, false)[0] + 1 << endl;
        std::cout << "Tabung dengan luas terbesar: tabung " << cariIndex(daftar_luas, nilaiTerbesar(daftar_luas), 1, false)[0] + 1 << endl;

        std::cout << "Urutan tabung dengan luas paling kecil ke besar: ";
        for (int i = 0; i < jml_tabung; i++) {
            std::cout << "tabung " << cariIndex(daftar_luas, ascendArray(daftar_luas), jml_tabung)[i] + 1 << ", ";
        }
        std::cout << endl;
        std::cout << "Urutan tabung dengan volume paling kecil ke besar: ";
        for (int i = 0; i < jml_tabung; i++) {
            std::cout << "tabung " << cariIndex(daftar_volume, ascendArray(daftar_volume), jml_tabung)[i] + 1 << ", ";
        }
        std::cout << endl;

        std::cout << "Pasangan tabung yang memiliki nilai yang sama: ";
        /* for (int i = 0; i < jml_tabung; i++) {
            std::cout << "(";
            for (int j = 0; j < jml_tabung; j++) {
                std::cout << "tabung " << cariSama(daftar_volume)[i][j] + 1 << ", ";
            }
            std::cout << ") ";
        } */
    }

    return 0;
}
