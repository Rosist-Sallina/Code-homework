#include "book.h"

Book::Book(int ID, string name, string author, string publishing_house)
{
    this->ID = ID;
	this->name = name;
	this->author = author;
	this->publishing_house = publishing_house;
	state.first = false; // Set state to available
}

int Book::get_ID() {
    return ID;
}

string Book::get_name() {
    return name;
}

string Book::get_author() {
    return author;
}

string Book::get_publishing_house() {
    return publishing_house;
}

bool Book::get_state() {
    return state.first;
}

void Book::change_state() {
    state.first = !state.first; // Toggle state between borrowed and available
    if (!state.first) { // If borrowed, clear borrower name
        state.second = "";
    }
}

void Book::change_state(string borrower) {
    state.first = true; // Mark as borrowed
    state.second = borrower; // Set borrower name
}

void Book::print_message() {
    cout << "ID:" << ID << "\nname:" << name << "\nauthor:" << author
        << "\npublishing_house:" << publishing_house;
    if (state.first) {
        cout << "\nborrower:" << state.second << endl<< "state:borrowed\n";
    } else {
        cout << "\nstate:loanable" << endl;
    }
}
