#include <algorithm>
#include <iostream>
#include <vector>

class Person
{
private:
    static std::vector<Person*> osoby;
    std::string imie;
    std::string nazwisko;

public:

    Person(std::string i, std::string n)
    :imie(i), nazwisko(n)
    {
        std::cout << "Tworze " << imie << " " << nazwisko << "\n";
        osoby.push_back(this);
    }

    Person(const Person& p)
    :imie(p.imie), nazwisko(p.nazwisko)
    {
        std::cout << "Kopiuje " << imie << " " << nazwisko << "\n";
        osoby.push_back(this);
    }

    ~Person(void)
    {
        std::cout << "Usuwam "<< imie << " " << nazwisko << "\n";
        Person::osoby.erase(std::find(osoby.begin(),osoby.end(), this));
    }

    std::string Imie(void) const
    {
        return imie;
    }

    std::string Nazwisko(void) const
    {
        return nazwisko;
    }

    static void OutputPersons(std::ostream& wyjscie)
    {
        wyjscie << "lista osob:\n";

        for (unsigned int i = 0; i < osoby.size(); ++i)
        {
            std::cout << osoby[i]->imie << ' ' << osoby[i]->nazwisko << std::endl;
        }
    }
};

std::vector<Person*> Person::osoby;

class Worker
{
    Person person_;
    std::string position_;

public:

    Worker(const Person& person, std::string position)
    : person_(person), position_(position)
    {}
};

void Fun2(void)
{
    Person s("Dariusz", "Dabacki");
    Person t("Eugeniusz", "Ebacki");
    {
        Person u("Franciszek", "Fabacki");
    }
    Worker w(Person("Grzegorz","Gabacki"),"guard");
    Person::OutputPersons(std::cout);
}

void Fun(void)
{
    Person* pq = new Person("Bartosz", "Babacki");
    Person r("Czeslaw", "Cabacki");
    Fun2();
    delete pq;
}

int main(void)
{
    Person p("Adam", "Abacki");
    Fun();

    std::cin.get();

    return 0;
}
