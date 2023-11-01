class Base {
public:
	virtual void func()noexcept;
};


class Der : public Base {
public:
	//void func()override; //gecersiz
	void func()noexcept override; //gecerli
};
