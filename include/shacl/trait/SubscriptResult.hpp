template<typename T, typename IndexType = std::ptrdiff_t,
         bool = SubscriptDefined_v<T, IndexType>>
struct SubscriptResult {};

template<typename T, typename IndexType>
struct SubscriptResult<T, IndexType, true> {
  using type = detail::SubscriptResult_t<T, IndexType>;
};

template<typename T, typename IndexType = std::ptrdiff_t>
using SubscriptResult_t = detail::SubscriptResult_t<T, IndexType>;
