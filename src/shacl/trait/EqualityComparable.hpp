template<typename... Args>
constexpr const bool EqualityComparable_v =
  EqualityDefined_v<Args...> and InequalityDefined_v<Args...>;

template<typename... Args>
using EqualityComparable = bool_t<EqualityComparable_v<Args...>>;
