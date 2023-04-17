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

    return 0;
}
