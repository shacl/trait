namespace detail {
template<typename T>
static constexpr bool IsInteger_v = false;

template<>
static constexpr bool IsInteger_v<short> = true;

template<>
static constexpr bool IsInteger_v<unsigned short> = true;

template<>
static constexpr bool IsInteger_v<int> = true;

template<>
static constexpr bool IsInteger_v<unsigned int> = true;

template<>
static constexpr bool IsInteger_v<long> = true;

template<>
static constexpr bool IsInteger_v<unsigned long> = true;

template<>
static constexpr bool IsInteger_v<long long> = true;

template<>
static constexpr bool IsInteger_v<unsigned long long> = true;
}

template<typename T>
static constexpr bool IsInteger_v = detail::IsInteger_v<std::remove_cv_t<T>>;

template<typename T>
using IsInteger = bool_t<IsInteger_v<T>>;
