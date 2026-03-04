// Create:
// Media
// Book
// Video
// Audio
// Demonstrate shared and specific features.

#include <iostream>
using namespace std;

// Base Class
class Media {
    public:
    string title;

    void getMedia() {
        cout << "Enter Title: ";
        cin.ignore(); 
        getline(cin, title);
    }

    void showMedia() {
        cout << "Title: " << title << endl;
    }
};

// Derived Class: Book
class Book : public Media {
    public:
    int pages;

    void getBook() {
        cout << "Enter Number of Pages: ";
        cin >> pages;
    }

    void showBook() {
        showMedia(); 
        cout << "Pages: " << pages << endl;
    }
};

// Derived Class: Video
class Video : public Media {
    public:
    double duration; 

    void getVideo() {
        cout << "Enter Duration (minutes): ";
        cin >> duration;
    }

    void showVideo() {
        showMedia(); 
        cout << "Duration: " << duration << " minutes" << endl;
    }
};

// Derived Class: Audio
class Audio : public Media {
    public:
    string artist;

    void getAudio() {
        cin.ignore(); 
        cout << "Enter Artist Name: ";
        getline(cin, artist);
    }

    void showAudio() {
        showMedia(); 
        cout << "Artist: " << artist << endl;
    }
};

int main() {

    cout << "--- Book ---" << endl;
    Book b;
    b.getMedia();
    b.getBook();
    b.showBook();

    cout << "\n--- Video ---" << endl;
    Video v;
    v.getMedia();
    v.getVideo();
    v.showVideo();

    cout << "\n--- Audio ---" << endl;
    Audio a;
    a.getMedia();
    a.getAudio();
    a.showAudio();

    return 0;
}