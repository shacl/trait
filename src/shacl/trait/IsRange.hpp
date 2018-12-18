namespace detail {
template<typename T, typename = void>
static constexpr bool IsRange_v = false;

template<typename T>
static constexpr bool IsRange_v
<T, void_t<decltype(std::begin(std::declval<T>())),
           decltype(std::end(std::declval<T>()))>> = true;
}

template<typename T>
static constexpr bool IsRange_v = detail::IsRange_v<T>;

template<typename T>
using IsRange = bool_t<IsRange_v<T>>;
