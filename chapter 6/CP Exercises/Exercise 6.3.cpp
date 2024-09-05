/* 6.3: A book shop maintains the inventory of books that are being sold at the shop.
The list includes details such as author, title, price, publisher and stock position.
Whenever a customer wants a book, the sales person inputs the title and author
and the system searches the list and displays whether it is available or not. If it is
not, an appropriate message is displayed. If it is, then the system displays the
book details and requests for the number of copies required. If the requested
copies are available, the total cost of the requested copies is displayed; otherwise
“Required copies not in stock” is displayed.
Design a system using a class called books with suitable member functions and
constructors. Use new operator in constructors to allocate memory space required. */

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

    // Function to check and process the order
    void processOrder(int requestedCopies) {
        if (requestedCopies <= stock) {
            float totalCost = requestedCopies * price;
            cout << "\nTotal cost for " << requestedCopies << " copies: $" << totalCost;
            stock -= requestedCopies;
        } else {
            cout << "\nRequired copies not in stock";
        }
    }
};

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
    }

    return 0;
}
