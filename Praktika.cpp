#include <string>
#include <iostream>
#include <clocale>
#include <windows.h>
#include <math.h>
using namespace std;

class Armor
{
public:
    string name;
    int armor;
    Armor(string name, int armor)
    {
        this->name = name;
        this->armor = armor;
    }
};
class Ammo
{
public:
    string name;
    string type;
    int damage, count;
    Ammo(string name, string type, int damage)
    {
        this->name = name;
        this->type = type;
        this->damage = damage;
        this->count = 1;
    }
};
class Animal
{
public:
    string name;
    int health, damage, speed, unit;
    Animal(string name, int health, int damage, int speed)
    {
        this->name = name;
        this->health = health;
        this->damage = damage;
        this->speed = speed;
        this->unit=1;
    }
    void say()
    {
        cout << endl;
        cout << " Я " << name << endl;
        cout << "hp = " << health << endl;
        cout << "damage = " << damage << endl;
        cout << "speed = " << speed << endl;
    }
    int attack(int Damage)
	{
		health-=Damage;
		Damage=0;
		if (health<=0){ Damage=fabs(health); health=0; damage=0; unit=0;}
		return Damage;
	}
};
class Sold
{
public:
    string name; int health, damage, armor, unit;
    Sold(string name, int health, int damage, int armor, Armor dospeh)
    {
        this->name = name;
        this->health = health;
        this->damage = damage;
        this->armor = armor;
        this->armor += dospeh.armor;
        this->unit=1;
    }
    void say()
    {
        cout << endl;
        cout << "Я " << name << endl;
        cout << "hp = " << health << endl;
        cout << "damage = " << damage << endl;
        cout << "armor = " << armor << endl;
    }
        int attack(int Damage)
	{
		health-=Damage;
		Damage=0;
		if (health<=0){ Damage=fabs(health); health=0;damage=0; unit=0; armor=0;}
		return Damage;
	}
	int protect( int Damage){
		if (Damage>=armor){Damage-=armor; armor=0;}
		else {armor-=Damage; Damage=0;}
		return Damage;
	}
};
class Mex 
{
public:
    string name, type, ammotype; int health, damage, unit, ammo;
    Mex(string name, string ammotype, string type, int health, Ammo bullet)
    {
    	
        this->name = name;
        this->ammotype = ammotype;
        ammotype = bullet.name;
        this->type = type;
        type = bullet.type;
        this->health = health;
        this->damage = bullet.damage; 
		this->unit=1;   
		this->ammo = bullet.count;   
    }
    void say()
    {
        cout << endl;
        cout << "Я " << name << endl;
        cout << "AmmoType : " << ammotype << endl;
        cout << "Type : " << type << endl;
        cout << "hp = " << health << endl;
        cout << "damage = " << damage << endl;
    }
    int attack(int Damage)
	{
		health -= Damage;
		Damage=0;
		if (ammo=0){damage=0;}
		if (health<=0){ Damage=fabs(health); health=0;damage=0;unit=0;}
		return Damage;
	}
};
class Rider 
{
public:
    string name, type, rider;
    int speed, health, damage, armor, unit;
    Rider(string name, string type, int health, int damage, int speed, Sold Rogue, Animal Bear) 
    {
        this->name = name;
        this->type = type;
        type = Bear.name;
        rider = Rogue.name;
        this->health = health;
        this->health += Rogue.health;
        this->health += Bear.health;
        this->damage = damage;
        this->damage += Rogue.damage;
        this->damage += Bear.damage;
        this->speed = speed;
        speed = Bear.speed;
        this->armor=Rogue.armor;
        this->unit=1;
    }
    void say()
    {
        cout << endl;
        cout << "Я " << name << " " << rider << endl;
        cout << "animal : " << type << endl;
        cout << "hp = " << health << endl;
        cout << "damage = " << damage << endl;
        cout << "speed = " << speed << endl;
        cout << "armor = " << armor << endl;
    }
    int attack(int Damage)
	{
		health -= Damage;
		Damage=0;
		if (health<=0){ Damage=fabs(health); health=0;damage=0;unit=0;}
		return Damage;
	}
	int protect( int Damage){
		if (Damage>=armor){Damage-=armor; armor=0;}
		else {armor-=Damage; Damage=0;}
		return Damage;
	}
};

