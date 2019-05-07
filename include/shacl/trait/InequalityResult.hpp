template<typename T, typename U = T, bool = InequalityDefined_v<T, U>>
struct InequalityResult {};

template<typename T, typename U>
struct InequalityResult<T, U, true> {
  using type = detail::InequalityResult_t<T, U>;
};

template<typename T, typename U = T>
using InequalityResult_t = detail::InequalityResult_t<T, U>;
