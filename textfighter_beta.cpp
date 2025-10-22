#include <iostream>
#include <string>
#include <ctime>
#include <memory>

using namespace std::string_literals;

class Weapon{
    public:
        // These attributes are public so they are accessible by Characters
        std::string name;
        int damage;

        // Constructor that uses arguments
        Weapon(const std::string& n, int dmg) : name(n), damage(dmg) {}
};

class Character{
    protected:
        std::string name;
        int max_health;
        int health;
        Weapon& weapon;
    
    public:
        Character(const std::string& n, int hp, Weapon& weap) : name(n), max_health(hp), health(hp), weapon(weap) {}
        
        // Public methods to access private attributes
        std::string get_name() const {
            return name;
        }

        int get_health() const {
            return health;
        }

        void attack(Character& target){
            // Using the attributes of the Weapon object, we can get the object name and damge.
            std::cout << name << " attacks with " << weapon.name << "\n";
            int damage = weapon.damage;
            if (rand() % 4 == 0) { 
                damage *= 2;
                std::cout << "Critical hit!" << "\n";
            }
            target.health -= damage;
            std::cout << "It deals " << damage << " damage to " << target.name << "!\n";
            std::cout << "\n";
        };
};

class Player : public Character{
    public:
        Player(std::string n, int hp, Weapon& weap) : Character(n, hp, weap) {}

        void heal(){
            health += 30;
            if (health > max_health){
                health = max_health;
            }
            std::cout << name << " healed 30 HP!" << "\n";
        }

        std::string choose_action(){
            std::cout << "1. Attack" << "\n";
            std::cout << "2. Heal" << "\n";
            std::cout << "Choose your action: ";

            std::string choice;
            std::cin >> choice;
            while (choice != "1" && choice != "2") {
                std::cout << "Invalid choice! Please try again.";
                std::cin >> choice;
            }
            std::cout << "\n";
            
            return choice;
        }

        void player_turn(Character& target){
            std::string action = choose_action();
            if (action == "1"){
                attack(target);
            } else if (action == "2"){
                heal();
            }
        }
};

int main() {
    // Set a random seed so that it's different every time
    srand(time(0));

    // Weapons
    Weapon sword("Sword", 25);
    Weapon club("Club", 15);

    // Enemies
    Character orc("Orc", 100, club);

    // Player
    Player player("Hero", 100, sword);

    // Battle loop
    while (true) {
        std::cout << player.get_name() << " HP: " << player.get_health() << "\n";
        std::cout << orc.get_name() << " HP: " << orc.get_health() << "\n";

        player.player_turn(orc);
        if (orc.get_health() <= 0) {
            std::cout << player.get_name() << " wins!" << "\n";
            break;
        }
        orc.attack(player);
        if (player.get_health() <= 0) {
            std::cout << orc.get_name() << " wins!" << "\n";
            break;
        }
    }

    return 0;
};
