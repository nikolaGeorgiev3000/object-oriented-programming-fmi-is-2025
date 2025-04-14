#include <iostream>

const int MAX_LEN = 21;

struct Vegetable
{
    char name[MAX_LEN];
    double weight;

    void inputVegetable()
    {
        std::cout << "Vegetable name: ";
        std::cin.getline(name, MAX_LEN);

        std::cout << "Vegetable weight: ";
        std::cin >> weight;
        std::cin.ignore(); // For the next getline()
    }
};

struct Dressing
{
    char name[MAX_LEN];
    double quantity;
    char allergen[MAX_LEN];

    void inputDressing()
    {
        std::cout << "Dressing name: ";
        std::cin.getline(name, MAX_LEN);

        std::cout << "Dressing quantity: ";
        std::cin >> quantity;
        std::cin.ignore();

        std::cout << "Allergen name: ";
        std::cin.getline(allergen, MAX_LEN);
        std::cin.ignore();
    }
};

struct Salad
{
    char name[MAX_LEN];
    Vegetable veggies[3];
    Dressing dressing;
    double price;

    void inputSalad()
    {
        std::cout << "Salad name: ";
        std::cin.getline(name, MAX_LEN);

        for (short i = 0; i < 3; i++)
        {
            veggies[i].inputVegetable();
        }

        dressing.inputDressing();

        std::cout << "Salad price: ";
        std::cin >> price;
        std::cin.ignore();
    }

    double getWeight() const
    {
        double toReturn = 0;

        for (int i = 0; i < 3; i++)
        {
            toReturn += veggies[i].weight;
        }

        return toReturn;
    }

    void printAllergen() const
    {
        std::cout << dressing.allergen << std::endl;
    }

    void print()
    {
        std::cout << this->name << std::endl
                  << std::endl;

        std::cout << "Contents:\n";

        for (int i = 0; i < 3; i++)
        {
            std::cout << veggies[i].name << " ";
        }
        std::cout << dressing.name << std::endl;

        std::cout << "Price: " << price << std::endl;
        std::cout << "Weight: " << this->getWeight() << std::endl;
        std::cout << "Allergen: " << dressing.allergen << std::endl;
    }
};

void analyseSalads(Salad salads[], int n)
{
    std::cout << "Salads: ";

    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        std::cout << salads[i].name << " ";
        sum += salads[i].price;
    }
    std::cout << "\nTotal cost: " << sum << " leva.\n";

    std::cout << "Allergens: ";
    for (int i = 0; i < n; i++)
    {
        salads[i].printAllergen();
        std::cout << ", ";
    }
    std::cout << std::endl;
}

int main()
{
    Salad salad1;
    salad1.inputSalad();
    std::cout << std::endl;
    salad1.print();

    Salad salad_arr[5];
    for (int i = 0; i < 5; i++)
        salad_arr[i].inputSalad();

    analyseSalads(salad_arr, 5);

    return 0;
}
