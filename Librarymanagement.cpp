#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <ctime>

using namespace std;

struct Book {
    string title;
    string author;
    string ISBN;
    bool isAvailable;
};

struct Borrower {
    string name;
    unordered_map<string, time_t> borrowedBooks;
};

vector<Book> books;
unordered_map<string, Borrower> borrowers;
const double finePerDay = 1.0;

void to_add_a_Book() 
{
    Book newBook;
    cout << "Enter the book title which u want enter: ";
    cin.ignore();
    getline(cin, newBook.title);
    cout << "Enter the book author: ";
    getline(cin, newBook.author);
    cout << "Enter the book ISBN: ";
    getline(cin, newBook.ISBN);
    newBook.isAvailable = true;
    books.push_back(newBook);
    cout << "Book added successfully." << endl;
}

void to_searchBook() 
{
    string query;
    cout << "Enter the title, author, or ISBN to search: ";
    cin.ignore();
    getline(cin, query);

    for (const auto& book : books) 
    {
        if (book.title == query || book.author == query || book.ISBN == query) 
        {
            cout << "Title: " << book.title << ", Author: " << book.author 
                 << ", ISBN: " << book.ISBN << ", Availability: " 
                 << (book.isAvailable ? "Available" : "Checked out") << endl;
        }
    }
}

void checkoutBook() 
{
    string isbn, borrowerName;
    cout << "Enter borrower name: ";
    cin.ignore();
    getline(cin, borrowerName);
    cout << "Enter the book ISBN to checkout: ";
    getline(cin, isbn);

    for (auto& book : books) 
    {
        if (book.ISBN == isbn && book.isAvailable) 
        {
            book.isAvailable = false;
            time_t now = time(0);
            borrowers[borrowerName].borrowedBooks[isbn] = now;
            cout << "Book checked out successfully." << endl;
            return;
        }
    }
    cout << "Book not available for checkout." << endl;
}

void to_returnBook() 
{
    string isbn, borrowerName;
    cout << "Enter borrower name: ";
    cin.ignore();
    getline(cin, borrowerName);
    cout << "Enter book ISBN to return: ";
    getline(cin, isbn);

    auto& borrower = borrowers[borrowerName];
    if (borrower.borrowedBooks.find(isbn) != borrower.borrowedBooks.end()) 
    {
        time_t borrowedTime = borrower.borrowedBooks[isbn];
        time_t now = time(0);
        double daysOverdue = difftime(now, borrowedTime) / (60 * 60 * 24) - 14;

        if (daysOverdue > 0) 
        {
            double fine = daysOverdue * finePerDay;
            cout << "Book returned late. Fine: $" << fine << endl;
        } 
        else 
        {
            cout << "Book returned on time. No fine." << endl;
        }

        borrower.borrowedBooks.erase(isbn);
        for (auto& book : books) 
        {
            if (book.ISBN == isbn) 
            {
                book.isAvailable = true;
                break;
            }
        }
    } 
    else 
    {
        cout << "No record of this book being borrowed by " << borrowerName << "." << endl;
    }
}

void to_showMenu() 
{
    cout << "\nLibrary Management System" << endl;
    cout << "1. Add The Book" << endl;
    cout << "2. Search Any Book" << endl;
    cout << "3. Checkout  The Book" << endl;
    cout << "4. Return The Book" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
}

int main() 
{
    int ch;
    while (true) 
    {
        to_showMenu();
        cin >> ch;
        switch (ch) 
        {
            case 1:
                to_add_a_Book();
                break;
            case 2:
                to_searchBook();
                break;
            case 3:
                checkoutBook();
                break;
            case 4:
                to_returnBook();
                break;
            case 5:
                cout << "Exiting Library Management System. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
    return 0;
}
