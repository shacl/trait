namespace detail {
template<typename T>
using DereferenceResult_t = decltype(*std::declval<T>());

template<typename T, typename = void>
static constexpr bool DereferenceDefined_v = false;

template<typename T>
static constexpr bool
DereferenceDefined_v<T, void_t<DereferenceResult_t<T>>> = true;
}

template<typename... Args>
using DereferenceDefined = bool_t<detail::DereferenceDefined_v<Args...>>;

template<typename T>
static constexpr bool DereferenceDefined_v = detail::DereferenceDefined_v<T>;
