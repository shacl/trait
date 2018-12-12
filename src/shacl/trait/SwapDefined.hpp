namespace detail {
namespace adl {

struct swap_tag {};

template<typename T> swap_tag swap(T&, T&);
template<typename T, std::size_t N> swap_tag swap(T (&a)[N], T (&b)[N]);

template<typename, typename> std::false_type can_swap(...) noexcept(false);
template<typename T, typename U,
         typename = decltype(swap(std::declval<T&>(), std::declval<U&>()))>
std::true_type can_swap(int)
  noexcept(noexcept(swap(std::declval<T&>(), std::declval<U&>())));

template<typename, typename> std::false_type uses_std(...);
template<typename T, typename U>
std::is_same<decltype(swap(std::declval<T&>(), std::declval<U&>())), swap_tag>
uses_std(int);

template<class T>
struct is_std_swap_noexcept :
  std::integral_constant
  <bool,
   std::is_nothrow_move_constructible<T>::value
   and std::is_nothrow_move_assignable<T>::value> {};

template<class T, std::size_t N>
struct is_std_swap_noexcept<T[N]> : is_std_swap_noexcept<T> {};

template<class T, class U>
struct is_adl_swap_noexcept :
  std::integral_constant<bool, noexcept(can_swap<T, U>(0))> {};

}
}

template<class T, class U = T>
struct SwapDefined :
  std::integral_constant
  <bool,
   decltype(detail::adl::can_swap<T, U>(0))::value
   and (not decltype(detail::adl::uses_std<T, U>(0))::value
        or (std::is_move_assignable<T>::value
            and std::is_move_constructible<T>::value))> {};

template<class T, std::size_t N>
struct SwapDefined<T[N], T[N]> :
  std::integral_constant
  <bool,
   decltype(detail::adl::can_swap<T[N], T[N]>(0))::value
   and (not decltype(detail::adl::uses_std<T[N], T[N]>(0))::value
        or SwapDefined<T, T>::value)> {};

template<typename T, typename U = T>
static constexpr bool SwapDefined_v = SwapDefined<T, U>::value;
