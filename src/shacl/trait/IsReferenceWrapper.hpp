template<typename T>
constexpr const bool IsReferenceWrapper_v = false;

template<typename T>
constexpr const bool IsReferenceWrapper_v<std::reference_wrapper<T>> = true;

template<typename T>
using IsReferenceWrapper = bool_t<IsReferenceWrapper_v<T>>;


