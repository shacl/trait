namespace detail {
template<typename Left, typename Right>
using LessThanEqualResult_t =
  decltype(std::declval<Left>() <= std::declval<Right>());

template<typename Left, typename Right, typename = void>
constexpr const bool LessThanEqualDefined_v = false;

template<typename Left, typename Right>
constexpr const bool LessThanEqualDefined_v
<Left, Right, void_t<LessThanEqualResult_t<Left, Right>>> = true;
}

template<typename Left, typename Right = Left>
using LessThanEqualDefined =
  bool_t<detail::LessThanEqualDefined_v<Left, Right>>;

template<typename Left, typename Right = Left>
constexpr const bool LessThanEqualDefined_v =
  detail::LessThanEqualDefined_v<Left, Right>;
