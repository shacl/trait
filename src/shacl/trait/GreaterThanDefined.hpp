namespace detail {
template<typename Left, typename Right, typename = void>
static constexpr bool GreaterThanDefined_v = false;

template<typename Left, typename Right>
static constexpr bool GreaterThanDefined_v
<Left, Right,
 void_t<decltype(std::declval<Left>() > std::declval<Right>())>> = true;
}

template<typename Left, typename Right = Left, typename = void>
using GreaterThanDefined = bool_t<detail::GreaterThanDefined_v<Left, Right>>;

template<typename Left, typename Right = Left>
static constexpr bool GreaterThanDefined_v =
  detail::GreaterThanDefined_v<Left, Right>;

