template<typename T, typename U = T, bool = EqualityDefined_v<T, U>>
struct EqualityResult {};

template<typename T, typename U>
struct EqualityResult<T, U, true> {
  using type = detail::EqualityResult_t<T, U>;
};

template<typename T, typename U = T>
using EqualityResult_t = detail::EqualityResult_t<T, U>;
