#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

class Weapon {
private:
    string _name;
    int _damage;
    int _price;

public:
    // Public constructor to initialize armor details
    Weapon(const string name, int damage, int price)
    {
        _name = name;
        _damage = damage;
        _price = price;
    }

    // Getters
    string getName() const {
        return _name;
    }

    int getDamage() const
    {
        return _damage;
    }

    int getPrice() const
    {
        return _price;
    }

    // Setters
    void setName(const string &name) {
        _name = name;
    }

    void setDamage(int damage)
    {
        _damage = damage;
    }

    void setPrice(int price) {
        _price = price;
    }
};

class Armor {
private:
    string _name;
    int _resistance;
    int _price;

public:
    // Public constructor to initialize armor details
    Armor(const string &name, int resistance, int price)
    {
        _name = name;
        _resistance = resistance;
        _price = price;
    }

    // Getters
    string getName() const {
        return _name;
    }

    int getResistance() const
    {
        return _resistance;
    }

    int getPrice() const
    {
        return _price;
    }

    // Setters
    void setName(const string &name) {
        _name = name;
    }

    void setResistance(int resistance)
    {
        _resistance = resistance;
    }

    void setPrice(int price) {
        _price = price;
    }
};

// The menu will house the menu class, this will hold all of the weapons in the shop
// as well as the methods needed to add and remove items.
class Menu {
private:
    vector<Weapon> weapons;
    vector<Armor> armors;

public:
    // Constructor
    Menu() {
        weapons.push_back(Weapon("Short Sword", 10, 100));
        weapons.push_back(Weapon("Assasins Dagger", 15, 125));
        weapons.push_back(Weapon("Pantheon's Spear", 20, 150));

        armors.push_back(Armor("Knights Helm", 5, 100));
        armors.push_back(Armor("Knights Chest Plate", 15, 100));
        armors.push_back(Armor("Knights Chest Grieves", 15, 100));
    }

    void MainLoop() {
        // Welcome the user to the shop.
        cout << "Welcome to the Blacksmith Shop." << endl;

        // Initialize choice variable.
        int choice = 0;
        
        // Menu Options
        while (choice != 4) {
            // Display the Menu
            DisplayOptions();

            // Get their action choice.
            cout << "What would you like to do today? ";
            string response;
            cin >> response;

            // Convert response to an int.
            choice = stoi(response);

            switch (choice)
            {
            case 1:
                Inventory();
                break;
            case 2:
                AddItem();
                break;
            case 3:
                RemoveItem();
                break;
            default:
                break;
            }
        }
    }

    void DisplayOptions() {
        cout << "[1] Inventory." << endl;
        cout << "[2] Add Item." << endl;
        cout << "[3] Remove Item" << endl;
        cout << "[4] Leave System." << endl;
    };

    void Inventory() {   
        cout << "Here is the current items in the inventory." << endl;
        cout << " " << endl;
        // Iterate through the weapons vector displaying the info related to each armor.
        cout << "Weapons: " << endl;
        int i = 0;
        for (auto weapon : weapons) {
            cout << i + 1 << ". Name: " << weapon.getName() << ", Damage: " << weapon.getDamage() << ", Cost: " << weapon.getPrice() << endl;
            i += 1;
        }
        // Iterate through the armors vector displaying the info related to each armor.
        cout << "Armor: " << endl;
        i = 0;
        for (auto armor : armors) {
            cout << i + 1 << ". Name: " << armor.getName() << ", Resistance: " << armor.getResistance() << ", Cost: " << armor.getPrice() << endl;
            i += 1;
        }
    
        cout << endl;
    }

    void AddItem() {
        cout << "Would you like to add a weapon or armor? ";
        string choice;
        cin >> choice;

        if (choice == "weapon") {
            // Get the name
            string weaponName;
            cout << "Enter the weapon name: ";
            cin.ignore();
            getline(cin, weaponName);
            // Get the damage and convert response to int
            string weaponDamage;
            cout << "Enter the damage: ";
            cin >> weaponDamage;
            int weaponDamageInt = stoi(weaponDamage);
            // Get the cost and convert it to an int.
            string weaponCost;
            cout << "Enter the cost: ";
            cin >> weaponCost;
            int weaponCostInt = stoi(weaponCost);

            Weapon w = Weapon(weaponName, weaponDamageInt, weaponCostInt);
            weapons.push_back(w);
        } else if (choice == "armor") {
            // Get the name
            string armorName;
            cout << "Enter the armor name: ";
            cin.ignore();
            getline(cin, armorName);
            // Get the damage and convert response to int
            cout << "Enter the resistance: ";
            string armorResistance;
            cin >> armorResistance;
            int armorResistanceInt = stoi(armorResistance);
            // Get the cost and convert it to an int.
            cout << "Enter the cost: ";
            string armorCost;
            cin >> armorCost;
            int armorCostInt = stoi(armorCost);

            Armor a = Armor(armorName, armorResistanceInt, armorCostInt);
            armors.push_back(a);
        }

        cout << endl;
    }

    void RemoveItem() {
        // Display the current items.
        Inventory();
        cout << "Would you like to remove an weapon or armor: ";
        string response;
        cin >> response;

        if (response == "weapon") {
            cout << "Enter the weapon number you'd like to remove: ";
            cin >> response;
            int choice = stoi(response);
            weapons.erase(weapons.begin() + choice - 1);
        } else if (response == "armor") {
            cout << "Enter the armor number you'd like to remove: ";
            cin >> response;
            int choice = stoi(response);
            armors.erase(armors.begin() + choice - 1);
        }

        cout << endl;
    }
    
};

int main() {
    Menu m = Menu();

    m.MainLoop();

    return 0;
};