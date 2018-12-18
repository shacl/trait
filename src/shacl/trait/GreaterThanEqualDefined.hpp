namespace detail {
template<typename Left, typename Right, typename = void>
static constexpr bool GreaterThanEqualDefined_v = false;

template<typename Left, typename Right>
static constexpr bool GreaterThanEqualDefined_v
<Left, Right,
 void_t<decltype(std::declval<Left>() >= std::declval<Right>())>> = true;
}

template<typename Left, typename Right = Left>
using GreaterThanEqualDefined =
  bool_t<detail::GreaterThanEqualDefined_v<Left, Right>>;

template<typename Left, typename Right = Left>
static constexpr bool GreaterThanEqualDefined_v =
  detail::GreaterThanEqualDefined_v<Left, Right>;
