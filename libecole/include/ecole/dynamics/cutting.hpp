#pragma once

#include <cstddef>
#include <nonstd/span.hpp>
#include <optional>
#include <utility>

#include "scip/def.h"
#include <xtensor/xtensor.hpp>

#include "ecole/dynamics/parts.hpp"
#include "ecole/export.hpp"

namespace ecole::dynamics {

class ECOLE_EXPORT CuttingDynamics : public DefaultSetDynamicsRandomState {
public:
	using ActionSet = std::optional<xt::xtensor<std::size_t, 1>>;
	using Action = std::pair<nonstd::span<std::size_t const>, nonstd::span<SCIP_Real const>>;

	ECOLE_EXPORT CuttingDynamics();

	ECOLE_EXPORT auto reset_dynamics(scip::Model& model) -> std::tuple<bool, ActionSet>;

	ECOLE_EXPORT auto step_dynamics(scip::Model& model, std::size_t const& var_idx) -> std::tuple<bool, ActionSet>;
};

}  // namespace ecole::dynamics