class Army {
public:
	int health, damage, defense, count;
	Army(int count, int health, int damage, int armor,  Animal Bear, Sold   Rogue, Mex    Ballista,  Mex    Cannon, Rider  rider1, Rider  rider2, Rider  rider3)
	{
		this->health = health + Bear.health + Rogue.health + Ballista.health + Cannon.health + rider1.health + rider2.health + rider3.health;
        this->damage = damage + Bear.damage + Rogue.damage + Ballista.damage + Cannon.damage + rider1.damage + rider2.damage + rider3.damage;
        this->defense = armor + Rogue.armor + rider1.armor + rider2.armor + rider3.armor;
        this->count = count + Bear.unit + Rogue.unit + Ballista.unit + Cannon.unit + rider1.unit + rider2.unit + rider3.unit;
	}
    void say () 
	{
    	cout << endl;
        cout << "Вся армия" << endl;
        cout << "hp = " << health << endl;
        cout << "damage = " << damage << endl;
        cout << "armor = " << defense << endl;
        cout << "в армии " << count << " воинов"<< endl;
	}
	    void attack( Animal Bear, Sold   Rogue, Mex    Ballista,  Mex    Cannon, Rider  rider1, Rider  rider2, Rider  rider3)
	{
		health = Bear.health + Rogue.health + Ballista.health + Cannon.health + rider1.health + rider2.health + rider3.health;
        damage = Bear.damage + Rogue.damage + Ballista.damage + Cannon.damage + rider1.damage + rider2.damage + rider3.damage;
        defense = Rogue.armor + rider1.armor + rider2.armor + rider3.armor;
        count = Bear.unit + Rogue.unit + Ballista.unit + Cannon.unit + rider1.unit + rider2.unit + rider3.unit;
	}
};

void Attack(int Damage, Animal &Bear, Sold   &Rogue, Mex    &Ballista,  Mex    &Cannon, Rider  &rider1, Rider  &rider2, Rider  &rider3, Army   &army);
void Say(Animal &Bear, Sold   &Rogue, Mex    &Ballista,  Mex    &Cannon, Rider  &rider1, Rider  &rider2, Rider  &rider3, Army   &army);

