template<typename T>
struct Negate : std::integral_constant<bool, not bool(T::value)> {};

template<typename T>
static constexpr bool Negate_v = Negate<T>::value;
