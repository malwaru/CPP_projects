import std;

using namespace std;

template<predicate<int, int> Matcher, invocable<size_t, int, int> MatchHandler>
void findMatches(span<const int> values1, span<const int> values2,
	Matcher matcher, MatchHandler handler)
{
	if (values1.size() != values2.size()) { return; } // Must be same size.

	for (size_t i{ 0 }; i < values1.size(); ++i) {
		if (matcher(values1[i], values2[i])) {
			handler(i, values1[i], values2[i]);
		}
	}
}

bool intEqual(int value1, int value2)
{
	return value1 == value2;
}

bool bothOdd(int value1, int value2)
{
	return value1 % 2 == 1 && value2 % 2 == 1;
}

class Handler
{
public:
	void handleMatch(size_t position, int value1, int value2)
	{
		println("Match found at position {} ({}, {})",
			position, value1, value2);
	}
};

int main()
{
	Handler handler;

	vector values1{ 2, 5, 6, 9, 10, 1, 1 };
	vector values2{ 4, 4, 2, 9, 0, 3, 1 };
	println("Calling findMatches() using intEqual():");
	findMatches(values1, values2, intEqual, bind(&Handler::handleMatch, &handler,
		placeholders::_1, placeholders::_2, placeholders::_3));

	println("Calling findMatches() using bothOdd():");
	findMatches(values1, values2, bothOdd, bind(&Handler::handleMatch, &handler,
		placeholders::_1, placeholders::_2, placeholders::_3));
}
