#include <iostream>
#include <cstdlib>
#include <cassert>

#include "Calc.hpp"

auto test_Calc(void) -> void
{
    Calc c;
    std::string view;
    int update_count = 0;
    c.SetDisplayUpdateHandler([&](std::string nv)
            {
            ++update_count;
            view = nv;
            });
    c.Press(Calc::Zero);
    assert(update_count == 0);
    c.Press(Calc::Sep); // separator dziesiętny
    assert(update_count == 1);
    assert(view == "0.");
    c.Press({Calc::Two,Calc::Five});
    assert(update_count == 3);
    assert(view == "0.25");
    c.Press({Calc::Mul,Calc::Add});
    assert(update_count == 3);
    c.Press({Calc::Sep,Calc::Seven,Calc::Five});
    assert(update_count == 6);
    assert(view == "0.75");
    c.Press({Calc::Eq});
    assert(update_count == 7);
    assert(view == "1");
    c.Press({Calc::Sub,Calc::Div});
    assert(update_count == 7);
    assert(view == "1");
    c.Press({Calc::Four,Calc::Eq});
    assert(update_count == 9);
    assert(view == "0.25");

    std::cerr << "Klasa pomyslnie przeszla testy.\n";
}

int main( void ) {
    test_Calc();

    std::cin.get();
    std::cout << std::endl;
    std::cin.get();
    return 0;
}
