namespace detail {
template<typename T>
constexpr const bool IsInteger_v = false;

template<>
constexpr const bool IsInteger_v<short> = true;

template<>
constexpr const bool IsInteger_v<unsigned short> = true;

template<>
constexpr const bool IsInteger_v<int> = true;

template<>
constexpr const bool IsInteger_v<unsigned int> = true;

template<>
constexpr const bool IsInteger_v<long> = true;

template<>
constexpr const bool IsInteger_v<unsigned long> = true;

template<>
constexpr const bool IsInteger_v<long long> = true;

template<>
constexpr const bool IsInteger_v<unsigned long long> = true;
}

template<typename T>
constexpr const bool IsInteger_v = detail::IsInteger_v<std::remove_cv_t<T>>;

template<typename T>
using IsInteger = bool_t<IsInteger_v<T>>;
