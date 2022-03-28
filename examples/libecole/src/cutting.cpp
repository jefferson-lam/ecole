#include "ecole/environment/cutting.hpp"
#include "ecole/information/nothing.hpp"
#include "ecole/instance/set-cover.hpp"
#include "ecole/observation/node-bipartite.hpp"
#include "ecole/reward/n-nodes.hpp"
#include <iostream>
#include <ostream>

int main() {
	try {
		auto env = ecole::environment::
			Cutting<ecole::observation::NodeBipartite, ecole::reward::NNodes, ecole::information::Nothing>{};
		std::size_t constexpr n_rows = 100;
		std::size_t constexpr n_cols = 200;
		auto gen = ecole::instance::SetCoverGenerator{{n_rows, n_cols}};

		static constexpr auto n_episodes = 1;
		for (std::size_t i = 0; i < n_episodes; ++i) {
			auto [obs, action_set, reward, done, info] = env.reset(gen.next());
			std::cout << action_set.has_value() << std::endl;
		}
	} catch (std::exception const& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}
}
