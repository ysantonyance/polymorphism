#include <iostream>
using namespace std;

class Animal
{
public:
	string name;
	int weight;
	int power;

	void Print() const
	{
		cout << "-------------------------------------\n";

		cout << "Name: " << name << "\n";
		if (weight > 0)
		{
			cout << "Weight: " << weight << "kg " << "\n\n";
		}

		if (power > 0)
		{
			cout << "Power: " << power << "atk" << "\n\n";
		}
	}
};

class Herbivore : public Animal
{
public:
	bool life = true;

	void EatGrass()
	{
		weight += 10;
	}
};

class Wildbeest : public Herbivore
{
public:
	Wildbeest()
	{
		name = "Wildbeest";
		weight = 200;
	}
};

class Bison : public Herbivore
{
public:
	Bison()
	{
		name = "Bison";
		weight = 1000;
	}
};

class Carnivore : public Animal
{
public:
	void Eat(Herbivore* victim)
	{
		cout << name << " ate " << victim->name;
		victim->life = false;
		if (power > victim->weight)
			power += 10;
		else
			power -= 10;
	}
};

class Lion : public Carnivore
{
public:
	Lion()
	{
		name = "Lion";
		power = 800;
	}
};

class Wolf : public Carnivore
{
public:
	Wolf()
	{
		name = "Wolf";
		power = 300;
	}
};

class Continent
{
public:
	string name;
};

class Africa : public Continent
{
public:
	Africa()
	{
		name = "Africa";
	}
};

class NorthAmerica : public Continent
{
public:
	NorthAmerica()
	{
		name = "North America";
	}
};

int main()
{
	//srand(time(0));
	Herbivore* herbivores[5];
	for (int i = 0; i < 5; i++)
	{
		int random = rand() % 2;
		if (random == 0)
			herbivores[i] = new Wildbeest();
		else
			herbivores[i] = new Bison();
	}

	cout << "Herbivores: \n";
	for (int i = 0; i < 5; i++)
	{
		herbivores[i]->Print();
	}

	Carnivore* carnivores[5];
	for (int i = 0; i < 5; i++)
	{
		int random = rand() % 2;
		if (random == 0)
			carnivores[i] = new Lion();
		else
			carnivores[i] = new Wolf();
	}

	cout << "Carnivores: \n";
	for (int i = 0; i < 5; i++)
	{
		carnivores[i]->Print();
	}

	Animal* animals[10];
	for (int i = 0; i < 10; i++)
	{
		int random = rand() % 4;
		switch (random)
		{
		case 0:
			animals[i] = new Wildbeest();
			break;
		case 1:
			animals[i] = new Bison();
			break;
		case 2:
			animals[i] = new Lion();
			break;
		case 3:
			animals[i] = new Wolf();
			break;
		}
	}

	cout << "All Animals: \n";
	for (int i = 0; i < 10; i++)
	{
		animals[i]->Print();
	}

	for (int i = 0; i < 5; i++)
	{
		delete herbivores[i];
		delete carnivores[i];
	}

	for (int i = 0; i < 10; i++)
	{
		delete animals[i];
	}
}