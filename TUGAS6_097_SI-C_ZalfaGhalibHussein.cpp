#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

// Deklarasi struct untuk produk
struct Product {
    string name;
    int stock;
    double price;
};

const int MAX_PRODUCTS = 3;

// Fungsi untuk menampilkan daftar produk
void displayProducts(const Product products[], int numProducts) {
    cout << setw(60) << setfill(' ') << "Daftar Produk Minimarket Al - Hussein!" << setfill(' ') << endl;
    cout << setw(80) << setfill('=') << "" << endl;
    cout << setw(5) << setfill(' ') << "NO";
    cout << setw(20) << setfill(' ') << "Nama Produk";
    cout << setw(10) << setfill(' ') << "Stok";
    cout << setw(15) << setfill(' ') << "Harga" << endl;
    cout << setw(80) << setfill('=') << "" << endl;

    for (int i = 0; i < numProducts; i++) {
        cout << setw(5) << setfill(' ') << i + 1;
        cout << setw(20) << setfill(' ') << products[i].name;
        cout << setw(10) << setfill(' ') << products[i].stock;
        cout << setw(15) << setfill(' ') << fixed << products[i].price << endl;
    }
    cout << setw(80) << setfill('=') << "" << endl;
}

// Fungsi untuk melakukan pembelian produk
void purchaseProduct(Product products[], int numProducts) {
    cout << "Masukkan nomor produk yang akan dibeli: ";
    int productNumber;
    cin >> productNumber;

    if (productNumber >= 1 && productNumber <= numProducts) {
        int quantity;
        cout << "Masukkan jumlah yang akan dibeli: ";
        cin >> quantity;

        Product selectedProduct = products[productNumber - 1];
        if (quantity > selectedProduct.stock) {
            cout << "Stok tidak cukup!" << endl;
        } else {
            double total = selectedProduct.price * quantity;
            if (selectedProduct.price > 200000.0) {
                total *= 0.9;
            }

            if (total > 25000.0) {
                total *= 0.98;
            }
            if (total > 50000.0) {
                total *= 0.96;
            }
            if (total > 100000.0) {
                total *= 0.94;
            }

            cout << "Total harga: Rp" << fixed << setprecision(2) << total << endl;
            products[productNumber - 1].stock -= quantity;
        }
    } else {
        cout << "Nomor produk tidak valid!" << endl;
    }
}
// Fungsi untuk operasi cmath
double calculateCMath(double angka, int operasi) {
    switch (operasi) {
        case 1:
            return sqrt(angka);  // Menghitung akar kuadrat
        case 2:
            return abs(angka);   // Menghitung nilai absolut
        case 3:
            return exp(angka);   // Menghitung eksponensial
        default:
            cout << "Operasi tidak valid." << endl;
            return 0.0;  // Return a default value if the operation is not valid
		}
	}  

// Fungsi rekursif untuk deret bilangan ganjil
int deret_ganjil(int n) {
    if (n == 1) {
        return 1;
    } else {
        return deret_ganjil(n - 1) + 2;
    }
}

// Fungsi rekursif untuk deret bilangan genap
int deret_genap(int n) {
    if (n == 1) {
        return 2;
    } else {
        return deret_genap(n - 1) + 2;
    }
}

// Fungsi untuk mencetak deret ganjil atau genap
void cetakDeret(char kode, int awal, int akhir) {
    int total = 0;

    cout << "Deret " << (kode == '-' ? "Ganjil" : "Genap") << " : ";

   for (int i = awal; i <= akhir; i += 2) {
        if ((kode == '-' && i % 2 == 1) || (kode == '+' && i % 2 == 0)) {
            cout << i;
            total += i;

        if (i < akhir) {
            cout << " + ";
        }
    }
}

    cout << " = " << total << endl;
}

int main() {
    Product products[MAX_PRODUCTS] = {
        {"Deterjen   ", 70, 50000},
        {"Susu Bayi  ", 50, 20000},
        {"LeMineral  ", 20, 7000}
    };

    while (true) {
        cout << setw(80) << setfill('=') << "" << endl;
        cout << setw(62) << setfill(' ') << "Selamat datang di Minimarket Al - Hussein!" << endl;
        cout << setw(80) << setfill('=') << "" << endl;
        cout << "1. Tampilkan Daftar Produk" << endl;
        cout << "2. Pembelian Produk" << endl;
        cout << "3. Cmath" << endl;
        cout << "4. Rekursif" << endl;
        cout << "Pilihan Anda (1/2/3/4): ";

        int choice;
        cin >> choice;

        cout << setw(80) << setfill('=') << "" << endl;

        if (choice == 1) {
            displayProducts(products, MAX_PRODUCTS);
            cout << "Apakah Anda ingin melakukan transaksi? (y/n): ";

            char pilihan;
            cin >> pilihan;

            if (pilihan == 'y' || pilihan == 'Y') {
                cout << "Anda ingin melakukan transaksi." << endl;
            } else if (pilihan == 'n' || pilihan == 'N') {
                cout << "Anda tidak ingin melakukan transaksi." << endl;
                break; // Keluar dari pengulangan
            } else {
                cout << "Pilihan tidak valid. Silakan jawab dengan 'y' atau 'n'." << endl;
            }
        } else if (choice == 2) {
            purchaseProduct(products, MAX_PRODUCTS);
        } else if (choice == 3) {
            // Meminta pengguna untuk memilih operasi cmath
            cout << "1. Akar Kuadrat \n2. Nilai Absolut \n3. Eksponensial" << endl;
            cout << "Pilih operasi cmath : ";
            int cmathChoice;
            cin >> cmathChoice;

            // Memasukkan angka
            cout << "Masukkan angka: ";
            double angka;
            cin >> angka;

            // Memanggil fungsi cmath dan menampilkan hasil
            double hasilCMath = calculateCMath(angka, cmathChoice);
            cout << "Hasil operasi cmath: " << hasilCMath << endl;
		} else if (choice == 4) {
           int awalBilangan, akhirBilangan;
           char pilih;

           cout << "Input Bilangan Awal : ";
           cin >> awalBilangan;

           cout << "Input Bilangan Akhir : ";
           cin >> akhirBilangan;

           cout << "[-] Deret Ganjil : " << endl;
           cout << "[+] Deret Genap : " << endl;
           cout << "Pilihan [- \\ +] : ";
           cin >> pilih;

           switch (pilih) {
                  case '-':
                      cetakDeret(pilih, awalBilangan, akhirBilangan);
                  break;
                  case '+':
                      cetakDeret(pilih, awalBilangan, akhirBilangan);
                  break;
                  default:
                      cout << "Pilihan tidak valid." << endl;
                  break;
            }
        }
    }
}
