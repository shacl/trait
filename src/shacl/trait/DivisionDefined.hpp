namespace detail {
template<typename Left, typename Right, typename = void>
static constexpr bool DivisionDefined_v = false;

template<typename Left, typename Right>
static constexpr bool DivisionDefined_v
<Left, Right,
 void_t<decltype(std::declval<Left>() / std::declval<Right>())>> = true;
}

template<typename Left, typename Right = Left>
using DivisionDefined = bool_t<detail::DivisionDefined_v<Left, Right>>;

template<typename Left, typename Right = Left>
static constexpr bool DivisionDefined_v =
  detail::DivisionDefined_v<Left, Right>;
