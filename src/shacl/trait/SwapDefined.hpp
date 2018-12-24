namespace detail {
namespace swap {

/**
 * We define the signature for a surrogate function for std::swap, which accepts
 * the same arguments, but (unlike std::swap) is constrained via SFINAE. This
 * swap definition will be found by namespace lookup by the `defined_for`
 * template variable (defined later in this namespace) should argument-dependent
 * lookup for a swap function on a parameter type fail.
 *
 * Std::swap is implemented in terms of move construction and move assignment.
 * If this functionality is not available, an instantiation of std::swap will
 * fail with a hard error.
 */
template<typename T,
         std::enable_if_t
         <std::is_move_assignable<T>::value
          and std::is_move_constructible<T>::value, bool> = true>
void swap(T&, T&)
  noexcept(std::is_nothrow_move_assignable<T>::value
           and std::is_nothrow_move_constructible<T>::value);

template<typename T, std::size_t N,
         typename = decltype(swap(std::declval<T&>(), std::declval<T&>()))>
void swap(T (&a)[N], T (&b)[N]) noexcept(noexcept(swap(*a, *b)));

/**
 * We define a boolean template variable which detects whether swap
 * is available by unqualified lookup.
 *
 * If T == U, given the presence of a swap overload in this namespace, a
 * swap implementation can only be unavailable if a matching swap signature
 * was explicitly deleted in the namespace of (one or both of) the argument
 * parameter types OR the type in question does not support move assignment
 * and/or move construction.
 *
 * If T != U, a swap implementation is available iff a matching swap signature
 * was defined in the namespace of (one or both of) the argument parameter
 * types.
 */
template<typename T, typename U, typename = void>
static constexpr bool defined_for = false;

template<typename T, typename U>
static constexpr bool
defined_for<T, U, void_t<decltype(swap(std::declval<T&>(),
                                       std::declval<U&>()))>> = true;

#ifdef __INTEL_COMPILER
/**
 * Intel compiler workaround.
 *
 * On Intel 18.0.2, icpc does not correctly sfinae the previous signature for 
 * array parameters. This specialization is a workaround for that failure.
 * Strictly speaking, this work around introduces the possibility of an incorrect
 * detection. Should a user delete the array-specific swap in the namespace of
 * the parameter type, this specialization will fail to detect that. In practice,
 * there is little utility to deleting that signature, so this is not expected
 * to be an issue in normal use.
 */
template<typename T, std::size_t N>
static constexpr bool
defined_for<T[N], T[N], void_t<decltype(swap(std::declval<T&>(),
                                             std::declval<T&>()))>> = true;
#endif

}
}

template<typename T, typename U = T>
static constexpr bool SwapDefined_v = detail::swap::defined_for<T, U>;

template<typename T, typename U = T>
struct SwapDefined : std::integral_constant<bool, SwapDefined_v<T, U>> {};
