#include <iostream>
#include <string>
using namespace std;


class String {
protected:
    string str;

public:
    String() : str("") {}

    String(const char* s) : str(s) {}

    String(const String& other) : str(other.str) {}

    String& operator=(const String& other) {
        if (this != &other) {
            str = other.str;
        }
        return *this;
    }

    size_t length() const {
        return str.length();
    }

    void clear() {
        str.clear();
    }

    
    String operator+(const String& other) const {
        return String(str + other.str);
    }

    String& operator+=(const String& other) {
        str += other.str;
        return *this;
    }

    bool operator==(const String& other) const {
        return str == other.str;
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    const char* getStr() const {
        return str.c_str();
    }

    void toLower() {
        for (char& ch : str) {
            ch = tolower(ch);
        }
    }

    void toUpper() {
        for (char& ch : str) {
            ch = toupper(ch);
        }
    }

    String substring(size_t start, size_t length) const {
        return String(str.substr(start, length));
    }
};


class BitString : public String {
public:
    BitString() : String() {}

    BitString(const char* s) : String() {
        if (isValid(s)) {
            str = s;
        }
        else {
            clear();
        }
    }

    bool isValid(const char* s) {
        for (size_t i = 0; i < str.length(); ++i) {
            if (s[i] != '0' && s[i] != '1') {
                return false;
            }
        }
        return true;
    }

    void changeSign() {
        for (size_t i = 0; i < str.length(); ++i) {
            str[i] = (str[i] == '0') ? '1' : '0';
        }
    }

    BitString operator+(const BitString& other) const {
        return BitString(str + other.str); 
    }

    BitString& operator+=(const BitString& other) {
        str += other.str;
        return *this;
    }

    bool operator==(const BitString& other) const {
        return str == other.str;
    }

    bool operator!=(const BitString& other) const {
        return !(*this == other);
    }

    int toDecimal() const {
        int result = 0;
        for (size_t i = 0; i < str.length(); ++i) {
            result = result * 2 + (str[i] - '0');
        }
        return result;
    }

    BitString fromDecimal(int number) {
        string result;
        if (number == 0) {
            result = "0";
        }
        else {
            while (number > 0) {
                result = (number % 2 == 0 ? '0' : '1') + result;
                number /= 2;
            }
        }
        return BitString(result.c_str());
    }
};


class DomesticAnimal {
protected:
    string name;
    int age;

public:
    DomesticAnimal(string n, int a) : name(n), age(a) {}

    virtual void speak() = 0; 
    virtual ~DomesticAnimal() {}

    void showInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Клас для собак
class Dog : public DomesticAnimal {
public:
    Dog(string n, int a) : DomesticAnimal(n, a) {}

    void speak() override {
        cout << name << " says Woof!" << endl;
    }

    void favoriteGame() {
        cout << name << " loves playing fetch!" << endl;
    }
};


class Cat : public DomesticAnimal {
public:
    Cat(string n, int a) : DomesticAnimal(n, a) {}

    void speak() override {
        cout << name << " says Meow!" << endl;
    }
};


class Parrot : public DomesticAnimal {
public:
    Parrot(string n, int a) : DomesticAnimal(n, a) {}

    void speak() override {
        cout << name << " says Squawk!" << endl;
    }
};

class Fish : public DomesticAnimal {
public:
    Fish(string n, int a) : DomesticAnimal(n, a) {}

    void speak() override {
        cout << name << " says Blub!" << endl;
    }
};


class Rabbit : public DomesticAnimal {
public:
    Rabbit(string n, int a) : DomesticAnimal(n, a) {}

    void speak() override {
        cout << name << " says Thump!" << endl;
    }
};

int main() {
    
    Dog dog("Mike", 3);
    Cat cat("Tommy", 2);
    Parrot parrot("Polly", 5);
    Fish fish("Goldie", 1);
    Rabbit rabbit("Fluffy", 2);

    
    DomesticAnimal* animals[] = { &dog, &cat, &parrot, &fish, &rabbit };

    for (DomesticAnimal* animal : animals) {
        animal->showInfo();
        animal->speak();
    }

   
    BitString b1("1101");
    BitString b2("1010");

    cout << "BitString 1: " << b1.getStr() << endl;
    cout << "BitString 2: " << b2.getStr() << endl;

    b1.changeSign();
    cout << "After change sign: " << b1.getStr() << endl;

    BitString b3 = b1 + b2;
    cout << "Concatenation: " << b3.getStr() << endl;

    cout << "Decimal of BitString 1: " << b1.toDecimal() << endl;

    BitString b4 = b4.fromDecimal(13);
    cout << "BitString of decimal 13: " << b4.getStr() << endl;

    return 0;
}
