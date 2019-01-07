namespace detail {
template<typename Left, typename Right>
using GreaterThanResult_t =
  decltype(std::declval<Left>() > std::declval<Right>());

template<typename Left, typename Right, typename = void>
constexpr const bool GreaterThanDefined_v = false;

template<typename Left, typename Right>
constexpr const bool GreaterThanDefined_v
<Left, Right, void_t<GreaterThanResult_t<Left, Right>>> = true;
}

template<typename Left, typename Right = Left>
using GreaterThanDefined = bool_t<detail::GreaterThanDefined_v<Left, Right>>;

template<typename Left, typename Right = Left>
constexpr const bool GreaterThanDefined_v =
  detail::GreaterThanDefined_v<Left, Right>;

