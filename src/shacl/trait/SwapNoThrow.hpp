namespace detail {
namespace swap {

template<typename T, typename U>
static constexpr bool nothrow_for =
  noexcept(swap(std::declval<T&>(), std::declval<U&>()));

}
}

template<class T, class U = T, bool = SwapDefined<T, U>::value>
struct SwapNoThrow {};

template<class T, class U>
struct SwapNoThrow<T, U, true> :
  std::integral_constant<bool, detail::swap::nothrow_for<T, U>> {};

template<typename T, typename U = T>
static constexpr bool SwapNoThrow_v = detail::swap::nothrow_for<T, U>;
