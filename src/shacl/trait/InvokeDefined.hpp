#if __cplusplus < 201703L

namespace detail {

template<typename F, typename... Args>
struct InvokeDefined {
  template<typename G = F, typename = void>
  struct Implementation : std::false_type {};

  template<typename G>
  struct Implementation<G, void_t<decltype(INVOKE(std::declval<G>(),
                                                  std::declval<Args>()...))>>
    : std::true_type {};
};

}

template<typename F, typename... Args>
using InvokeDefined =
  typename detail::InvokeDefined<F, Args...>::template Implementation<>;

#else

template<typename F, typename... Args>
using InvokeDefined = std::is_invocable<F, Args...>;

#endif

template<typename F, typename... Args>
static constexpr bool InvokeDefined_v = InvokeDefined<F, Args...>::value;

