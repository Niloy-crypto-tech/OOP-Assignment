// 6.5 : Modify the program of exercise 6.4 to demostrate the use of pointers to access the members 
#include <iostream>
#include <cstring>

using namespace std;

class Book {
private:
    char* author;
    char* title;
    char* publisher;
    float price;
    int stock;

    // Private member function to update the price
    void updatePrice(float newPrice) {
        price = newPrice;
        cout << "\nPrice updated to $" << price;
    }

    // Static members to track transactions
    static int successfulTransactions;
    static int unsuccessfulTransactions;

public:
    // Constructor to initialize book details
    Book(const char* authorName, const char* titleName, const char* publisherName, float bookPrice, int stockCount) {
        author = new char[strlen(authorName) + 1];
        strcpy(author, authorName);

        title = new char[strlen(titleName) + 1];
        strcpy(title, titleName);

        publisher = new char[strlen(publisherName) + 1];
        strcpy(publisher, publisherName);

        price = bookPrice;
        stock = stockCount;
    }

    // Destructor to free allocated memory
    ~Book() {
        delete[] author;
        delete[] title;
        delete[] publisher;
    }

    // Function to check if a book matches the provided title and author
    bool isBookAvailable(const char* searchTitle, const char* searchAuthor) {
        return strcmp(title, searchTitle) == 0 && strcmp(author, searchAuthor) == 0;
    }

    // Function to display book details
    void displayBookDetails() const {
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nPublisher: " << publisher;
        cout << "\nPrice: $" << price;
        cout << "\nStock: " << stock;
    }

    // Function to process the order
    void processOrder(int requestedCopies) {
        if (requestedCopies <= stock) {
            float totalCost = requestedCopies * price;
            cout << "\nTotal cost for " << requestedCopies << " copies: $" << totalCost;
            stock -= requestedCopies;
            successfulTransactions++;
        } else {
            cout << "\nRequired copies not in stock";
            unsuccessfulTransactions++;
        }
    }

    // Public function to allow the price to be updated
    void changePrice(float newPrice) {
        updatePrice(newPrice);
    }

    // Static function to display transaction statistics
    static void displayTransactionStats() {
        cout << "\nSuccessful Transactions: " << successfulTransactions;
        cout << "\nUnsuccessful Transactions: " << unsuccessfulTransactions;
    }
};

// Initializing static members
int Book::successfulTransactions = 0;
int Book::unsuccessfulTransactions = 0;

int main() {
    // Initialize some books
    Book book1("J.K. Rowling", "Harry Potter and the Sorcerer's Stone", "Bloomsbury", 20.99, 10);
    Book book2("George Orwell", "1984", "Secker & Warburg", 15.50, 5);
    Book book3("J.R.R. Tolkien", "The Hobbit", "Allen & Unwin", 12.80, 7);

    // Array of pointers to books in the shop's inventory
    Book* inventory[] = { &book1, &book2, &book3 };
    int inventorySize = sizeof(inventory) / sizeof(inventory[0]);

    // Input the title and author from the customer
    char searchTitle[50], searchAuthor[50];
    cout << "Enter the title of the book: ";
    cin.getline(searchTitle, 50);
    cout << "Enter the author of the book: ";
    cin.getline(searchAuthor, 50);

    // Search for the book in the inventory using pointers
    Book* foundBook = nullptr;
    for (int i = 0; i < inventorySize; i++) {
        if (inventory[i]->isBookAvailable(searchTitle, searchAuthor)) {
            foundBook = inventory[i];
            foundBook->displayBookDetails();

            // Request the number of copies required
            int requestedCopies;
            cout << "\nEnter the number of copies required: ";
            cin >> requestedCopies;

            // Process the order using pointer
            foundBook->processOrder(requestedCopies);
            break;
        }
    }

    if (!foundBook) {
        cout << "\nBook not available in inventory.";
        Book::unsuccessfulTransactions++;
    }

    // Allow updating the price of a book (optional)
    cout << "\nDo you want to update the price of a book? (y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        cout << "Enter the title of the book: ";
        cin.ignore();
        cin.getline(searchTitle, 50);
        cout << "Enter the author of the book: ";
        cin.getline(searchAuthor, 50);

        for (int i = 0; i < inventorySize; i++) {
            if (inventory[i]->isBookAvailable(searchTitle, searchAuthor)) {
                float newPrice;
                cout << "Enter the new price: ";
                cin >> newPrice;
                inventory[i]->changePrice(newPrice);
                break;
            }
        }
    }

    // Display transaction statistics using pointer
    Book::displayTransactionStats();

    return 0;
}
