namespace detail {
template<typename Left, typename Right, typename = void>
static constexpr bool AdditionDefined_v = false;

template<typename Left, typename Right>
static constexpr bool AdditionDefined_v
<Left, Right,
 void_t<decltype(std::declval<Left>() + std::declval<Right>())>> = true;
}

template<typename Left, typename Right = Left>
static constexpr bool AdditionDefined_v =
  detail::AdditionDefined_v<Left, Right>;

template<typename... Args>
using AdditionDefined = bool_t<AdditionDefined_v<Args...>>;
