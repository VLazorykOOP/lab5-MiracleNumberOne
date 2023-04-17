#include <iostream>
#include <string>

class Student {
protected:
    std::string name;
    int course;
    int id;

public:
    // Конструктор з параметрами
    Student(const std::string& name, int course, int id)
        : name(name), course(course), id(id) {}

    // Деструктор
    ~Student() {
        std::cout << "Деструктор класу Студент: " << name << std::endl;
    }

    // Функція друку
    void print() const {
        std::cout << "ПІБ: " << name << ", Курс: " << course << ", ID: " << id << std::endl;
    }
};

class StudentDiploma : public Student {
private:
    std::string thesisTopic;

public:
    // Конструктор за замовчуванням
    StudentDiploma() : thesisTopic("") {}

    // Конструктор з параметрами
    StudentDiploma(const std::string& name, int course, int id, const std::string& thesisTopic)
        : Student(name, course, id), thesisTopic(thesisTopic) {}

    // Деструктор
    ~StudentDiploma() {
        std::cout << "Деструктор класу Студент-дипломник: " << name << std::endl;
    }

    // Функція друку
    void print() const {
        std::cout << "ПІБ: " << name << ", Курс: " << course << ", ID: " << id
                  << ", Тема диплома: " << thesisTopic << std::endl;
    }

    // Функції перепризначення назви диплома та ідентифікаційного номера
    void setThesisTopic(const std::string& thesisTopic) {
        this->thesisTopic = thesisTopic;
    }

    void setId(int id) {
        this->id = id;
    }
};

class Room {
private:
    double area; // Площа кімнати

public:
    // Конструктор
    Room(double _area) : area(_area) {}

    // Метод доступу до площі
    double getArea() const {
        return area;
    }
};

class OneBedroomApartment {
private:
    Room room;     // Кімната
    double kitchenArea; // Площа кухні
    int floor;     // Поверх

public:
    // Конструктор з параметрами
    OneBedroomApartment(double _roomArea, double _kitchenArea, int _floor)
        : room(_roomArea), kitchenArea(_kitchenArea), floor(_floor) {}

    // Метод доступу до площі кухні
    double getKitchenArea() const {
        return kitchenArea;
    }

    // Метод доступу до поверху
    int getFloor() const {
        return floor;
    }
};

class CityOneBedroomApartment : public OneBedroomApartment {
private:
    std::string cityName; // Назва міста

public:
    // Конструктор з параметрами
    CityOneBedroomApartment(double _roomArea, double _kitchenArea, int _floor, const std::string& _cityName)
        : OneBedroomApartment(_roomArea, _kitchenArea, _floor), cityName(_cityName) {}

    // Метод доступу до назви міста
    const std::string& getCityName() const {
        return cityName;
    }

    // Функція друку
    void print() const {
        std::cout << "One Bedroom Apartment in " << cityName << std::endl;
        std::cout << "Floor: " << getFloor() << std::endl;
        std::cout << "Room Area: " << room.getArea() << " sq.m" << std::endl;
        std::cout << "Kitchen Area: " << getKitchenArea() << " sq.m" << std::endl;
    }
};


int main() {
    // Тестування класу Студент
    Student student1("Іванов Іван Іванович", 2, 12345);
    student1.print();

    // Тестування класу Студент-дипломник
    StudentDiploma student2("Петров Петро Петрович", 4, 56789, "Аналіз даних");
    student2.print();

    // Перепризначення назви диплома та ідентифікаційного номера
    student2.setThesisTopic("Машинне навчання");
    student2.setId(98765);
    student2.print();

    
    // Створення об'єкту класу CityOneBedroomApartment
    CityOneBedroomApartment apartment(50.0, 10.0, 5, "Kyiv");

    // Виклик функції друку
    apartment.print();

    return 0;
}