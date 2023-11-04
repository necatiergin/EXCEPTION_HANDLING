- _std::exception_ptr_, C++ Standart Kütüphanesi'nin bir bileşenidir.
- Hataların daha esnek ve daha genelleştirilmiş bir şekilde yönetilmesine yardımcı olmak için _C++11_ Standardı ile dile eklenmiştir.
- _std::exception_ptr_, nesneleri _"polimorfik pointer"_ olarak kullanılan bir sınıftır. 
- Genellikle hata nesnelerini yakalamak ve farklı bir bağlamda yeniden göndermek için diğer _"exception handling"_ araçları ile birlikte kullanılır. 
- Birincil amacı, bir hata nesnesin daha sonra kullanmak üzere saklanmasına veya kodun farklı bir noktasında yeniden gönderilmesine olanak sağlamaktır.

_std::exception_ptr_'nin fayda sağlayabileceği bir senaryo örneği:

Bir hata gönderebilecek bir kodumuz var ve bu hatayı hemen yakalamak ama daha sonra ele almak _(handle)_ istiyoruz.
- hata gönderme potansiyelinde olan kodu bir try bloğu içine alırız. 
- hatayı yakalar ve hata nesnesini bir _std::exception_ptr_ nesnesine dönüştürürüz.

Daha sonra bu _std::exception_ptr_ nesnesini  kodumuzun diğer bölümlerine, farklı bir _thread_'e ya da farklı bir fonkiyona aktarabiliriz.;
- Hata nesnesini aktardığımız yerde daha sonra orijinal hata nesnesini yeniden gönderebiliriz.
- Böyle hata nesnelerini loglayabilir hatta bir kapta _(container)_ tutabiliriz.

_std::exception_ptr_'nin temel faydası, hata nesnelerinin işlenmesini geciktirmemize izin vermesi ve böylece hatanın gönderildiği orijinal bağlamın artık var olmadığı durumlarda bile hata bilgilerini kodun farklı bölümleri arasında taşımak için bir yol sağlamasıdır.

<!--
-->


