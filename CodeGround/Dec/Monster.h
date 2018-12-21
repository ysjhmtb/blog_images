

#ifndef DEC_MONSTER_H
#define DEC_MONSTER_H

#include <string>
#include "Position2D.h"

class Monster {

private:
    std::string m_name;
    Position2D m_location;

//    int m_x;
//    int m_y;

public:
    Monster(const std::string name_in, const Position2D &pos_in)
            : m_name(name_in), m_location(pos_in) {}

    void moveTo(const Position2D &pos_target) {
        m_location.set(pos_target);

//        m_x = x_target;
//        m_y = y_target;
    }

    // 반환형이 std::ostream & 이 아니라 std::ostream 이면 다음과 같은 에러 발생.
    //
    // error: call to deleted constructor of 'std::ostream' (aka 'basic_ostream<char>')
    //        return out;
    //
    friend std::ostream &operator<<(std::ostream &out, Monster &monster) {
        out << monster.m_name << "  " << monster.m_location << std::endl;
        return out;
    }


};


#endif //DEC_MONSTER_H
