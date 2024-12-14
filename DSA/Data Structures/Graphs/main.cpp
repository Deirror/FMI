#include "graph.hpp"

int main() {
	graph<int> gam({ {1, 1, 0}, {0, 0, 1}, {0, 0, 0} }, {0, 1, 2});
	std::cout << gam.is_connected() << '\n';
	graph<int> gal({ 0, 1, 2, 3, 4, 5, 6, 7}, { {1, 2, 7}, {0}, {0}, {4}, {3, 5}, {4, 6}, {5}, {0} });
	std::cout << gal.is_connected() << '\n';
	std::cout << gal.contains(4) << '\n';
	std::cout << gal.has_cycle() << '\n';// 0
	graph<string> gel({ {"str", "abc"}, {"abc", "dsa"}, {"dsa", "sda"}, {"sda", "sda"} });
	std::cout << gel.has_cycle() << '\n';// 1
	graph<string> gelTroll({ {{'h', 'a', 'h'}, {'x', 'D'}}, {{'a', 'm', 'a', 'm'}, {'x', 'D'}}, {{'x', 'D'}, {'x', 'D'}}});
	std::cout << gelTroll.has_cycle() << '\n';// 1
	std::cout << gelTroll.path( "hah", "amam" );// 2
	return 0;
}
