class Base {
public:
	virtual void foo()noexcept;
	virtual void bar();
};

class Der : public Base {
public:
	//void foo()override; //invalid
	void foo()noexcept override; //valid
	void bar()noexcept override; //valid
};
