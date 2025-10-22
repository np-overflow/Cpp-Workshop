import random


class Character:

    def __init__(self, name, max_health, weapon):
        self.name = name
        self.max_health = max_health
        self.health = max_health
        self.weapon = weapon
    
    def attack(self, target):
        damage = self.weapon.damage
        if random.randint(1, 10) == 1:
            damage *= 2  # Critical hit
            print("Critical hit!")
        target.health -= self.weapon.damage
        print(f"{self.name} attacks {target.name} for {damage} damage!")


class Player(Character):

    def heal(self):
        self.health += 30
        if self.health > self.max_health:
            self.health = self.max_health
        print(f"{self.name} heals!")

    def choose_action(self):
        print("Your turn!")
        print("(1) Attack")
        print("(2) Heal")
        action = input("Choose action [1-2]:")
        while action not in ['1', '2']:
            action = input("Invalid input. Choose action [1-2]: ")
        return action
    
    def act(self, target):
        action = self.choose_action()
        if action == '1':
            self.attack(target)
            print(f"{self.name} attacks!")
        elif action == '2':
            self.heal()
            print(f"{self.name} heals!")


class Weapon:

    def __init__(self, name, damage):
        self.name = name
        self.damage = damage


def main():
    player_name = input("Enter your character's name: ")
    player = Player(name=player_name, max_health=100, weapon=Weapon("Sword", 20))
    enemy = Character(name="Orc", max_health=50, weapon=Weapon("Club", 15))

    while player.health > 0 and enemy.health > 0:
        print()
        print(player.name, "/ Health:", player.health)
        print("Enemy / Health:", enemy.health)
        print()
        player.act(enemy)
        enemy.attack(player)
        print("Enemy attacks!")
    
    if player.health <= 0:
        print("You have been defeated!")
    else:
        print("You have defeated the enemy!")


if __name__ == "__main__":
    main()

# Stuff that can be added by workshop students during and after the workshop:

# Basic
# - Add more weapons
# - Add more enemies for the player to fight and continue the game
# - Defense stat

# Intermediate
# - Add an armour class to modify defense stat
# - Make a seperate class for attacks and add more attacks (e.g. spells)
# - Add levels, experience points and gold which can be dropped by enemies

# Advanced
# - Add a shop after defeating an enemy where the player can buy random weapons and armour
# - Make more enemy types with different moves and behaviours
# - Finish the game with a bossfight!