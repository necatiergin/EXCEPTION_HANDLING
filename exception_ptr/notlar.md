- _std::exception_ptr_, C++ Standart Kütüphanesi'nin bir bileşenidir.
- Hataların daha esnek ve daha genelleştirilmiş bir şekilde yönetilmesine yardımcı olmak için _C++11_ Standardı ile dile eklenmiştir.
- _std::exception_ptr_, nesneleri _"polimorfik pointer"_ olarak kullanılan bir sınıftır. 
- Genellikle hata nesnelerini yakalamak ve farklı bir bağlamda yeniden göndermek için diğer _"exception handling"_ araçları ile birlikte kullanılır. 
- Birincil amacı, bir hata nesnesin daha sonra kullanmak üzere saklanmasına veya kodun farklı bir noktasında yeniden gönderilmesine olanak sağlamaktır.

<!--




İşte std::exception_ptr'nin yararlı olabileceği tipik bir senaryo:

Bir istisna fırlatabilecek bir kodunuz var ve bu istisnayı hemen ele almadan yakalamak istiyorsunuz.

Potansiyel olarak fırlatılan kodu bir try-catch bloğuna sarar, istisnayı yakalar ve bir std::exception_ptr'ye dönüştürürsünüz.

Daha sonra bu std::exception_ptr'yi kodunuzun diğer bölümlerine, belki de farklı bir iş parçacığına veya farklı bir işleve aktarabilirsiniz; burada daha sonra orijinal istisnayı yeniden atabilir veya istisnayı günlüğe kaydetmek veya istisna türüne göre bir karar vermek gibi başka eylemler gerçekleştirebilirsiniz.

std::exception_ptr'nin temel faydası, istisnaların işlenmesini geciktirmenize izin vermesi ve istisnanın atıldığı orijinal bağlamın artık mevcut olmadığı durumlarda bile istisna bilgilerini kodunuzun farklı bölümleri arasında taşımak için bir yol sağlamasıdır.
-->


