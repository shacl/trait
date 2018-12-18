namespace detail {

template<typename T, typename IndexType>
using SubscriptResult_t =
  decltype(std::declval<T>()[std::declval<IndexType>()]);

template<typename T, typename IndexType, typename = void>
static constexpr bool SubscriptDefined_v = false;

template<typename T, typename IndexType>
static constexpr bool SubscriptDefined_v
<T, IndexType, void_t<SubscriptResult_t<T, IndexType>>> = true;

}

template<typename T, typename IndexType = std::ptrdiff_t>
static constexpr bool SubscriptDefined_v =
  detail::SubscriptDefined_v<T, IndexType>;

template<typename... Args>
using SubscriptDefined = bool_t<SubscriptDefined_v<Args...>>;
