#include <iostream>

using namespace std;

class Cents {
private:
    int m_cents;

public:
    Cents(int cents = 0) { m_cents = cents; }

    int getCents() const { return m_cents; }

    friend Cents operator+(const Cents &c1, const Cents &c2) {
        return Cents(c1.getCents() + c2.getCents());
    }


};


int main() {

    Cents cents1(6);
    Cents cents2(8);

    cout << (cents1 + cents2 + Cents(6)).getCents() << endl;


    return 0;
}



/*


class Something
{
public:
    int m_value;

    Something(): m_value(0) { }

    void setValue(int value) { m_value = value; }
    int getValue() { return m_value ; }
};

int main()
{
    const Something something; // calls default constructor

    something.m_value = 5; // compiler error: violates const
    something.setValue(5); // compiler error: violates const

    return 0;
}




Const member functions

Now, consider the following line of code:


  std::cout << something.getValue();


Perhaps surprisingly, this will also cause a compile error, even though getValue() doesn’t do anything to change a member variable! It turns out that const class objects can only explicitly call const member functions, and getValue() has not been marked as a const member function.

A const member function is a member function that guarantees it will not modify the object or call any non-const member functions (as they may modify the object).

To make getValue() a const member function, we simply append the const keyword to the function prototype, after the parameter list, but before the function body:




class Something
{
public:
    int m_value;

    Something() { m_value= 0; }

    void resetValue() { m_value = 0; }
    void setValue(int value) { m_value = value; }

    int getValue() const { return m_value; }
    // note addition of const keyword after parameter list, but before function body
};




https://www.learncpp.com/cpp-tutorial/810-const-class-objects-and-member-functions/

 *
 */




/*

 Friend functions

A friend function is a function that can access the private members of a class
 as though it were a member of that class. In all other regards, the friend function is just like a normal function.
 A friend function may be either a normal function, or a member function of another class.
 To declare a friend function, simply use the friend keyword in front of the prototype of the function
 you wish to be a friend of the class. It does not matter whether you declare the friend function
 in the private or public section of the class.

Here’s an example of using a friend function:



 class Accumulator
{
private:
    int m_value;
public:
    Accumulator() { m_value = 0; }
    void add(int value) { m_value += value; }

    // Make the reset() function a friend of this class
    friend void reset(Accumulator &accumulator);
};

// reset() is now a friend of the Accumulator class
void reset(Accumulator &accumulator)
{
    // And can access the private data of Accumulator objects
    accumulator.m_value = 0;
}

int main()
{
    Accumulator acc;
    acc.add(5); // add 5 to the accumulator
    reset(acc); // reset the accumulator to 0

    return 0;
}

 https://www.learncpp.com/cpp-tutorial/813-friend-functions-and-classes/
 */