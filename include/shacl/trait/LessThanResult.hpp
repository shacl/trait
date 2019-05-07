template<typename T, typename U = T, bool = LessThanDefined_v<T, U>>
struct LessThanResult {};

template<typename T, typename U>
struct LessThanResult<T, U, true> {
  using type = detail::LessThanResult_t<T, U>;
};

template<typename T, typename U = T>
using LessThanResult_t = detail::LessThanResult_t<T, U>;
