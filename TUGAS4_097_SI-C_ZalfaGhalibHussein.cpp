#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Deklarasi struct untuk produk
struct Product {
    string name;
    int stock;
    double price;
};

// Fungsi untuk menampilkan daftar produk
void displayProducts(Product products[], int size) {
    cout << setw(60) << setfill(' ') << "Daftar Produk Minimarket Al - Hussein!" << setfill(' ') << endl;
    cout << setw(80) << setfill('=') << "" << endl;
    cout << setw(5) << setfill(' ') << "NO";
    cout << setw(20) << setfill(' ') << "Nama Produk";
    cout << setw(10) << setfill(' ') << "Stok";
    cout << setw(15) << setfill(' ') << "Harga" << endl;
    cout << setw(80) << setfill('=') << "" << endl;

    for (int i = 0; i < size; i++) {
        cout << setw(5) << setfill(' ') << i + 1;
        cout << setw(20) << setfill(' ') << products[i].name;
        cout << setw(10) << setfill(' ') << products[i].stock;
        cout << setw(15) << setfill(' ') << fixed << products[i].price << endl;
    }
    cout << setw(80) << setfill('=') << "" << endl;
}

const int MAX_PRODUCTS = 3;

void displayProducts(const Product products[], int numProducts) {
    for (int i = 0; i < numProducts; ++i) {
        cout << i + 1 << ". " << products[i].name << " (Stok: " << products[i].stock << ", Harga: Rp" << products[i].price << ")" << endl;
    }
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
        cout << "Pilihan Anda (1/2): ";
      
        int choice;
        cin >> choice;
        
        cout << setw(80) << setfill('=') << "" << endl;
                        
        if (choice == 1) {
            displayProducts(products, MAX_PRODUCTS);
            {
			cout << "Apakah Anda ingin melakukan transaksi? (y/n): ";
        
        char pilihan;
        cin >> pilihan;
            
        if (pilihan == 'y' || pilihan == 'Y') {
            cout << "Anda ingin melakukan transaksi." << endl;
        } 
        else if (pilihan == 'n' || pilihan == 'N') {
            cout << "Anda tidak ingin melakukan transaksi." << endl;
        } 
        else {
            cout << "Pilihan tidak valid. Silakan jawab dengan 'y' atau 'n'." << endl;
        }
	    }
        }
        else if (choice == 2) {
	    
            cout << "Masukkan nomor produk yang akan dibeli: ";
            int productNumber;
            cin >> productNumber;

            if (productNumber >= 1 && productNumber <= MAX_PRODUCTS) {
                int quantity;
                cout << "Masukkan jumlah yang akan dibeli: ";
                cin >> quantity;

                Product selectedProduct = products[productNumber - 1];
                if (quantity > selectedProduct.stock) {
                    cout << "Stok tidak cukup!" << endl;
                }
                else {
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
            }
            else 
            {
                cout << "Nomor produk tidak valid!" << endl;
            }
        }
        else 
        {
            cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
        }
    }

    return 0;
}
