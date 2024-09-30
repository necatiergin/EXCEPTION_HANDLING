#include <iostream>

class ExBase {
public:
    virtual ~ExBase() = default;
    virtual void raise()
    {
        throw *this;
    }

    virtual void raise()const
    {
        throw* this;
    }
};

class ExDer1 : public ExBase { 
public:
    void raise()override
    {
        throw *this;
    }

    void raise()const override
    {
        throw* this;
    }
};

class ExDer2 : public ExBase {
public:
    void raise()override
    {
        throw* this;
    }

    void raise()const override
    {
        throw* this;
    }
};

void f(const ExBase& ex)
{
    // other code
    ex.raise();
}

int main()
{
    ExDer1 ed;
    try {
        f(ed);
    }
    catch (ExDer1&) {
        std::cout << "ExDer1 exception caught\n";
    }
    catch (ExDer2&) {
        std::cout << "ExDer2 exception caught\n";
    }
    catch (...) {
        std::cout << "other exception caught\n";
    }
}
