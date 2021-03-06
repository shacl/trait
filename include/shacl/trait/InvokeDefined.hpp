#if __cplusplus < 201703L

namespace detail {

template<typename... Args>
using InvokeResult_t =
  decltype(INVOKE(std::declval<Args>()...));

template<typename F, typename... Args>
struct InvokeDefined {
  template<typename G = F, typename = void>
  struct Implementation_t : std::false_type {};

  template<typename G>
  struct Implementation_t
  <G, void_t<InvokeResult_t<G, Args...>>> : std::true_type {};

  template<typename G = F>
  static constexpr bool Implementation = Implementation_t<G>::value;
};

}

template<typename... Args>
constexpr const bool InvokeDefined_v =
  detail::InvokeDefined<Args...>::template Implementation<>;

template<typename... Args>
using InvokeDefined = bool_t<InvokeDefined_v<Args...>>;

#else

template<typename... Args>
using InvokeDefined = std::is_invocable<Args...>;

template<typename... Args>
constexpr const bool InvokeDefined_v = std::is_invocable_v<Args...>;

#endif

