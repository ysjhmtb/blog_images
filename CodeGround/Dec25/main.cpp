
// main.cpp

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>

int main() {

    {
        std::vector<int> container;

        for (int i = 0; i < 10; ++i)
            container.push_back(i);

        auto itr = std::min_element(container.begin(), container.end());
        std::cout << *itr << std::endl;

        itr = std::max_element(container.begin(), container.end());
        std::cout << *itr << std::endl;

        std::cout << std::endl;

        itr = std::find(container.begin(), container.end(), 3);
        container.insert(itr, 128);

        for (auto &e:container) std::cout << e << " ";
        std::cout << std::endl;

        std::sort(container.begin(), container.end());

        for (auto &e:container) std::cout << e << " ";
        std::cout << std::endl;

        std::reverse(container.begin(), container.end());

        for (auto &e:container) std::cout << e << " ";
        std::cout << "\n\n\n" << std::endl;
    }

    {
        std::list<int> container;

        for (int i = 0; i < 10; ++i)
            container.push_back(i);

        auto itr = std::min_element(container.begin(), container.end());
        std::cout << *itr << std::endl;

        itr = std::max_element(container.begin(), container.end());
        std::cout << *itr << std::endl;

        std::cout << std::endl;

        itr = std::find(container.begin(), container.end(), 3);
        container.insert(itr, 128);

        for (auto &e:container) std::cout << e << " ";
        std::cout << std::endl;

        // std::sort(container.begin(), container.end());
        container.sort();

        for (auto &e:container) std::cout << e << " ";
        std::cout << std::endl;

        // std::reverse(container.begin(), container.end());
        container.reverse();

        for (auto &e:container) std::cout << e << " ";
        std::cout << std::endl;
    }

    return 0;
}


