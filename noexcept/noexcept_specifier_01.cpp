void f1() noexcept;             // f1 exception göndermeyecek
void f2() noexcept(true);       // f2 exception göndermeyecek (f1 bildirimi ile aynı anlamda)
void f3();                      // f3 exception gönderebilir
void f4() noexcept(false);      // f4 exception gönderebilir (f3 bildirimi ile aynı anlamda)
