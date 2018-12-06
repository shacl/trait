template<typename...>
struct Conjunction : std::true_type {};

template<typename T, typename... Ts>
struct Conjunction<T, Ts...> :
  std::conditional_t<bool(T::value), Conjunction<Ts...>, T> {};

template<typename... Ts>
static constexpr bool Conjunction_v = Conjunction<Ts...>::value;