int main()
{
	SetConsoleCP(1251);      // подключаем русский язык 
	SetConsoleOutputCP(1251);// на вывод и ввод
	int Damage;
	
    Armor  SteelArmor("Steel Armor", 50);
    Ammo   Bolt("Bolt", "Untouchable Horror", 18);
    Ammo   Stone("Stone", "Loud Growing ShiftBludgeoning Absorption", 55);
    Animal Bear("Bear", 54, 15, 8);
    Sold   Rogue("Rogue", 38, 11, 0, SteelArmor);
    Mex    Ballista("ballista", Bolt.name, Bolt.type, 764, Bolt);
    Mex    Cannon("Cannon", Stone.name, Stone.type, 584, Stone);
    Rider  rider1("Rider 1 ", Bear.name, 0, 0, Bear.speed, Rogue, Bear);
    Rider  rider2("Rider 2 ", Bear.name, 0, 0, Bear.speed, Rogue, Bear);
    Rider  rider3("Rider 3 ", Bear.name, 0, 0, Bear.speed, Rogue, Bear);
    Army   army(0, 0, 0, 0, Bear, Rogue, Ballista, Cannon, rider1, rider2, rider3);
    
    Armor  SteelArmor2("Steel Armor", 50);
    Ammo   Bolt2("Bolt", "Untouchable Horror", 18);
    Ammo   Stone2("Stone", "Loud Growing ShiftBludgeoning Absorption", 55);
    Animal Bear2("Bear", 54, 15, 8);
    Sold   Rogue2("Rogue", 38, 11, 0, SteelArmor2);
    Mex    Ballista2("ballista", Bolt2.name, Bolt2.type, 764, Bolt2);
    Mex    Cannon2("Cannon", Stone2.name, Stone2.type, 584, Stone2);
    Rider  Rider1("Rider 1 ", Bear2.name, 0, 0, Bear2.speed, Rogue2, Bear2);
    Rider  Rider2("Rider 2 ", Bear2.name, 0, 0, Bear2.speed, Rogue2, Bear2);
    Rider  Rider3("Rider 3 ", Bear2.name, 0, 0, Bear2.speed, Rogue2, Bear2);
    Army   army2(0, 0, 0, 0, Bear2, Rogue2, Ballista2, Cannon2, Rider1, Rider2, Rider3);

    char menu,n;
    A: cout << "\n\nЧтобы вывести характеристики армии введите 1 \n";
       cout << "Чтобы начать атаку введите 2\n";
     
    cin >> menu;
    switch(menu)
	{
		case '1':
		    cout << "Чтобы вывести характеристики 1 армии введите '1', 2 армии введите '2': ";
	    	cin >> n;
	    	if (n=='1') Say( Bear, Rogue, Ballista, Cannon, rider1, rider2, rider3, army);
    		if (n=='2') Say( Bear2, Rogue2, Ballista2, Cannon2, Rider1, Rider2, Rider3, army2);
	    	if (n!='1' && n!='2'){cout << "Такой армии нет"; break;}
    	break;
    	case '2':
    		if (Ballista.ammo - 1==0){ Ballista.ammo-=1;Ballista.damage=0;} else Ballista.ammo-=1;
			if (Cannon.ammo - 1==0){Cannon.ammo-=1; Cannon.damage=0;} else Cannon.ammo-=1;
            Damage = Rogue2.protect(army.damage);
            Damage = Rider1.protect(Damage);
            Damage = Rider2.protect(Damage);
            Damage = Rider3.protect(Damage);
            Attack(Damage, Bear2, Rogue2, Ballista2, Cannon2, Rider1, Rider2, Rider3, army2);
        	if (army2.health<=0){cout << "\n Game Over! \n Победила первая армия\n"; break;}
			    
        	if (Ballista2.ammo - 1==0){ Ballista2.ammo-=1;Ballista2.damage=0;} else Ballista2.ammo-=1;
			if (Cannon2.ammo - 1==0){Cannon2.ammo-=1; Cannon2.damage=0;} else Cannon2.ammo-=1;
            Damage = Rogue.protect(army2.damage);
            Damage = rider1.protect(Damage);
            Damage = rider2.protect(Damage);
            Damage = rider3.protect(Damage);
            Attack(Damage, Bear, Rogue, Ballista, Cannon, rider1, rider2, rider3, army);
            if (army.health<=0){cout << "\n Game Over! \n Победила вторая армия\n"; break;}
    	    break;
        default: cout << "Такой команды нет. Введите другой символ : \n"; break;   
	}
	goto A;
    system("pause");
    return 0;
};

void Attack(int Damage, Animal &Bear, Sold   &Rogue, Mex    &Ballista,  Mex    &Cannon, Rider  &rider1, Rider  &rider2, Rider  &rider3, Army   &army){
	if (Ballista.unit>0 && Damage>0) {Damage = Ballista.attack(Damage);}
    if (Cannon.unit>0 && Damage>0) {Damage = Cannon.attack(Damage);}
    if (Rogue.unit>0 && Damage>0) {Damage = Rogue.attack(Damage);}
    if (Bear.unit>0 && Damage>0) {Damage = Bear.attack(Damage);}
    if (rider1.unit>0 && Damage>0) {Damage = rider1.attack(Damage);}
    if (rider2.unit>0 && Damage>0) {Damage = rider2.attack(Damage);}
    if (rider3.unit>0 && Damage>0) {Damage = rider3.attack(Damage);}
    if (army.count>0 ) army.attack(Bear, Rogue, Ballista, Cannon, rider1, rider2, rider3);
}

void Say(Animal &Bear, Sold   &Rogue, Mex    &Ballista,  Mex    &Cannon, Rider  &rider1, Rider  &rider2, Rider  &rider3, Army   &army){
	if (army.count>0){
		army.say(); 
		if (Ballista.unit>0) Ballista.say(); else cout << "\n Ballista мертв \n";
        if (Cannon.unit>0) Cannon.say();else cout << "\n Cannon мертв \n"; 
        if (Rogue.unit>0) Rogue.say(); else cout << "\n Rogue мертв \n";
        if (Bear.unit>0) Bear.say(); else cout << "\n Bear мертв  \n";
        if (rider1.unit>0) rider1.say(); else cout << "\n Rider1 мертв  \n";
        if (rider2.unit>0) rider2.say(); else cout << "\n Rider2 мертв  \n";
        if (rider3.unit>0) rider3.say(); else cout << "\n Rider3 мертв  \n";} 
	else cout << "\nАрмия мертва\n";}
