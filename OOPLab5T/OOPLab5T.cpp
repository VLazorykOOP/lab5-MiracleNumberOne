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

class SportGame {
protected:
    std::string gameType;
    int numOfPlayers;
public:
    // Конструктор за замовчуванням
    SportGame() : gameType(""), numOfPlayers(0) {}
    
    // Конструктор з параметрами
    SportGame(const std::string& type, int numPlayers) : gameType(type), numOfPlayers(numPlayers) {}
    
    // Конструктор копіювання
    SportGame(const SportGame& other) : gameType(other.gameType), numOfPlayers(other.numOfPlayers) {}
    
    // Конструктор перенесення
    SportGame(SportGame&& other) : gameType(std::move(other.gameType)), numOfPlayers(other.numOfPlayers) {}
    
    // Оператор присвоєння
    SportGame& operator=(const SportGame& other) {
        if (this == &other) return *this; // Перевірка на самоприсвоєння
        
        gameType = other.gameType;
        numOfPlayers = other.numOfPlayers;
        
        return *this;
    }
    
    // Оператор перенесення
    SportGame& operator=(SportGame&& other) {
        if (this == &other) return *this; // Перевірка на самоприсвоєння
        
        gameType = std::move(other.gameType);
        numOfPlayers = other.numOfPlayers;
        
        return *this;
    }
    
    // Функції вводу/виводу
    virtual void input(std::istream& is) {
        std::cout << "Введіть тип гри: ";
        is >> gameType;
        std::cout << "Введіть кількість гравців: ";
        is >> numOfPlayers;
    }
    
    virtual void output(std::ostream& os) const {
        os << "Тип гри: " << gameType << ", Кількість гравців: " << numOfPlayers;
    }
    
    friend std::istream& operator>>(std::istream& is, SportGame& game) {
        game.input(is);
        return is;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const SportGame& game) {
        game.output(os);
        return os;
    }
};

class Football : public SportGame {
private:
    std::string team1;
    std::string team2;
public:
    // Конструктор за замовчуванням
    Football() : SportGame(), team1(""), team2("") {}
    
    // Конструктор з параметрами
    Football(const std::string& type, int numPlayers, const std::string& t1, const std::string& t2)
        : SportGame(type, numPlayers), team1(t1), team2(t2) {}
    
    // Конструктор копіювання
    Football(const Football& other)
        : SportGame(other), team1(other.team1), team2(other.team2) {}
    
    // Конструктор перенесення
    Football(Football&& other)
        : SportGame(std::move(other)), team1(std::move(other.team1)), team2(std::move(other.team2)) {}
    
    // Оператор присвоєння
    Football& operator=(const Football& other) {
        if (this == &other) return *this; // Перевірка на самоприсвоєння
        
        SportGame::operator=(other); // Виклик оператора присвоєння базового класу
        
        team1 = other.team1;
        team2 = other.team2;
        
        return *this;
    }
    
    // Оператор перенесення
    Football& operator=(Football&& other) {
        if (this == &other) return *this; // Перевірка на самоприсвоєння
        
        SportGame::operator=(std::move(other)); // Виклик оператора перенесення базового класу
        
        team1 = std::move(other.team1);
        team2 = std::move(other.team2);
        
        return *this;
    }
    
    // Функції вводу/виводу
    void input(std::istream& is) override {
        SportGame::input(is); // Виклик функції вводу базового класу
        std::cout << "Введіть назву команди 1: ";
        is >> team1;
        std::cout << "Введіть назву команди 2: ";
        is >> team2;
    }
    
    void output(std::ostream& os) const override {
        SportGame::output(os); // Виклик функції виводу базового класу
        os << ", Команда 1: " << team1 << ", Команда 2: " << team2;
    }
    
    friend std::istream& operator>>(std::istream& is, Football& football) {
        football.input(is);
        return is;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Football& football) {
        football.output(os);
        return os;
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


    // Створення об'єкту класу Football за допомогою конструктора за замовчуванням
    Football football1;
    std::cout << "Футбол 1: " << football1 << std::endl;
    
    // Введення даних в об'єкт football1
    std::cin >> football1;
    
    // Створення об'єкту класу Football за допомогою конструктора з параметрами
    Football football2("Футбол", 11, "Команда 1", "Команда 2");
    std::cout << "Футбол 2: " << football2 << std::endl;
    
    // Введення даних в об'єкт football2
    std::cin >> football2;
    
    // Створення об'єкту класу Football за допомогою конструктора копіювання
    Football football3 = football2;
    std::cout << "Футбол 3: " << football3 << std::endl;
    
    // Створення об'єкту класу Football за допомогою конструктора перенесення
    Football football4 = std::move(football3);
    std::cout << "Футбол 4: " << football4 << std::endl;
    
    // Введення даних в об'єкт football4
    std::cin >> football4;
    
    // Оператор присвоєння
    football1 = football4;
    std::cout << "Футбол 1 (після оператора присвоєння): " << football1 << std::endl;
    
    // Оператор перенесення
    football2 = std::move(football4);
    std::cout << "Футбол 2 (після оператора перенесення): " << football2 << std::endl;
    
    return 0;
}