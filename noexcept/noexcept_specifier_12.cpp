//  from N.Jossutis book

class Base {
public:
    virtual void func() noexcept(sizeof(int) < 8); // might throw if sizeof(int) >= 8
};

class Derived : public Base {
public:
    void func() noexcept(sizeof(int) < 4) override; // might throw if sizeof(int) >= 4
};
