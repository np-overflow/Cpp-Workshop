#include <iostream>
#include <string>
#include <ctime>
#include <memory>

class Weapon{
    public:
        std::string name;
        int damage;

        Weapon(std::string n, int dmg) : name(n), damage(dmg) {};
};

class Character{
    protected:
        std::string name;
        int max_health;
        int health;
        Weapon weapon;

    public:
        Character(std::string n, int hp, Weapon weap) : name(n), max_health(hp), health(hp), weapon(weap) {}

        std::string get_name() {
            return name;
        }

        int get_health() {
            return health;
        }

        void attack(Character& target) {
            int damage = weapon.damage;
            std::cout << name << " attacks with " << weapon.name << "\n";
            if (rand() % 10 == 0) {
                damage *= 2;
                std::cout << "Critical hit!" << "\n";
            }
            target.health -= damage;
            std::cout << "It dealt " << damage << " damage!" << "\n";
            std::cout << "\n";
        }
};

class Player : public Character{
    public:
        Player(std::string n, int hp, Weapon weap) : Character(n, hp, weap) {};

        void heal() {
            health += 30;
            if (health > max_health) {
                health = max_health;
            }
            std::cout << name << " healed!" << "\n";
        }

        std::string choose_action() {
            std::cout << "1. Attack" << "\n";
            std::cout << "2. Heal" << "\n";
            std::cout << "Choose your action: ";

            std::string choice;
            std::cin >> choice;
            while (choice != "1" && choice != "2") {
                std::cout << "Invalid choice. Choose again: ";
                std::cin >> choice;
            }
            std::cout << "\n";

            return choice;
        }

        void player_turn(Character& target) {
            std::string action = choose_action();
            if (action == "1") {
                attack(target);
            } else if (action == "2") {
                heal();
            }
        }
};

int main() {  
    srand(time(0));
    
    Weapon sword("Sword", 25);
    Weapon club("Club", 15);

    Character orc("Orc", 100, club);

    Player player("Hero", 100, sword);

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
}