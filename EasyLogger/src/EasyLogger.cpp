// EasyLogger.cpp : Defines the functions for the static library.
//

#include <epch.h>

//#define WIN32_LEAN_AND_MEAN 

#include <EasyLogger.h>
#include <EasyParser.h>

#include <ConsoleVirtualizer.h>

#include <random> 

#include <chrono>

namespace EasyLogger {


	void EasyLogger::SetupEasyLogger() {
		//std::cout << rang::style::reset;
	}

	void EasyLogger::Log(const char* log) {
		//EasyParser parser;

		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 255);
		//for (int t = 0; t < 20; t++) {
		//	int r = dist6(rng);
		//	int g = dist6(rng);
		//	int b = dist6(rng);
		//	std::string colour = Formatter::ColourConsoleForeground(r, g, b);
		//std::cout << Attrs::Blue() << log << "\n";
		//}

		//std::cout << Attrs::Default() << Attrs::Underline() << log << Attrs::NoUnderline() << "\n" ;
		//std::cout << Attrs::Bold() << Attrs::Magenta() << log << "\n";
		//std::cout << Attrs::Green() << log << "\n";
		//std::cout << Attrs::Blue() << log << "\n";
		//std::cout << Comp::Colour<60, 50, 10>() << "Custom! | " << Attrs::Default() << Comp::CreateColour(255, 120, 50) << "Even More Custom! \n";
		//std::cout << Attrs::Default() << Comp::FormSequence(Comp::Underline(true), Comp::CreateColour(60, 145, 200)) << log << "\n" << Attrs::Default();
		//std::cout << Comp::WrapWithAttr(log, Attrs::Cyan()) << "\n";
		//std::cout << Comp::WrapWithColour<255, 120, 50>(log) << "\n";		
		auto start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 1000; i++) {
			//std::cout << Comp::WrapWithSequence(log, Comp::FormSequence(Comp::Underline(true), Attrs::FormSequence(Attrs::Red()))) << "\n";
			std::cout << Attrs::Red() << log << "\n";
			//std::cout << log << "\n";
		}
		
		
		std::cout << Attrs::Default() << "\n";

		auto stop = std::chrono::high_resolution_clock::now();
		auto durationColour = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);


		auto starta = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 1500; i++) {
			//std::cout << Comp::WrapWithSequence(log, Comp::FormSequence(Comp::Underline(true), Attrs::FormSequence(Attrs::Red()))) << "\n";
			std::cout << log << "\n";
		}

		auto stopa = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopa - starta);

		std::cout << Attrs::Default() << "\n\n\t" << Comp::WrapWithAttr("Duration:", Attrs::Underline()) << " " << Comp::WrapWithAttr(std::to_string(duration.count()).c_str(), Attrs::Orange()) << "\n";
		std::cout << Attrs::Default() << "\n\n\t" << Comp::WrapWithAttr("Duration (EasyLogger):", Attrs::Underline()) << " " << Comp::WrapWithAttr(std::to_string(durationColour.count()).c_str(), Attrs::Orange()) << "\n";
		
		std::cout << Attrs::Default() << "\n\n\t" << Comp::WrapWithAttr("Difference:", Attrs::Underline()) << " " << Comp::WrapWithAttr(std::to_string(durationColour.count() - duration.count()).c_str(), Attrs::Red()) << "\n";


		//start = std::chrono::high_resolution_clock::now();
		//std::cout << log << "\n";
		//stop = std::chrono::high_resolution_clock::now();
		//duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		//std::cout << Attrs::Default() << "\n\n\t" << Comp::WrapWithAttr("Duration:", Attrs::Underline()) << " " << Comp::WrapWithAttr(std::to_string(duration.count()).c_str(), Attrs::Orange()) << "\n";
	}

}