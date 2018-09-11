template<typename T, bool = DereferenceDefined_v<T>>
struct Dereferenced {};

template<typename T>
struct Dereferenced<T, true> {
  using type = decltype(*std::declval<T>());
};

template<typename T>
using Dereferenced_t = typename Dereferenced<T>::type;
