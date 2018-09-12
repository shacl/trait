#ifndef SHACL_TRAIT
#define SHACL_TRAIT

#include <functional>
#include <type_traits>
#include <iterator>

namespace shacl {
namespace trait {

#include "shacl/trait/void_t.hpp"

#include "shacl/trait/LessThanDefined.hpp"
#include "shacl/trait/LessThanEqualDefined.hpp"
#include "shacl/trait/GreaterThanDefined.hpp"
#include "shacl/trait/GreaterThanEqualDefined.hpp"
#include "shacl/trait/EqualityDefined.hpp"
#include "shacl/trait/InequalityDefined.hpp"
#include "shacl/trait/Comparable.hpp"

#include "shacl/trait/AdditionDefined.hpp"
#include "shacl/trait/SubtractionDefined.hpp"
#include "shacl/trait/MultiplicationDefined.hpp"
#include "shacl/trait/DivisionDefined.hpp"
#include "shacl/trait/Scalable.hpp"
#include "shacl/trait/Arithmetic.hpp"

#include "shacl/trait/IsRange.hpp"
#include "shacl/trait/RangeTraits.hpp"

#include "shacl/trait/IsReferenceWrapper.hpp"
#include "shacl/trait/InvokeDefined.hpp"

#include "shacl/trait/DereferenceDefined.hpp"
#include "shacl/trait/Dereferenced.hpp"

}
}

#endif
