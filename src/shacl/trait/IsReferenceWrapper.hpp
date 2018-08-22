template<typename T>
struct IsReferenceWrapper : std::false_type {};

template<typename U>
struct IsReferenceWrapper<std::reference_wrapper<U>> : std::true_type {};

template<typename T>
static constexpr bool IsReferenceWrapper_v = IsReferenceWrapper<T>::value;
