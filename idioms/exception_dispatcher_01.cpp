//exception dispatcher
//önemli bir exception idiyomu

class NecException {

};


class ErgException {

};

class CSDException {

};



void handle_exception()
{
	try {
		throw;
	}
	catch (NecException& e) {
		
	}
	catch (ErgException& e) {
		
	}
	catch (CSDException & e) {

	};
}


void func()
{
	try {
		// hata 
	}
	catch (...) {
		handle_exception();
	}
}
