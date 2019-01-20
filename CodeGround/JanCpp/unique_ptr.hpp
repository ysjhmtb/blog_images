
#ifndef JANCPP_UNIQUE_PTR_HPP
#define JANCPP_UNIQUE_PTR_HPP


// http://bunhere.tistory.com/407

#include <iostream>
#include <memory>   // unique_ptr


class House {

private:
    int m_window;
    int m_door;

public:
    House(int window, int door)
            : m_window(window), m_door(door) {}

    int window() const { return m_window; }

    int door() const { return m_door; }

};


void usingUniquePtr() {


    std::unique_ptr<int> a(new int(3));
    std::unique_ptr<int> b = std::move(a);
    std::cout << *b.get() << std::endl;
    std::unique_ptr<int> c = std::make_unique<int>(5);
    std::cout << *c.get() << std::endl;


    std::unique_ptr<House> home(new House(4, 1));
    std::cout << home->window() << " windows and " << home->door() << " doors " << std::endl;

    std::unique_ptr<House> home2 = std::make_unique<House>(3, 1);
    std::cout << home2->window() << " windows and " << home2->door() << " doors " << std::endl;

    std::unique_ptr<House> home3 = std::move(home2);
    std::cout << home3->window() << " windows and " << home3->door() << " doors " << std::endl;

}


#endif //JANCPP_UNIQUE_PTR_HPP
