#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Interface Observer
class Observer {
public:
    virtual ~Observer() {}
    virtual void update() = 0;
};

// Interface Subject
class Subject {
public:
    virtual ~Subject() {}
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify() = 0;
};

// Concrete Subject: WeatherStation
class WeatherStation : public Subject {
private:
    int temperature;
    int humidity;
    std::string skyConditions;
    std::vector<Observer*> observers;
public:
    void attach(Observer* observer) override {
        observers.push_back(observer);
    }

    void detach(Observer* observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify() override {
        for (Observer* observer : observers) {
            observer->update();
        }
    }

    void setWeather(int temp, int hum, std::string sky) {
        temperature = temp;
        humidity = hum;
        skyConditions = sky;
        notify();
    }

    const int getTemperature() { return temperature; }
    int getHumidity() { return humidity; }
    std::string getSkyConditions() { return skyConditions; }
};

// Concrete Observer: TemperatureWidget
class TemperatureWidget : public Observer {
private:
    WeatherStation* weatherStation;
public:
    TemperatureWidget(WeatherStation* ws) : weatherStation(ws) {}

    void update() override {
        std::cout << "Temperature Widget updated. Current temperature: " << weatherStation->getTemperature() << "C\n";
    }
};

// Concrete Observer: HumidityWidget
class HumidityWidget : public Observer {
private:
    WeatherStation* weatherStation;
public:
    HumidityWidget(WeatherStation* ws) : weatherStation(ws) {}

    void update() override {
        std::cout << "Humidity Widget updated. Current humidity: " << weatherStation->getHumidity() << "%\n";
    }
};

// Concrete Observer: SkyConditionsWidget
class SkyConditionsWidget : public Observer {
private:
    WeatherStation* weatherStation;
public:
    SkyConditionsWidget(WeatherStation* ws) : weatherStation(ws) {}

    void update() override {
        std::cout << "Sky Conditions Widget updated. Current conditions: " << weatherStation->getSkyConditions() << "\n";
    }
};

// Main function
int main() {
    WeatherStation weatherStation;

    TemperatureWidget tempWidget(&weatherStation);
    HumidityWidget humWidget(&weatherStation);
    SkyConditionsWidget skyWidget(&weatherStation);

    weatherStation.attach(&tempWidget);
    weatherStation.attach(&humWidget);
    weatherStation.attach(&skyWidget);

    // Simulando mudanças nas condições climáticas
    weatherStation.setWeather(25, 70, "Partly Cloudy");
    weatherStation.setWeather(30, 65, "Sunny");

    // Removendo um widget
    weatherStation.detach(&humWidget);

    weatherStation.setWeather(28, 60, "Mostly Cloudy");

    return 0;
}
