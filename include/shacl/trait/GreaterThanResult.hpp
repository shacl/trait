template<typename T, typename U = T, bool = GreaterThanDefined_v<T, U>>
struct GreaterThanResult {};

template<typename T, typename U>
struct GreaterThanResult<T, U, true> {
  using type = detail::GreaterThanResult_t<T, U>;
};

template<typename T, typename U = T>
using GreaterThanResult_t = detail::GreaterThanResult_t<T, U>;
