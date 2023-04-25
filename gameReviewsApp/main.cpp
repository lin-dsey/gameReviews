#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct GameReview {
    string name;
    string review;
    int rating;
    string dateCompleted;
    string genre;
};

vector<GameReview> gameReviews;

void addReview() {
    GameReview review;
    cout << "Enter game name: ";
    getline(cin, review.name);
    cout << "Enter review: ";
    getline(cin, review.review);
    cout << "Enter rating (0-10): ";
    cin >> review.rating;
    cin.ignore();
    cout << "Enter date completed (MM/DD/YYYY): ";
    getline(cin, review.dateCompleted);
    cout << "Enter genre: ";
    getline(cin, review.genre);
    gameReviews.push_back(review);
    cout << "Review added successfully!" << endl;
}

void displayReviews() {
    if (gameReviews.empty()) {
        cout << "No reviews to display." << endl;
        return;
    }
    for (const auto& review : gameReviews) {
        cout << "Game name: " << review.name << endl;
        cout << "Review: " << review.review << endl;
        cout << "Rating: " << review.rating << endl;
        cout << "Date completed: " << review.dateCompleted << endl;
        cout << "Genre: " << review.genre << endl;
        cout << endl;
    }
}

void searchReviewsByGenre() {
    string genre;
    cout << "Enter genre to search for: ";
    getline(cin, genre);
    transform(genre.begin(), genre.end(), genre.begin(), ::tolower); // convert to lowercase
    bool found = false;
    for (const auto& review : gameReviews) {
        string reviewGenre = review.genre;
        transform(reviewGenre.begin(), reviewGenre.end(), reviewGenre.begin(), ::tolower); // convert to lowercase
        if (reviewGenre == genre) {
            cout << "Game name: " << review.name << endl;
            cout << "Review: " << review.review << endl;
            cout << "Rating: " << review.rating << endl;
            cout << "Date completed: " << review.dateCompleted << endl;
            cout << "Genre: " << review.genre << endl;
            cout << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No reviews found for genre \"" << genre << "\"." << endl;
    }
}

int main() {
    while (true) {
        cout << "1. Add review" << endl;
        cout << "2. Display reviews" << endl;
        cout << "3. Search reviews by genre" << endl;
        cout << "4. Exit" << endl;
        int choice;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        cout << endl;
        switch (choice) {
            case 1:
                addReview();
                break;
            case 2:
                displayReviews();
                break;
            case 3:
                searchReviewsByGenre();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
    return 0;
}
