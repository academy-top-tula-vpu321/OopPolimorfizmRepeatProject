#include <iostream>
#include <string>
#include <cstdint>

class Fraction
{
    int n, d;
public:
    Fraction(int n, int d) : n{ n }, d{ d } {};
    
    int getN() { return n; }
    int getD() { return d; }

    std::string ToString()
    {
        return "[" + std::to_string(n)
            + "/" + std::to_string(d) + "]";
    }
};

template <typename T>
T sum(T a, T b)
{
    return a + b;
}

Fraction sum(Fraction a, Fraction b)
{
    return Fraction(a.getN() * b.getD() + a.getD() * b.getN(), a.getD() * b.getD());
}


class Base
{
public:
    Base()
    {
        std::cout << "Base construct\n";
    }

    virtual void BaseMethod()
    {
        std::cout << "Base method work\n";
    }

    ~Base()
    {
        std::cout << "Base destruct\n";
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        std::cout << "Derived construct\n";
    }

    void BaseMethod() override
    {
        std::cout << "Derived oerflow Base method and work\n";
    }

    void DerivedMethod()
    {
        std::cout << "Derived method work\n";
    }

    ~Derived()
    {
        std::cout << "Derived destruct\n";
    }
};

class SecondDerived : public Derived
{
public:
    void BaseMethod() override
    {
        std::cout << "Second Derived oerflow Base method and work\n";
    }
};



class Gadget
{
public:
    int value;
    Gadget(int value = 0) : value{value}
    {
        std::cout << this << " " 
            << this->value << " Gadget construct\n";
    }
};

class Scanner : virtual public Gadget
{
public:
    Scanner() : Gadget(10)
    {
        std::cout << this << " Scanner construct\n";
    }
};

class Printer : virtual public Gadget
{
public:
    Printer() : Gadget(20)
    {
        std::cout << this << " Printer construct\n";
    }
};

class Copier : public Scanner, public Printer
{
public:
    Copier() : Gadget(30)
    {
        std::cout << this << " Copier construct\n";
    }
};


template <typename T>
class User
{
    T id;
};

class DocPrint
{
public:
    template <typename T>
    void Print(T message)
    {
        std::cout << message << "\n";
    }
};



template <typename T>
class Storage
{
    T value;
public:
    Storage(T value = 0) : value{ value } {};
    T& Value() { return value; }
    void Print()
    {
        std::cout << value << "\n";
    }
    ~Storage() {}
};

template <typename T>
class Storage<T*>
{
    T* value;
public:
    Storage(T* value) : value{ new T(*value) } {}
    ~Storage() { delete value; }
    void Print()
    {
        std::cout << *value << "\n";
    }
};

template <>
void Storage<double>::Print()
{
    std::cout << std::scientific << value << "\n";
}

template <>
Storage<char*>::Storage(char* value)
{
    if (!value) return;
    int length{};
    while (value[length] != '\0')
        ++length;
    ++length;
    this->value = new char[length];
    for (int i{}; i < length; i++)
        this->value[i] = value[i];
}

template <>
Storage<char*>::~Storage()
{
    std::cout << "Storage for char* destruct\n";
    delete[] value;
}


/*
template <typename T>
class Storage8
{
    T array[8]{};
public:
    T& operator[](int index)
    {
        return array[index];
    }
};

template <>
class Storage8<bool>
{
    std::uint8_t value{};
public:
    void Set(int index, bool value)
    {
        auto mask = 1 << index;
        if (value)
            this->value |= mask;
        else
            this->value &= ~mask;
    }

    bool Get(int index)
    {
        auto mask = 1 << index;
        return this->value & mask;
    }
};
*/


int main()
{
    /*Base base;
    Derived derived;

    base = derived;

    Base* basePtr = new Base();
    Derived* derivedPtr = new Derived();
    

    derivedPtr->DerivedMethod();
    ((Derived*)basePtr)->DerivedMethod();
    std::cout << "\n";

    basePtr->BaseMethod();
    derivedPtr->BaseMethod();
    std::cout << "\n";

    delete basePtr;
    basePtr = derivedPtr;

    basePtr->BaseMethod();
    derivedPtr->BaseMethod();

    delete derivedPtr;
    */

    /*
    Copier* copier = new Copier();
    std::cout << "\n";

    Scanner* scanner = new Scanner();
    std::cout << "\n";

    Printer* printer = new Printer();
    */

    /*
    DocPrint* printer = new DocPrint();
    printer->Print<int>(100.56);
    */

    /*
    Fraction f1(2, 5);
    Fraction f2(3, 7);
    Fraction f3 = sum(f1, f2);
    std::cout << f3.ToString() << "\n";
    */

    /*
    Storage<int> sv(100);
    sv.Print();

    Storage<float> fv(45.78);
    fv.Print();

    Storage<double> dv(45.78);
    dv.Print();

    std::string name;
    std::cout << "Input name: ";
    std::cin >> name;

    Storage<char*> cv((char*)name.c_str());
    cv.Print();

    name.clear();
    cv.Print();
    */

    /*
    Storage8<int> arrInt;
    std::cout << sizeof(arrInt) << "\n";
    for (int i{}; i < 8; i++)
        arrInt[i] = (i + 1) * 2;
    for (int i{}; i < 8; i++)
        std::cout << arrInt[i] << " ";
    std::cout << "\n";

    Storage8<double> arrDbl;
    std::cout << sizeof(arrDbl) << "\n";
    for (int i{}; i < 8; i++)
        arrDbl[i] = (i + 1) / 2.0;
    for (int i{}; i < 8; i++)
        std::cout << arrDbl[i] << " ";
    std::cout << "\n";

    Storage8<bool> arrBl;
    std::cout << sizeof(arrBl) << "\n";
    for (int i{}; i < 8; i++)
        arrBl.Set(i, i % 2);
    for (int i{}; i < 8; i++)
        std::cout << std::boolalpha << arrBl.Get(i) << " ";
    std::cout << "\n";
    */

    Storage<int> iv(10);
    iv.Print();

    int n{ 20 };
    Storage<int*> ipv(&n);
    ipv.Print();
    
}
