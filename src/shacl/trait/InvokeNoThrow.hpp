namespace detail {

template<typename Fn, typename... Args>
struct InvokeNoThrow {
  template<bool = InvokeDefined_v<Fn, Args...>, typename = void>
  struct Implementation {};

  template<typename T>
  struct Implementation<true, T> :
    std::integral_constant
    <bool,
     noexcept(detail::INVOKE(std::declval<Fn>(),
                             std::declval<Args>()...))>{};
};

}

template<typename Fn, typename... Args>
constexpr const bool InvokeNoThrow_v =
  noexcept(detail::INVOKE(std::declval<Fn>(), std::declval<Args>()...));

template<typename... Args>
using InvokeNoThrow =
  typename detail::InvokeNoThrow<Args...>::template Implementation<>;
