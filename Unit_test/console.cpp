#include<cmath>
#include<stdexcept>

using namespace std;

float calculate_R(float x, float y)
{
	float R = sqrt(x * y) / abs(x);

	return R;
}


float calculate_S(float x, float y)
{
	float S = cos(y) * log2(x);

	return S;
}