template<typename...>
struct Disjunction : std::false_type {};

template<typename T, typename... Ts>
struct Disjunction<T, Ts...> :
  std::conditional_t<bool(T::value), T, Disjunction<Ts...>> {};

template<typename... Ts>
constexpr const bool Disjunction_v = Disjunction<Ts...>::value;
