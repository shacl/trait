namespace detail {
template<typename Left, typename Right, typename = void>
static constexpr bool LessThanEqualDefined_v = false;

template<typename Left, typename Right>
static constexpr bool LessThanEqualDefined_v
<Left, Right,
 void_t<decltype(std::declval<Left>() <= std::declval<Right>())>> = true;
}

template<typename Left, typename Right = Left>
using LessThanEqualDefined =
  bool_t<detail::LessThanEqualDefined_v<Left, Right>>;

template<typename Left, typename Right = Left>
static constexpr bool LessThanEqualDefined_v =
  detail::LessThanEqualDefined_v<Left, Right>;
