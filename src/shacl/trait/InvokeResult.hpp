#if __cplusplus < 201703L

namespace detail {

template<typename F, typename... Args>
struct InvokeResult {
  template<typename G = F, bool = InvokeDefined_v<G, Args...>>
  struct Implementation {};

  template<typename G>
  struct Implementation<G, true> {
    using type = decltype(INVOKE(std::declval<G>(), std::declval<Args>()...));
  };
};

}

template<typename F, typename... Args>
using InvokeResult =
  typename detail::InvokeResult<F, Args...>::template Implementation<>;

#else

template<typename F, typename... Args>
using InvokeResult = std::invoke_result<F, Args...>;

#endif

template<typename F, typename... Args>
using InvokeResult_t = typename InvokeResult<F, Args...>::type;