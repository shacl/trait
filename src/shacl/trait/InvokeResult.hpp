#if __cplusplus < 201703L

namespace detail {

template<typename F, typename... Args>
struct InvokeResult {
  template<typename G = F, bool = InvokeDefined_v<G, Args...>>
  struct Implementation {};

  template<typename G>
  struct Implementation<G, true> {
    using type = InvokeResult_t<G, Args...>;
  };
};

}

template<typename... Args>
using InvokeResult =
  typename detail::InvokeResult<Args...>::template Implementation<>;

template<typename... Args>
using InvokeResult_t = detail::InvokeResult_t<Args...>;

#else

template<typename... Args>
using InvokeResult = std::invoke_result<Args...>;

template<typename... Args>
using InvokeResult_t = typename std::invoke_result<Args...>::type;

#endif
