#include "Garage.h"
#include <cassert>

int main()
{
    try
    {
        // Create vehicles
        Car c1("Toyota", "Corolla", "Blue", EngineType::Hybrid, 122);
        Car c2("BMW", "M3", "Quicksilver", EngineType::Gasoline, 480);
        Truck t1("MAN", "TGS", "White", 12.5, "Construction materials");
        Truck t2("Volvo", "FH16", "Red", 20.0, "Heavy equipment");

        // Create garage with capacity for 6 vehicles
        Garage g(6);

        // Add vehicles (Garage clones them)
        assert(g.addVehicle(&c1));
        assert(g.addVehicle(&c2));
        assert(g.addVehicle(&t1));
        assert(g.addVehicle(&t2));

        std::cout << "Initial garage contents:" << std::endl;
        g.printGarage();

        // Total tax
        double total = g.getTotalTax();
        std::cout << "Total tax: " << total << std::endl << std::endl;

        // Access via operator[] (returns a clone; caller owns it)
        Vehicle* v0 = g[0];
        std::cout << "Clone of first vehicle:" << std::endl;
        v0->print();
        delete v0;
        std::cout << std::endl;

        // Remove by model+brand (try removing BMW M3 and a non-existent one)
        bool removed = g.removeVehicleByModelAndBrand("M3", "BMW");
        std::cout << "Removed BMW M3: " << (removed ? "yes" : "no") << std::endl;
        bool removedNone = g.removeVehicleByModelAndBrand("NoModel", "NoBrand");
        std::cout << "Removed non-existent: " << (removedNone ? "yes" : "no") << std::endl;

        std::cout << "\nAfter removal:" << std::endl;
        g.printGarage();
        std::cout << "Total tax now: " << g.getTotalTax() << std::endl << std::endl;

        // Test copy constructor
        Garage gCopy(g);
        std::cout << "Copied garage contents:" << std::endl;
        gCopy.printGarage();

        // Test assignment operator (same fixed capacity)
        Garage gAssign(6);
        gAssign = g;
        std::cout << "Assigned garage contents:" << std::endl;
        gAssign.printGarage();

        // Fill to capacity and test capacity guard
        Car c3("VW", "Golf", "White", EngineType::Diesel, 150);
        Car c4("Audi", "A4", "Gray", EngineType::Hybrid, 190);
        Truck t3("Scania", "R500", "Blue", 18.0, "Machinery");

        assert(g.addVehicle(&c3));
        assert(g.addVehicle(&c4));
        assert(g.addVehicle(&t3));
        // Next add should fail due to GARAGE_CAPACITY limit (6)
        bool addedOver = g.addVehicle(&c1);
        std::cout << "Attempt to exceed capacity: " 
                  << (addedOver ? "unexpectedly succeeded" : "correctly rejected") 
                  << std::endl;

        std::cout << "\nFinal garage contents:" << std::endl;
        g.printGarage();

        std::cout << "All tests ran successfully." << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Exception: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
