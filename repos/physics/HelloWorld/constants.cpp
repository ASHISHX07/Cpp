#include <iostream>

double height() {
	std::cout << "Enter the height of the tower in meters: ";
	double x{};
	std::cin >> x;

	return x;
}

void calculateDistance(double height) {

	int seconds{ 0 };

	while (height >= 0) {

		double distance{ height - 9.8 * seconds * seconds / 2 };

		if (distance <= 0) {
			std::cout << "the ball is on the ground\n";
			break;
		}
		else
		{
			std::cout << "At " << seconds << " seconds, the ball is at height: " << distance << '\n';
		}
		++seconds;
	}
}

int main() {

	double height{ ::height() };

	calculateDistance(height);

	return 0;
}