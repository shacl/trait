template<typename T, bool = DereferenceDefined_v<T>>
struct DereferenceResult {};

template<typename T>
struct DereferenceResult<T, true> {
  using type = decltype(*std::declval<T>());
};

template<typename T>
using DereferenceResult_t = typename DereferenceResult<T>::type;

// API backwards compatability
template<typename T>
using Dereferenced = DereferenceResult<T>;

template<typename T>
using Dereferenced_t = DereferenceResult_t<T>;
