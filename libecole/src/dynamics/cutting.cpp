#include <algorithm>
#include <cstddef>
#include <iostream>
#include <optional>
#include <scip/pub_lp.h>
#include <scip/pub_var.h>
#include <stdexcept>

#include <fmt/format.h>
#include <xtensor/xtensor.hpp>

#include "ecole/dynamics/cutting.hpp"
#include "ecole/scip/model.hpp"
#include "ecole/scip/utils.hpp"

namespace ecole::dynamics {

CuttingDynamics::CuttingDynamics() = default;

namespace {
std::optional<xt::xtensor<std::size_t, 1>> action_set(scip::Model const& model) {
	if (model.stage() != SCIP_STAGE_SOLVING) {
		return {};
	}
	auto const sepa_cands = model.separator_cands();
	auto sepa_cols = xt::xtensor<std::size_t, 1>::from_shape({sepa_cands.size()});

	std::cout << "Separator candidates size: " << sepa_cands.size() << std::endl;
	return sepa_cols;
}
}  // namespace

auto CuttingDynamics::reset_dynamics(scip::Model& model) -> std::tuple<bool, ActionSet> {
	model.solve_iter_start_cut();
	if (model.solve_iter_is_done()) {
		return {true, {}};
	}
	return {false, action_set(model)};
}

auto CuttingDynamics::step_dynamics(scip::Model& model, std::size_t const& var_idx) -> std::tuple<bool, ActionSet> {
	auto const lp_cols = model.lp_columns();
	if (var_idx >= lp_cols.size()) {
		throw std::invalid_argument{
			fmt::format("Cutting candidate index {} larger than the number of columns", var_idx, lp_cols.size())};
	}

	return {false, action_set(model)};
}

}  // namespace ecole::dynamics
