template<typename T, typename U = T, bool = LessThanEqualDefined_v<T, U>>
struct LessThanEqualResult {};

template<typename T, typename U>
struct LessThanEqualResult<T, U, true> {
  using type = detail::LessThanEqualResult_t<T, U>;
};

template<typename T, typename U = T>
using LessThanEqualResult_t = detail::LessThanEqualResult_t<T, U>;
