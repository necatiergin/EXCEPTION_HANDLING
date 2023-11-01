class Base {
public:
	virtual void func();
};


class Der : public Base {
public:
	void func()noexcept override; //gecerli
};
