namespace detail {
template<typename Left, typename Right = Left, typename = void>
static constexpr bool EqualityDefined_v = false;

template<typename Left, typename Right>
static constexpr bool EqualityDefined_v
<Left, Right, void_t<decltype(std::declval<Left>()
                              == std::declval<Right>())>> = true;
}

template<typename Left, typename Right>
using EqualityDefined = bool_t<detail::EqualityDefined_v<Left, Right>>;

template<typename Left, typename Right = Left>
static constexpr bool EqualityDefined_v =
  detail::EqualityDefined_v<Left, Right>;
