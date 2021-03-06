namespace detail {
template<typename Left, typename Right, typename = void>
constexpr const bool MultiplicationDefined_v = false;

template<typename Left, typename Right>
constexpr const bool MultiplicationDefined_v
<Left, Right,
 void_t<decltype(std::declval<Left>() * std::declval<Right>())>> = true;
}

template<typename Left, typename Right = Left>
using MultiplicationDefined =
  bool_t<detail::MultiplicationDefined_v<Left, Right>>;

template<typename Left, typename Right = Left>
constexpr const bool MultiplicationDefined_v =
  detail::MultiplicationDefined_v<Left, Right>;
