namespace detail {

template<typename Left, typename... Rest>
struct Sum;

template<typename T>
struct Sum<T> {
  template<typename dummy = void>
  struct Implementation {
    using type = T;
  };
};


template<typename Left, typename Right, typename... Rest >
struct Sum<Left, Right, Rest...> {
  template<bool = AdditionDefined_v<Left, Right>, typename dummy = void>
  struct Implementation {};

  template<typename dummy>
  struct Implementation<true, dummy> :
    Sum<decltype(std::declval<Left>() + std::declval<Right>()),
        Rest...>::template Implementation<> {};
};

}

template<typename First, typename... Rest>
struct Sum : detail::Sum<First, Rest...>::template Implementation<>{};

template<typename First, typename... Rest>
using Sum_t = typename Sum<First, Rest...>::type;
