#### Hangi durumlarda std::terminate işlevi çağrılır?

+ Bir _exception_ gönderildiğinde ve gönderilen _exception_ yakalanamadığında _(uncaught exception)_.
+ _noexcept_ olarak bildirilen bir fonksiyondan bir _exception_ gönderildiğinde. _(noexcept violation)_
+ Gönderilen _exception_ kopyalama semantiği ile yakalandığında ve gönderilen _exception_ nesnesinin _copy ctor_'ı _exception throw_ ettiğinde.
+ bir _rethrow statement_, yakalanmış bir _exception_ söz konusu değilken yürütüldüğünde. 
+ Bir _std::thread_ nesnesi _joinable_ durumda iken _destructor_'ı çağrıldığında. 
