#include <iostream>
#include <string>
using namespace std;

// 1. ENGINE CLASS
class Engine {
private:
    const int engineNumber; 
    string type;
    int horsePower;
    string fuelType;
    string transmission;

public:
    // Default Constructor
    Engine() : engineNumber(0) {
        type = "Unknown"; horsePower = 0; fuelType = "Petrol"; transmission = "Manual";
    }

    // Parametrized Constructor
    Engine(int num, string t, int hp, string f, string tr)
        : engineNumber(num), type(t), horsePower(hp), fuelType(f), transmission(tr) {}

    // Copy Constructor
    Engine(const Engine &e) : engineNumber(e.engineNumber) {
        type = e.type; horsePower = e.horsePower; fuelType = e.fuelType; transmission = e.transmission;
    }

    // Member Functions
    void display() const { 
        cout << "   [Engine] No: " << engineNumber << ", Type: " << type 
             << ", HP: " << horsePower << ", Fuel: " << fuelType << endl;
    }
    void upgradeHP(int add) { horsePower += add; }
    void changeFuel(string f) { fuelType = f; }
    bool isPowerful() const { return horsePower > 200; }

    // Getters and Setters
    int getEngineNumber() const { return engineNumber; }
    string getType() const { return type; }
    void setType(string t) { type = t; }
};

// 2. LOCATION CLASS
class Location {
private:
    string city, area, province, country;
    int postalCode;

public:
    Location() { city = area = province = "Unknown"; country = "Pakistan"; postalCode = 0; }
    Location(string c, string a, string p, string co, int pc)
        : city(c), area(a), province(p), country(co), postalCode(pc) {}

    void display() const {
        cout << "   [Location] " << area << ", " << city << ", " << country << " (" << postalCode << ")" << endl;
    }
    void updatePostal(int p) { postalCode = p; }
    string getFullAddress() const { return area + ", " + city; }
    bool isInternational() const { return country != "Pakistan"; }

    // Getters and Setters
    string getCity() const { return city; }
    void setCity(string c) { city = c; }
};

// 3. VEHICLE CLASS
class Vehicle {
private:
    const int vehicleID; 
    string brand, model;
    double price;
    int year, mileage;
    bool approved;

    Engine engine;   
    Location location;

public:
    Vehicle() : vehicleID(0), engine(), location() {
        brand = model = "Unknown"; price = 0; year = 0; mileage = 0; approved = false;
    }

    Vehicle(int id, string b, string m, double p, int y, int mil, Engine e, Location l)
        : vehicleID(id), brand(b), model(m), price(p), year(y), mileage(mil), engine(e), location(l), approved(false) {}

    // Copy Cons
    Vehicle(const Vehicle &v) 
        : vehicleID(v.vehicleID), brand(v.brand), model(v.model),
          price(v.price), year(v.year), mileage(v.mileage), engine(v.engine), location(v.location), approved(v.approved) {}

    void approve() { approved = true; }
    void applyDiscount(double percent) { price -= (price * (percent / 100)); }
    bool isVintage() const { return year < 2000; }
    
    void display() const {
        cout << "\nVehicle ID: " << vehicleID << " | " << year << " " << brand << " " << model 
             << " | Price: PKR " << price << " | Approved: " << (approved ? "Yes" : "No") << endl;
        engine.display();
        location.display();
    }

    bool matchesFilter(string b, string m, double minP, double maxP, int minY, int maxM) const {
        return approved && (brand == b || b == "") && (model == m || m == "") &&
               price >= minP && price <= maxP && year >= minY && mileage <= maxM;
    }

    // Getters and Setters
    int getVehicleID() const { return vehicleID; }
    void setBrand(string b) { brand = b; }
    void setModel(string m) { model = m; }
    void setPrice(double p) { price = p; }
    void setYear(int y) { year = y; }
    void setMileage(int m) { mileage = m; }
};

// 4. USER-BASE CLASS
class User {
protected:
    const int userID;
    string name, email, role;

public:
    User() : userID(0) { name = email = "Unknown"; role = "Guest"; }
    User(int id, string n, string e, string r) : userID(id), name(n), email(e), role(r) {}
    
    virtual void display() const {
        cout << "User ID: " << userID << " | Name: " << name << " | Role: " << role << endl;
    }
    virtual void updateEmail(string e) { email = e; }
    string getName() const { return name; }
    int getID() const { return userID; }
    bool isAdmin() const { return role == "Admin"; }
};

// 5. MESSAGE CLASS
class Message {
private:
    static int counter; 
    const int messageID;
    int senderID, receiverID;
    string text;

public:
    Message(int s, int r, string t) : messageID(++counter), senderID(s), receiverID(r), text(t) {}

    static int getTotalMessages() { return counter; }
    void display() const {
        cout << "   Msg [" << messageID << "] From User " << senderID << ": " << text << endl;
    }
    int getSender() const { return senderID; }
    string getText() const { return text; }
};
int Message::counter = 0;

// 6. BUYER CLASS
class Buyer : public User {
private:
    Vehicle** favorites; 
    int favCount, maxFav;
    Message** inbox;
    int msgCount, maxMsg;

public:
    Buyer(int id, string n, string e) : User(id, n, e, "Buyer") {
        maxFav = 5; favCount = 0; favorites = new Vehicle*[maxFav];
        maxMsg = 5; msgCount = 0; inbox = new Message*[maxMsg];
    }

