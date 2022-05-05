#include "int.hpp"
#include <iostream>

using namespace std;

Int::Int() : my_int(0) {}
Int::Int(int value)
{
    my_int = value;
}

Int::~Int() {}
Int::Int(const Int& real_copy)
{
    this->my_int = real_copy.my_int;
}

bool operator< (const Int& l, const Int& r) { return l.my_int < r.my_int; }
bool operator> (const Int& l, const Int& r) { return l.my_int > r.my_int; }
bool operator== (const Int& l, const Int& r) { return l.my_int == r.my_int; }
bool operator!= (const Int& l, const Int& r) { return l.my_int != r.my_int; }
Int operator- (const Int& l, const Int& r) { return Int(l.my_int - r.my_int); }

Int Int::operator+ (const Int& r) { return Int(this->my_int + r.my_int); }

Int& Int::operator= (const Int& r)
{
    if (this == &r)
        return *this;
    my_int = r.my_int;
    return *this;
}

void Int::set_my_int(int& value) { my_int = value; }
int Int::get_my_int() const { return my_int; }

void Int::display() { cout << my_int << endl; }
