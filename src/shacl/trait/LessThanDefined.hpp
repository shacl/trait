namespace detail {
template<typename Left, typename Right = Left, typename = void>
static constexpr bool LessThanDefined_v = false;

template<typename Left, typename Right>
static constexpr bool LessThanDefined_v
<Left, Right,
 void_t<decltype(std::declval<Left>() < std::declval<Right>())>> = true;

}

template<typename Left, typename Right = Left>
using LessThanDefined = bool_t<detail::LessThanDefined_v<Left, Right>>;

template<typename Left, typename Right = Left>
static constexpr bool LessThanDefined_v =
  detail::LessThanDefined_v<Left, Right>;
