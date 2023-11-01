


<!--
- std::nested_exception, iç içe geçmiş istisnaların yönetimini kolaylaştırmak için C++11'de tanıtılan C++ Standart Kütüphanesi'nin bir parçasıdır. 
- İstisnaları saklamanıza ve yeniden atmanıza olanak tanıyan std::exception_ptr ile yakından ilişkilidir. std::nested_exception, bir istisnanın diğerinin sonucu olduğu durumlarla başa çıkmayı kolaylaştıran ve bir istisnalar hiyerarşisi oluşturan bir mekanizmadır.

- C++ programlarında, bir istisnanın başka bir istisnayı tetikleyerek bir istisna zinciri oluşturması mümkündür. 
- std::nested_exception, bu istisna hiyerarşisini daha düzenli ve bilgilendirici bir şekilde yakalamaya ve ele almaya yardımcı olmak için tasarlanmıştır.

 -İşte std::nested_exception'ın nasıl çalıştığı:

 Bir istisna yakalandığında, iç içe geçmiş istisnaları da içeren o anda etkin olan istisna bağlamını saklamak için std::nested_exception kullanabilirsiniz. Bu, std::make_exception_ptr(std::current_exception()) çağrısı aracılığıyla yapılır.

Daha sonra, geçerli istisna bağlamını temsil eden std::exception_ptr'yi (iç içe istisnalar içerebilir) kodunuzun başka bir bölümüne aktarabilirsiniz.

Kodunuzun bu diğer bölümünde, iç içe geçmiş tüm istisnalar da dahil olmak üzere istisnayı yeniden atmak veya ek işlem, günlük kaydı veya inceleme gerçekleştirmek için std::rethrow_exception kullanabilirsiniz.

Bu, yalnızca anlık istisnayı değil, aynı zamanda mevcut istisnanın bağlamına katkıda bulunmuş olabilecek iç içe geçmiş istisnaları da yakalamanıza ve yaymanıza olanak tanır. Orijinal bağlamı korumak için bir yol sağlar, bu da hata ayıklama ve geliştiricilere anlamlı bilgiler sağlama açısından çok değerli olabilir.

İşte std::nested_exception kullanımına basit bir örnek:

std::nested_exception is a part of the C++ Standard Library introduced in C++11 to facilitate the management of nested exceptions. It is closely related to std::exception_ptr, which allows you to store and rethrow exceptions. std::nested_exception is a mechanism that makes it easier to deal with situations where one exception is the consequence of another, forming a hierarchy of exceptions.

In C++ programs, it's possible for one exception to trigger another exception, creating a chain of exceptions. std::nested_exception is designed to help in capturing and dealing with this exception hierarchy in a more organized and informative way.

Here's how std::nested_exception works:

When an exception is caught, you can use std::nested_exception to store the currently active exception context, which includes any nested exceptions. This is done through a call to std::make_exception_ptr(std::current_exception()).

You can then pass the std::exception_ptr representing the current exception context (which may include nested exceptions) to another part of your code.

In that other part of your code, you can use std::rethrow_exception to rethrow the exception, including all the nested exceptions, or to perform additional handling, logging, or examination.

This allows you to capture and propagate not just the immediate exception but also any nested exceptions that might have contributed to the current exception's context. It provides a way to preserve the original context, which can be very valuable for debugging and providing meaningful information to developers.

Here's a simple example of using std::nested_exception:

-->