    void saveFavorite(Vehicle v) {
        if (favCount < maxFav) favorites[favCount++] = new Vehicle(v);
        else cout << "Favorites full!\n";
    }
    void viewFavorites() const {
        cout << "--- " << name << "'s Favorites ---";
        for (int i = 0; i < favCount; i++) favorites[i]->display();
    }
    void receiveMessage(Message* m) {
        if (msgCount < maxMsg) inbox[msgCount++] = m;
    }
    void clearInbox() { msgCount = 0; cout << "Inbox cleared.\n"; }

    ~Buyer() {
        for (int i = 0; i < favCount; i++) delete favorites[i];
        delete[] favorites; delete[] inbox;
    }
};

// 7. SELLER CLASS
class Seller : public User {
private:
    Vehicle** myAds;
    int adCount, maxAds;

public:
    Seller(int id, string n, string e) : User(id, n, e, "Seller") {
        maxAds = 10; adCount = 0; myAds = new Vehicle*[maxAds];
    }

    void addVehicle(Vehicle v) {
        if (adCount < maxAds) myAds[adCount++] = new Vehicle(v);
    }
    void viewAds() const {
        for (int i = 0; i < adCount; i++) myAds[i]->display();
    }
    void updatePrice(int id, double p) {
        for (int i = 0; i < adCount; i++) if (myAds[i]->getVehicleID() == id) myAds[i]->setPrice(p);
    }
    int getAdCount() const { return adCount; }

    ~Seller() {
        for (int i = 0; i < adCount; i++) delete myAds[i];
        delete[] myAds;
    }
};

// 8. ADMIN CLASS
class Admin : public User {
public:
    Admin(int id, string n, string e) : User(id, n, e, "Admin") {}

    void approveVehicle(Vehicle &v) { v.approve(); cout << "Admin: Vehicle Approved.\n"; }
    void removeUser(int id) { cout << "Admin: User " << id << " removed from database.\n"; }
    void systemAudit() { cout << "Admin: Running system diagnostic...\n"; }
    void banSeller(string reason) { cout << "Seller banned. Reason: " << reason << endl; }
};

// 9. SEARCH FILTER CLASS
class SearchFilter {
private:
    string brand;
    double maxP;

public:
    void setFilter(string b, double p) { brand = b; maxP = p; }
    void apply(Vehicle** vArr, int count) {
        cout << "\n--- Search Results ---";
        for (int i = 0; i < count; i++) {
            if (vArr[i]->matchesFilter(brand, "", 0, maxP, 0, 1000000)) vArr[i]->display();
        }
    }
    void reset() { brand = ""; maxP = 100000000; }
    string getActiveBrand() { return brand; }
};

// 10. MARKETPLACE CLASS
class Marketplace {
private:
    Vehicle** store;
    int vCount;
    User** community; 
    int uCount;

    static int totalGlobalAds; 

public:
    Marketplace() {
        vCount = uCount = 0;
        store = new Vehicle*[100];
        community = new User*[50];
    }

    void registerUser(User* u) { community[uCount++] = u; }
    void postAd(Vehicle v) { store[vCount++] = new Vehicle(v); totalGlobalAds++; }
    
    void displayStore() {
        if (vCount == 0) cout << "Market is empty.\n";
        for (int i = 0; i < vCount; i++) store[i]->display();
    }
    
    static int getGlobalAdCount() { return totalGlobalAds; }
    Vehicle** getStore() { return store; }
    int getVCount() { return vCount; }

    ~Marketplace() {
        for (int i = 0; i < vCount; i++) delete store[i];
        delete[] store; delete[] community;
    }
};
int Marketplace::totalGlobalAds = 0;

// MAIN
int main() {
    Marketplace pakWheels;

    // User Setup
    Admin* boss = new Admin(1, "SuperAdmin", "boss@wheels.com");
    Seller* s1 = new Seller(2, "Shoaib", "shoaib@cars.com");
    Buyer* b1 = new Buyer(3, "Ali", "ali@buyer.com");

    pakWheels.registerUser(boss);
    pakWheels.registerUser(s1);
    pakWheels.registerUser(b1);

    // Add Vehicle 
    Engine e1(555, "V6", 300, "Petrol", "Auto");
    Location l1("Lahore", "DHA", "Punjab", "Pakistan", 54000);
    Vehicle v1(101, "Honda", "Civic", 4500000, 2022, 12000, e1, l1);

    s1->addVehicle(v1);
    boss->approveVehicle(v1); 
    pakWheels.postAd(v1);

    Vehicle* const fixedPointer = pakWheels.getStore()[0]; 

    // Menu 
    int choice;
    do {
        cout << "\n1. View Market\n2. Search Honda\n3. Save Favorite (Buyer)\n4. Send Msg\n5. View Stats\n6. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) pakWheels.displayStore();
        else if (choice == 2) {
            SearchFilter sf;
            sf.setFilter("Honda", 5000000);
            sf.apply(pakWheels.getStore(), pakWheels.getVCount());
        }
        else if (choice == 3) {
            if (pakWheels.getVCount() > 0) b1->saveFavorite(*fixedPointer);
            b1->viewFavorites();
        }
        else if (choice == 4) {
            Message* m = new Message(3, 2, "Is the Civic available?");
            b1->receiveMessage(m);
            m->display();
        }
        else if (choice == 5) {
            cout << "Total Ads ever created: " << Marketplace::getGlobalAdCount() << endl;
            cout << "Total Messages sent: " << Message::getTotalMessages() << endl;
        }
    } while (choice != 6);

    delete boss;
    delete s1; 
    delete b1;

    return 0;


}