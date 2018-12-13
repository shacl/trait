template<typename T, typename = std::ptrdiff_t, typename = void>
struct SubscriptDefined : std::false_type {};

template<typename T, typename Arg>
struct SubscriptDefined<T, Arg,
                        void_t<decltype(std::declval<T>()
                                        [std::declval<Arg>()])>> :
  std::true_type {};

template<typename T, typename Arg = std::ptrdiff_t>
static constexpr bool SubscriptDefined_v = SubscriptDefined<T, Arg>::value;
