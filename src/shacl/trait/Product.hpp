namespace detail {

template<typename Left, typename... Rest>
struct Product;

template<typename T>
struct Product<T> {
  template<typename dummy = void>
  struct Implementation {
    using type = T;
  };
};

template<typename Left, typename Right, typename... Rest >
struct Product<Left, Right, Rest...> {
  template<bool = MultiplicationDefined_v<Left, Right>, typename dummy = void>
  struct Implementation {};

  template<typename dummy>
  struct Implementation<true, dummy> :
    Product<decltype(std::declval<Left>() * std::declval<Right>()),
            Rest...>::template Implementation<> {};
};

}

template<typename First, typename... Rest>
struct Product :
  detail::Product<First, Rest...>::template Implementation<>{};

template<typename First, typename... Rest>
using Product_t = typename Product<First, Rest...>::type;
