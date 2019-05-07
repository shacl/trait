namespace detail {
template<typename T, typename = void>
constexpr const bool HasType_v = false;

template<typename T>
constexpr const bool HasType_v<T, void_t<typename T::type>> = true;
}

template<typename T>
constexpr const bool HasType_v = detail::HasType_v<T>;

template<typename T>
using HasType = bool_t<HasType_v<T>>;
