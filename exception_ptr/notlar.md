- _std::exception_ptr_, C++ Standart Kütüphanesi'nin bir bileşenidir.
- Hataların daha esnek ve daha genelleştirilmiş bir şekilde yönetilmesine yardımcı olmak için _C++11_ Standardı ile dile eklenmiştir.

<!--


std::exception_ptr, "polimorfik istisna işaretçisini" temsil eden bir sınıftır. Genellikle istisnaları yakalamak ve farklı bir bağlamda yeniden atmak için diğer istisna işleme mekanizmalarıyla birlikte kullanılır. Birincil amacı, bir istisnayı daha sonra incelemek üzere saklamanıza veya kodunuzun farklı bir noktasında yeniden atmanıza olanak sağlamaktır.

İşte std::exception_ptr'nin yararlı olabileceği tipik bir senaryo:

Bir istisna fırlatabilecek bir kodunuz var ve bu istisnayı hemen ele almadan yakalamak istiyorsunuz.

Potansiyel olarak fırlatılan kodu bir try-catch bloğuna sarar, istisnayı yakalar ve bir std::exception_ptr'ye dönüştürürsünüz.

Daha sonra bu std::exception_ptr'yi kodunuzun diğer bölümlerine, belki de farklı bir iş parçacığına veya farklı bir işleve aktarabilirsiniz; burada daha sonra orijinal istisnayı yeniden atabilir veya istisnayı günlüğe kaydetmek veya istisna türüne göre bir karar vermek gibi başka eylemler gerçekleştirebilirsiniz.

std::exception_ptr'nin temel faydası, istisnaların işlenmesini geciktirmenize izin vermesi ve istisnanın atıldığı orijinal bağlamın artık mevcut olmadığı durumlarda bile istisna bilgilerini kodunuzun farklı bölümleri arasında taşımak için bir yol sağlamasıdır.
-->


