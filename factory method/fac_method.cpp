#include <iostream>
#include <string>

// Abstract Product: Building
class Building {
public:
    virtual ~Building() {}
    virtual std::string getType() const = 0;
    virtual void displayInfo() const;
};

// Concrete Products: Residence and Commerce
class Residence : public Building {
public:
    std::string getType() const override {
        return "Residence";
    }

    void displayInfo() const override {
        std::cout << "This is a residence building." << std::endl;
    }
};

class Commerce : public Building {
public:
    std::string getType() const override {
        return "Commerce";
    }

    void displayInfo() const override {
        std::cout << "This is a commerce building." << std::endl;
    }
};

// Abstract Creator: BuildingCreator
class BuildingCreator {
public:
    virtual ~BuildingCreator() {}
    virtual Building* createBuilding() = 0;

    void someOperation() const {
        Building* product = createBuilding();
        std::cout << "Creator: The same creator's code has just worked with " << product->getType() << std::endl;
        product->displayInfo();
        delete product;
    }
};

// Concrete Creators: ResidenceCreator and CommerceCreator
class ResidenceCreator : public BuildingCreator {
public:
    Building* createBuilding() override {
        return new Residence();
    }
};

class CommerceCreator : public BuildingCreator {
public:
    Building* createBuilding() override {
        return new Commerce();
    }
};

// Client Code
int main() {
    std::cout << "Creating a residence:" << std::endl;
    ResidenceCreator residenceCreator;
    residenceCreator.someOperation();
    std::cout << std::endl;

    std::cout << "Creating a commerce:" << std::endl;
    CommerceCreator commerceCreator;
    commerceCreator.someOperation();
    return 0;
}
