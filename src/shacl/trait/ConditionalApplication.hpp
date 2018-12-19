namespace detail {

template<bool>
struct Conditional {
  template<template<typename...> class T1,
           template<typename...> class T2,
           typename... Args >
  using application = T2<Args...>;
};

template<>
struct Conditional<true> {
  template<template<typename...> class T1,
           template<typename...> class T2,
           typename... Args >
  using application = T1<Args...>;
};

}

template<bool b,
         template<typename...> class T1,
         template<typename...> class T2,
         typename... Args>
struct ConditionalApplication {
  using type =
    typename detail::Conditional<b>::template application<T1, T2, Args...>;
};

template<bool b,
         template<typename...> class T1,
         template<typename...> class T2,
         typename... Args>
using ConditionalApplication_t =
  typename detail::Conditional<b>::template application<T1, T2, Args...>;
