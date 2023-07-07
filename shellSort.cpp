#include <iostream>

using namespace std;

/*
    Program Mengurutkan data secara ascending menggunakan metode shell sort
*/


int main(){

    // Deklarasi
    int Himpunan[20];
    int i, j, p, N;
    int temp;
    int jarak;

    // Memasukkan data
    cout << "Masukkan Banyak Bilangan : ";
    cin >> N;
    for (i = 0; i < N; i++){
        cout << "Elemen ke-" << i << " : ";
        cin >> Himpunan[i];
    }

    // Mencetak data sebelum diurutkan
    cout << "\nData sebelum diurutkan :  ";
    p = 0;
    while (p < N) {
        cout << "    " << Himpunan[p];
        p += 1;
    }


    // Proses Pengurutan (metode shell sort)
    jarak = N / 2;
    while (jarak >= 1) {

            // Insertion sort dengan jarak tertentu
            i = jarak;
            while (i < N) {
                
                // Menyimpan nilai Himpunan[i] sebelum diubah
                temp = Himpunan[i];

                // Menukarkan elemen pada array dengan jarak tertentu apabila perlu
                j = i;
                while ((j >= jarak) && (Himpunan[j - jarak] > temp) ) {
                    Himpunan[j] = Himpunan[j - jarak];
                    j -= jarak;
                }

                // Meletakkan temp (nilai Himpunan[i] sebelum diubah menjadi nilai Himpunan[j-jarak]) pada tempat yang tepat
                Himpunan[j] = temp;
                i += 1;
            }

        // Menampilkan hasil tahapan sorting untuk setiap jarak
        cout << "\nJarak = " << jarak << "            ==>  ";
        p = 0;
        while (p < N) {
            cout << "    " << Himpunan[p];
            p += 1;
        }

        jarak /= 2;
    }


    //Menampilkan hasil pengurutan
    cout << "\nData setelah diurutkan :  ";
    p = 0;
    while (p < N) {
        cout << "    " << Himpunan[p];
        p += 1;
    }

    return 0;
}