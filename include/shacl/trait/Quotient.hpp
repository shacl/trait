namespace detail {

template<typename Left, typename... Rest>
struct Quotient;

template<typename T>
struct Quotient<T> {
  template<typename dummy = void>
  struct Implementation {
    using type = T;
  };
};

template<typename Left, typename Right, typename... Rest >
struct Quotient<Left, Right, Rest...> {
  template<bool = DivisionDefined_v<Left, Right>, typename dummy = void>
  struct Implementation {};

  template<typename dummy>
  struct Implementation<true, dummy> :
    Quotient<decltype(std::declval<Left>() / std::declval<Right>()),
             Rest...>::template Implementation<> {};
};

}

template<typename First, typename... Rest>
struct Quotient :
  detail::Quotient<First, Rest...>::template Implementation<>{};

template<typename... Args>
using DivisionResult = Quotient<Args...>;

template<typename First, typename... Rest>
using Quotient_t = typename Quotient<First, Rest...>::type;

template<typename First, typename... Rest>
using DivisionResult_t = Quotient_t<First, Rest...>;
