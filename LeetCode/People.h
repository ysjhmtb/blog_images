//
// Created by yun on 2021/02/26.
//

#ifndef LEETCODE_PEOPLE_H
#define LEETCODE_PEOPLE_H

class People {
private:
    int age;
    char *name;
    double height;

public:
    void set_People(int _age, char *_name, double _height);

    void show_People();

    People() {
        char *t = "hello";
        std::cout << "생성자" << std::endl;
        age = 100;
        name = "hello";
        height = 180;
    }

    People(int _age, char *_name, double _height) {
        std::cout << "생성자, 인자 3개" << std::endl;
        age = _age;
        name = _name;
        height = _height;
    }
};

void People::set_People(int _age, char *_name, double _height) {
    age = _age;
    name = _name;
    height = _height;
}

void People::show_People() {
    std::cout << "나이 : " << age << std::endl;
    std::cout << "이름 : " << name << std::endl;
    std::cout << "키 : " << height << std::endl;

}


#endif //LEETCODE_PEOPLE_H
