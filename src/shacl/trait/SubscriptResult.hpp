template<typename T, typename Arg = std::ptrdiff_t,
         bool = SubscriptDefined_v<T, Arg>>
struct SubscriptResult {};

template<typename T, typename Arg>
struct SubscriptResult<T, Arg, true> {
  using type = decltype(std::declval<T>()[std::declval<Arg>()]);
};

template<typename T, typename Arg = std::ptrdiff_t>
using SubscriptResult_t =
  typename SubscriptResult<T, Arg>::type;
