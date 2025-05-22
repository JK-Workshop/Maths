#include <Vector.h>

int main() {
	constexpr auto add = [](const double& self, const double& other)->double { return self + other; };
	constexpr auto negate = [](const double& self)->double { return -self; };
	constexpr auto multiply = [](const double& self, const double& other)->double { return self * other; };
	constexpr auto inverse = [](const double& self)->double { return 1.0 / self; };

	using vec3d = jk::math::Vector<double, 3, add, negate, multiply, inverse>;

	vec3d v1(1.0, 2.0, 3.0), v2(10.0, 20.0, 30.0);
	vec3d v3 = v1 + v2;
	v3.Print();
	printf("%lf\n", v1.Dot(v2));

	return 0;
}