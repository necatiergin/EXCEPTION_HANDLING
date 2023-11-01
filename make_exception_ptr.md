_make_exception_ptr_ bir fonksiyon şablonu.
```
template <class E>
exception_ptr make_exception_ptr (E e) noexcept;
```

Fonksiyon kendisine gönderilen _exception_'dan bir _std::exception_ptr_ nesnesi oluşturarak onu döndürüyor. 
Fonksiyon şablonunun kodunun aşağıdaki gibi olduğu düşünülebilir:

```
template <class E>
exception_ptr make_exception_ptr (E e) noexcept
{
  try {
     throw e;
  } catch(...) {
     return current_exception();
  }
}
```


