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

template<typename... Args>
using Sum = typename detail::Sum<Args...>::template Implementation<>;

template<typename... Args>
using AdditionResult = Sum<Args...>;

template<typename... Args>
using Sum_t = typename Sum<Args...>::type;

template<typename... Args>
using AdditionResult_t = Sum_t<Args...>;
