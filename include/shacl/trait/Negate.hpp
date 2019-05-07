template<typename T>
struct Negate : std::integral_constant<bool, not bool(T::value)> {};

template<typename T>
constexpr const bool Negate_v = Negate<T>::value;
