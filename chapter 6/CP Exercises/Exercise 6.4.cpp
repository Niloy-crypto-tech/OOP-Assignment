/*Improve the system design in Exercise 6.3 to incorporate the following
features:
(a) The price of the books should be updated as and when required. Use a private
member function to implement this.
(b) The stock value of each book should be automatically updated as soon as a
transaction is completed.
(c) The number of successful and unsuccessful transactions should be recorded for
the purpose of statistical analysis. Use static data members to keep count of
transactions. */

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

    static int successfulTransactions;
    static int unsuccessfulTransactions;

    // Private member function to update the price of the book
    void updatePrice(float newPrice) {
        price = newPrice;
        cout << "\nPrice updated successfully to $" << price << endl;
    }

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

    // Function to process an order
    void processOrder(int requestedCopies) {
        if (requestedCopies <= stock) {
            float totalCost = requestedCopies * price;
            cout << "\nTotal cost for " << requestedCopies << " copies: $" << totalCost;
            stock -= requestedCopies;
            successfulTransactions++;
            cout << "\nStock updated: " << stock << " copies remaining.";
        } else {
            cout << "\nRequired copies not in stock";
            unsuccessfulTransactions++;
        }
    }

    // Public function to update the price via user input
    void updateBookPrice() {
        float newPrice;
        cout << "\nEnter new price for the book \"" << title << "\": $";
        cin >> newPrice;
        updatePrice(newPrice);
    }

    // Static function to display transaction statistics
    static void displayTransactionStats() {
        cout << "\n\nTransaction Statistics:";
        cout << "\nSuccessful Transactions: " << successfulTransactions;
        cout << "\nUnsuccessful Transactions: " << unsuccessfulTransactions << endl;
    }
};

// Initialize static members
int Book::successfulTransactions = 0;
int Book::unsuccessfulTransactions = 0;

int main() {
    // Initialize some books
    Book book1("J.K. Rowling", "Harry Potter and the Sorcerer's Stone", "Bloomsbury", 20.99, 10);
    Book book2("George Orwell", "1984", "Secker & Warburg", 15.50, 5);
    Book book3("J.R.R. Tolkien", "The Hobbit", "Allen & Unwin", 12.80, 7);

    // Array of books in the shop's inventory
    Book* inventory[] = { &book1, &book2, &book3 };
    int inventorySize = sizeof(inventory) / sizeof(inventory[0]);

    // Input the title and author from the customer
    char searchTitle[50], searchAuthor[50];
    cout << "Enter the title of the book: ";
    cin.getline(searchTitle, 50);
    cout << "Enter the author of the book: ";
    cin.getline(searchAuthor, 50);

    // Search for the book in the inventory
    bool bookFound = false;
    for (int i = 0; i < inventorySize; i++) {
        if (inventory[i]->isBookAvailable(searchTitle, searchAuthor)) {
            bookFound = true;
            inventory[i]->displayBookDetails();

            // Option to update the price before processing the order
            char updateChoice;
            cout << "\nDo you want to update the price of this book? (y/n): ";
            cin >> updateChoice;
            if (updateChoice == 'y' || updateChoice == 'Y') {
                inventory[i]->updateBookPrice();
            }

            // Request the number of copies required
            int requestedCopies;
            cout << "\nEnter the number of copies required: ";
            cin >> requestedCopies;

            // Process the order
            inventory[i]->processOrder(requestedCopies);
            break;
        }
    }

    if (!bookFound) {
        cout << "\nBook not available in inventory.";
        Book::unsuccessfulTransactions++;
    }

    // Display transaction statistics
    Book::displayTransactionStats();

    return 0;
}
