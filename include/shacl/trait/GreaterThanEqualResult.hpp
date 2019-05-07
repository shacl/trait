template<typename T, typename U = T, bool = GreaterThanEqualDefined_v<T, U>>
struct GreaterThanEqualResult {};

template<typename T, typename U>
struct GreaterThanEqualResult<T, U, true> {
  using type = detail::GreaterThanEqualResult_t<T, U>;
};

template<typename T, typename U = T>
using GreaterThanEqualResult_t = detail::GreaterThanEqualResult_t<T, U>;
