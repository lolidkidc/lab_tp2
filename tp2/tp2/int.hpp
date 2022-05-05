#pragma once

class Int
{
private:
    int my_int;
public:
    Int();
    explicit Int(int value);
    Int(const Int& real_copy);
    ~Int();

    Int operator+ (const Int& r);
    Int& operator=(const Int& r);
    void set_my_int(int& value);
    int get_my_int() const;

    friend bool operator< (const Int& l, const Int& r);
    friend bool operator> (const Int& l, const Int& r);
    friend bool operator== (const Int& l, const Int& r);
    friend bool operator!= (const Int& l, const Int& r);
    friend Int operator- (const Int& l, const Int& r);

    void display();
};

