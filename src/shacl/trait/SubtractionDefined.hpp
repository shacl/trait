namespace detail {
template<typename Left, typename Right, typename = void>
static constexpr bool SubtractionDefined_v = false;

template<typename Left, typename Right>
static constexpr bool SubtractionDefined_v
<Left, Right,
 void_t<decltype(std::declval<Left>() - std::declval<Right>())>> = true;
}

template<typename Left, typename Right = Left>
static constexpr bool SubtractionDefined_v =
  detail::SubtractionDefined_v<Left, Right>;

template<typename... Args>
using SubtractionDefined = bool_t<SubtractionDefined_v<Args...>>;
