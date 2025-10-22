#include <iostream>
#include <string>
#include <random>
#include <utility>

using namespace std::string_literals;

class Weapon{
    public:
        // These attributes are public so they are accessible by Characters
        std::string name;
        int damage;

        // Constructor that uses arguments
        Weapon(std::string  n, const int dmg) : name(std::move(n)), damage(dmg) {}
};

class Character{
    protected:
        std::string name;
        int max_health;
        int health;
        Weapon& weapon;

    public:
        Character(std::string  n, const int hp, Weapon& weap) : name(std::move(n)), max_health(hp), health(hp), weapon(weap) {}

        // Public methods to access private attributes
        [[nodiscard]] std::string get_name() const {
            return name;
        }

        [[nodiscard]] int get_health() const {
            return health;
        }

        void attack(Character& target) const {
            // Using the attributes of the Weapon object, we can get the object name and damge.
            std::cout << name << " attacks with " << weapon.name << "\n";
            int damage = weapon.damage;
            auto rd {std::random_device{}};
            auto mt = std::mt19937{rd()};
            if (auto uniform = std::uniform_int_distribution<int>{1, 100}; uniform(mt) % 4 == 0) {
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
        Player(const std::string &n, const int hp, Weapon& weap) : Character(n, hp, weap) {}

        void heal(){
            health += 30;
            if (health > max_health){
                health = max_health;
            }
            std::cout << name << " healed 30 HP!" << "\n";
        }

        static int choose_action(){
            std::cout << "1. Attack" << "\n";
            std::cout << "2. Heal" << "\n";
            std::cout << "Choose your action: ";

            int choice;
            while (!(std::cin >> choice) || choice < 1 || choice > 2) {
                std::cout << "Invalid input. Please enter 1 or 2: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            return choice;
        }

        void player_turn(Character& target){
            int action = choose_action();
            switch (action) {
                case 1:
                    attack(target);
                    break;
                case 2:
                    heal();
                    break;
            }
        }
};

int main() {
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
