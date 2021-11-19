#pragma once

#include <cstddef>
#include <optional>

#include <xtensor/xtensor.hpp>
#include <xtensor/xtensor_forward.hpp>

#include "ecole/dynamics/dynamics.hpp"

namespace ecole::dynamics {
class CuttingDynamics : public EnvironmentDynamics<std::size_t, std::optional<xt::xtensor<std::size_t, 1>>> {
public:
	using ActionSet = std::optional<xt::xtensor<std::size_t, 1>>;

	CuttingDynamics();

	std::tuple<bool, ActionSet> reset_dynamics(scip::Model& model) override;

	std::tuple<bool, ActionSet> step_dynamics(scip::Model& model, std::size_t const& var_idx) override;
};

}  // namespace ecole::dynamics