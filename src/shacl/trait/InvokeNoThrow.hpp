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
using InvokeNoThrow =
  typename detail::InvokeNoThrow<Fn, Args...>::template Implementation<>;

template<typename Fn, typename... Args>
static constexpr bool InvokeNoThrow_v = InvokeNoThrow<Fn, Args...>::value;
