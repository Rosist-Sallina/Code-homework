#include "library.h"

void Library::add_book(Book book) {
    for (auto& b : Books) {
        if (b.get_ID() == book.get_ID()) {
            cout << "Add Failed: Book already exists" << endl;
            return;
        }
    }
    Books.push_back(book);
    cout << "Added:" << book.get_name() << endl;
}

void Library::delete_book(int book_ID) {
    for (auto it = Books.begin() ; it != Books.end() ; it++) {
        if (it->get_ID() == book_ID) {
            cout << "Deleted:" << it->get_name() << endl;
            Books.erase(it);
            return;
        }
    }
    cout << "Delete Failed" << endl;
}

void Library::find_book(int book_ID) {
    for (auto& book : Books) {
        if (book.get_ID() == book_ID) {
            book.print_message();
            return;
        }
    }
    cout << "Find Failed" << endl;
}

void Library::borrow_book(int book_ID, string borrower) {
    for (auto& book : Books) {
        if (book.get_ID() == book_ID) {
            if (book.get_state()) {
                cout << "Borrow Failed: Book already borrowed" << endl;
                return;
            }
            book.change_state(borrower);
            cout << "Borrowed:" << book.get_name() << endl;
            return;
        }
    }
    cout << "Borrow Failed" << endl;
}

void Library::return_book(int book_ID) {
    for (auto& book : Books) {
        if (book.get_ID() == book_ID) {
            if (!book.get_state()) {
                cout << "Return Failed: Book not borrowed" << endl;
                return;
            }
            book.change_state();
            cout << "Returned:" << book.get_name() << endl;
            return;
        }
    }
    cout << "Return Failed" << endl;
}
