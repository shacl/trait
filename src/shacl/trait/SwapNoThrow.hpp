template<class T, class U = T, bool = SwapDefined<T, U>::value>
struct SwapNoThrow {};

template<class T, class U>
struct SwapNoThrow<T, U, true>:
  std::integral_constant
  <bool,
   ((decltype(detail::adl::uses_std<T, U>(0))::value
     and detail::adl::is_std_swap_noexcept<T>::value)
    or
    (not decltype(detail::adl::uses_std<T, U>(0))::value
     and detail::adl::is_adl_swap_noexcept<T, U>::value))> {};

template<typename T, typename U = T>
static constexpr bool SwapNoThrow_v = SwapNoThrow<T, U>::value;
