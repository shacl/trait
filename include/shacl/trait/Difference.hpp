namespace detail {
template<typename Left, typename... Rest>
struct Difference;

template<typename T>
struct Difference<T> {
  template<typename dummy = void>
  struct Implementation {
    using type = T;
  };
};

template<typename Left, typename Right, typename... Rest >
struct Difference<Left, Right, Rest... > {
  template<bool = SubtractionDefined_v<Left, Right>, typename dummy = void>
  struct Implementation {};

  template<typename dummy>
  struct Implementation<true, dummy> :
    Difference<decltype(std::declval<Left>() - std::declval<Right>()),
               Rest...>::template Implementation<> {};
};
}

template<typename... Args>
using Difference = typename detail::Difference<Args...>::template Implementation<>;

template<typename... Args>
using SubtractionResult = Difference<Args...>;

template<typename... Args>
using Difference_t = typename Difference<Args...>::type;

template<typename... Args>
using SubtractionResult_t = Difference_t<Args...>;
