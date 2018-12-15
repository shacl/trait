template<typename T, typename IndexType = std::ptrdiff_t, typename = void>
struct SubscriptDefined : std::false_type {};

namespace detail {

template<typename T, typename IndexType>
using SubscriptResult = decltype(std::declval<T>()[std::declval<IndexType>()]);

}

template<typename T, typename IndexType>
struct SubscriptDefined
<T, IndexType, void_t<detail::SubscriptResult<T, IndexType>>> :
  std::true_type {};

template<typename T, typename IndexType = std::ptrdiff_t>
static constexpr bool SubscriptDefined_v = SubscriptDefined<T, IndexType>::value;
