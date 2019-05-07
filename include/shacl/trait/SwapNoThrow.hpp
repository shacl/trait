namespace detail {
namespace swap {

template<typename T, typename U>
constexpr const bool nothrow_for =
  noexcept(swap(std::declval<T&>(), std::declval<U&>()));

}
}

template<typename T, typename U = T>
constexpr const bool SwapNoThrow_v = detail::swap::nothrow_for<T, U>;

template<class T, class U = T, bool = SwapDefined<T, U>::value>
struct SwapNoThrow {};

template<class T, class U>
struct SwapNoThrow<T, U, true> : bool_t<SwapNoThrow_v<T, U>> {};
