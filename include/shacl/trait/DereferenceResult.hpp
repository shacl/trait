template<typename T, bool = DereferenceDefined_v<T>>
struct DereferenceResult {};

template<typename T>
struct DereferenceResult<T, true> {
  using type = detail::DereferenceResult_t<T>;
};

template<typename T>
using DereferenceResult_t = detail::DereferenceResult_t<T>;

// API backwards compatability
template<typename T>
using Dereferenced = DereferenceResult<T>;

template<typename T>
using Dereferenced_t = DereferenceResult_t<T>;
