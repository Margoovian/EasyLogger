#pragma once

#include "epch.h"

namespace EasyLogger {

	template<typename T> 
	concept isInt = std::same_as<T, int>;

	class Sequence;

	template<typename T>
	concept isSequence = std::same_as<T, Sequence>;

	static inline std::map<int, const char*> sEscapeCodes
	
	{

		// - https://learn.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences

		// + Simple Cursor Positioning

		{0 , "\x1b" "M"				}, // - Shorthand: RI		| Behaviour: Reverse Index – Performs the reverse operation of \n, moves cursor up one line, maintains horizontal position, scrolls buffer if necessary*
		{1 , "\x1b" "7"				}, // - Shorthand: DECSC	| Behaviour: Save Cursor Position in Memory**
		{2 , "\x1b" "8"				}, // - Shorthand: DECSR	| Behaviour: Restore Cursor Position from Memory**
		
		// + Cursor Positioning

		{3 , "\x1b" "[{}A"			}, // - Code: CUU			| Description: Cursor Up							| Behaviour: Cursor up by <n>
		{4 , "\x1b" "[{}B"			}, // - Code: CUD			| Description: Cursor Down							| Behaviour: Cursor down by <n>
		{5 , "\x1b" "[{}C"			}, // - Code: CUF			| Description: Cursor Forward						| Behaviour: Cursor forward (Right) by <n>
		{6 , "\x1b" "[{}D"			}, // - Code: CUB			| Description: Cursor Backward						| Behaviour: Cursor backward (Left) by <n>
		{7 , "\x1b" "[{}E"			}, // - Code: CNL			| Description: Cursor Next Line						| Behaviour: Cursor down <n> lines from current position
		{8 , "\x1b" "[{}F"			}, // - Code: CPL			| Description: Cursor Previous Line					| Behaviour: Cursor up <n> lines from current position
		{9 , "\x1b" "[{}G"			}, // - Code: CHA			| Description: Cursor Horizontal Absolute			| Behaviour: Cursor moves to <n>th position horizontally in the current line
		{10, "\x1b" "[{}d"			}, // - Code: VPA			| Description: Vertical Line Position Absolute		| Behaviour: Cursor moves to the <n>th position vertically in the current column
		{11, "\x1b" "[{};{}H"		}, // - Code: CUP			| Description: Cursor Position						| Behaviour: *Cursor moves to <x>; <y> coordinate within the viewport, where <x> is the column of the <y> line
		{12, "\x1b" "[{};{}f"		}, // - Code: HVP			| Description: Horizontal Vertical Position			| Behaviour: *Cursor moves to <x>; <y> coordinate within the viewport, where <x> is the column of the <y> line
		{13, "\x1b" "[s"			}, // - Code: ANSISYSSC		| Description: Save Cursor – Ansi.sys emulation		| Behaviour: **With no parameters, performs a save cursor operation like DECSC
		{14, "\x1b" "[u"			}, // - Code: ANSISYSRC		| Description: Restore Cursor – Ansi.sys emulation	| Behaviour: **With no parameters, performs a restore cursor operation like DECRC

		// + Cursor Visibility

		{15, "\x1b" "[?12h"			}, // - Code: ATT160_ON		| Description: Text Cursor Enable Blinking			| Behaviour: TODO - Copy behaviour from website here
		{16, "\x1b" "[?12l"			}, // - Code: ATT160_OFF	| Description: Text Cursor Disable Blinking			| Behaviour: TODO - Copy behaviour from website here
		{17, "\x1b" "[?25h"			}, // - Code: DECTCEM_ON	| Description: Text Cursor Enable Mode Show			| Behaviour: TODO - Copy behaviour from website here
		{18, "\x1b" "[?25l"			}, // - Code: DECTCEM_OFF	| Description: Text Cursor Enable Mode Hide			| Behaviour: TODO - Copy behaviour from website here

		// + Cursor Shape

		{19, "\x1b" "[0SPq"			}, // - Code: DECSCUSR_A	| Description: User Shape							| Behaviour: TODO - Copy behaviour from website here
		{20, "\x1b" "[1SPq"			}, // - Code: DECSCUSR_B	| Description: Blinking Block						| Behaviour: TODO - Copy behaviour from website here
		{21, "\x1b" "[2SPq"			}, // - Code: DECSCUSR_C	| Description: Steady Block							| Behaviour: TODO - Copy behaviour from website here
		{22, "\x1b" "[3SPq"			}, // - Code: DECSCUSR_D	| Description: Blinking Underline					| Behaviour: TODO - Copy behaviour from website here
		{23, "\x1b" "[4SPq"			}, // - Code: DECSCUSR_E	| Description: Steady Underline						| Behaviour: TODO - Copy behaviour from website here
		{24, "\x1b" "[5SPq"			}, // - Code: DECSCUSR_F	| Description: Blinking Bar							| Behaviour: TODO - Copy behaviour from website here
		{25, "\x1b" "[6SPq"			}, // - Code: DECSCUSR_G	| Steady Bar										| Behaviour: TODO - Copy behaviour from website here

		// + Text Modification

		{26, "\x1b" "[{}@"			}, // - Code: ICH			| Insert Character									| Behaviour: TODO - Copy behaviour from website here
		{27, "\x1b" "[{}P"			}, // - Code: DCH			| Delete Character									| Behaviour: TODO - Copy behaviour from website here
		{28, "\x1b" "[{}X"			}, // - Code: ECH			| Erase Character									| Behaviour: TODO - Copy behaviour from website here
		{29, "\x1b" "[{}L"			}, // - Code: IL			| Insert Line										| Behaviour: TODO - Copy behaviour from website here
		{30, "\x1b" "[{}M"			}, // - Code: DL			| Delete Line										| Behaviour: TODO - Copy behaviour from website here
		{31, "\x1b" "[{}J"			}, // - Code: ED			| Erase in Display									| Behaviour: TODO - Copy behaviour from website here
		{32, "\x1b" "[{}K"			}, // - Code: EL			| Erase in Line										| Behaviour: TODO - Copy behaviour from website here

		// + Viewport Positioning

		{33, "\x1b" "[{}S"			}, // - Code: SU			| Scroll Up											| Behaviour: TODO - Copy behaviour from website here
		{34, "\x1b" "[{}T"			}, // - Code: SD			| Scroll Down										| Behaviour: TODO - Copy behaviour from website here

		// + Text Formatting

		{35, "\x1b" "[{}m"			}, // - Code: SGR			| Description: Set Graphics Rendition				| Behaviour: Set the format of the screen and text as specified by <n>
	};

	enum OpCode {
		RI			= 0,
		DECSC		= 1,
		DECSR		= 2,
		CUU			= 3 ,
		CUD			= 4 ,
		CUF			= 5 ,
		CUB			= 6 ,
		CNL			= 7 ,
		CPL			= 8 ,
		CHA			= 9 ,
		VPA			= 10,
		CUP			= 11,
		HVP			= 12,
		ANSISYSSC	= 13,
		ANSISYSRC	= 14,

		ATT160_ON   = 15,
		ATT160_OFF  = 16,
		DECTCEM_ON  = 17,
		DECTCEM_OFF = 18,

		DECSCUSR_A = 19,
		DECSCUSR_B = 20,
		DECSCUSR_C = 21,
		DECSCUSR_D = 22,
		DECSCUSR_E = 23,
		DECSCUSR_F = 24,
		DECSCUSR_G = 25,

		ICH			= 26,
		DCH			= 27,
		ECH			= 28,
		IL			= 29,
		DL			= 30,
		ED			= 31,
		EL			= 32,

		SU			= 33,
		SD			= 34,

		SGR			= 35

	};

	class Formatter {
	public:

		/// <summary>
		/// Formats a sequence of escape codes into 1 output to be rendered by standard out
		/// </summary>
		/// <typeparam name="OP"></typeparam>
		/// <typeparam name="...Vars"></typeparam>
		/// <param name="...codes"></param>
		/// <returns></returns>
		template<OpCode OP, int... Vars ,template<OpCode, int...> class... Codes>
		static constexpr std::string FormatSequence(Codes<OP, Vars...>... codes) {

			auto pack = std::make_tuple(std::forward<Vars>(codes)...);

			std::stringstream stream;

			[&] <std::size_t ... p>(std::index_sequence<p...>) {
				((stream << std::get<p>(codes)), ...);
			}(std::make_index_sequence<sizeof...(codes)>{});

			return stream.str();
		}

		/// <summary>
		/// Formates escape code from given code and variables
		/// </summary>
		/// <typeparam name="...Vars"></typeparam>
		/// <param name="code"></param>
		/// <param name="...vars"></param>
		/// <returns></returns>
		template<Streamable... Vars>
		static constexpr std::string FormatEscapeCode(OpCode code, Vars... vars) {
			return std::vformat(sEscapeCodes[code], std::make_format_args(vars...));
		}

		/// <summary>
		/// Formats the variables into a string that the escape code can use -> In: 255,100,0  Out: "255;100;0"
		/// </summary>
		/// <typeparam name="...Vars"></typeparam>
		/// <param name="...vars"></param>
		/// <returns></returns>
		template<Streamable... Vars>
		static constexpr std::string FormatVariables(Vars... vars) {

			auto pack = std::make_tuple(std::forward<Vars>(vars)...);

			std::stringstream stream;

			[&] <std::size_t ... p>(std::index_sequence<p...>) {
				((stream << std::get<p>(pack) << ";"), ...);
			}(std::make_index_sequence<sizeof...(vars)>{});
			
			return stream.str().erase(stream.str().size()-1);
		}

	};

	/// <summary>
	/// Compile Time Constant Escape code class abstraction
	/// </summary>
	/// <typeparam name="OP"></typeparam>
	/// <typeparam name="...Vars"></typeparam>
	template< OpCode OP, int... Vars >
	class EscapeCode {
	public:
		friend std::ostream& operator <<(std::ostream& out, const EscapeCode<OP, Vars...> escapeCode) {

			return out << Formatter::FormatEscapeCode(OP, Formatter::FormatVariables(Vars...));
		}

		friend std::string operator +(std::string& str, const EscapeCode<OP, Vars...> escapeCode) {
			return str + Formatter::FormatEscapeCode(OP, Formatter::FormatVariables(Vars...));
		}

		friend std::string operator +(const EscapeCode<OP, Vars...> escapeCode, std::string& str) {
			return Formatter::FormatEscapeCode(OP, Formatter::FormatVariables(Vars...)) + str;
		}

		friend void operator +=(std::string& str, const EscapeCode<OP, Vars...> escapeCode) {
			str += Formatter::FormatEscapeCode(OP, Formatter::FormatVariables(Vars...));
		}
	};

	/// <summary>
	/// Sequence of escape codes
	/// </summary>
	class Sequence {
	public:
		/// <summary>
		/// Forms a sequence from compile time constant Escape codes
		/// </summary>
		/// <typeparam name="OP"></typeparam>
		/// <typeparam name="...Vars"></typeparam>
		/// <param name="...codes"></param>
		template<OpCode OP, int... Vars, template<OpCode, int...> class... Codes>
		Sequence(Codes<OP, Vars...>... codes ) : mEval(Formatter::FormatSequence<Codes>(codes...)) {}

		/// <summary>
		/// Forms a sequence with 1 escape code from OpCode and Vars
		/// </summary>
		/// <typeparam name="...Vars"></typeparam>
		/// <param name="code"></param>
		/// <param name="...vars"></param>
		template<isInt... Vars>
		Sequence(OpCode code, Vars... vars) : mEval(Formatter::FormatEscapeCode(code, Formatter::FormatVariables(vars...))) {}

		/// <summary>
		/// Creates a sequence from other sequences (useful for run time formats)
		/// </summary>
		/// <typeparam name="...Seqs"></typeparam>
		/// <param name="...sequences"></param>
		template<isSequence... Seqs>
		Sequence(Seqs... sequences) {

			std::stringstream stream;

			([&]{
				stream << sequences;
			} (), ...);

			mEval = std::move(stream.str());
		}

		inline std::string str() const { return mEval; } // Creates new string possible different implementation wanted

		friend std::ostream& operator <<(std::ostream& out, const Sequence& sequence) {
			return out << sequence.mEval;
		};

		friend std::string operator +(std::string& str, const Sequence& sequence) {
			return str + sequence.mEval;
		}

		friend std::string operator +(const Sequence& sequence, std::string& str) {
			return sequence.mEval + str;
		}

		friend void operator +=(std::string& str, const Sequence& sequence) {
			str += sequence.mEval;
		}

	private:
		std::string mEval;
	};

}

// Classes for compositions
namespace EasyLogger::Comp {

	template<int Red, int Green, int Blue>
	class Colour : public EscapeCode<SGR, 38, 2, Red, Green, Blue> {};

	template<int Param>
	class TextSingle : public EscapeCode<SGR, Param> {};


	Sequence CreateColour(int red, int green, int blue) {

		red > 255 ? red = 255: red = red;
		red < 0 ? red = 0: red = red;

		green > 255 ? green = 255 : green = green;
		green < 0 ? green = 0 : green = green;

		blue > 255 ? blue = 255 : blue = blue;
		blue < 0 ? blue = 0 : blue = blue;

		return Sequence(OpCode::SGR,38,2,red,green,blue);
	}

	Sequence Underline(bool isUnderlined) {
		return isUnderlined ? Sequence(OpCode::SGR, 4) : Sequence(OpCode::SGR, 24);
	}

	template<isSequence... Seqs>
	Sequence FormSequence(Seqs... attributes) {
		return Sequence(attributes...);
	}

	template<int Red, int Green, int Blue>
	std::string WrapWithColour(const char* text) {
		std::string str;
		str += Colour<Red, Green, Blue>();
		str += text;
		str += TextSingle<0>();
		return str;
	}

	template<OpCode OP, int... Vars, template<OpCode, int...> class Code>
	std::string WrapWithAttr(const char* text, Code<OP, Vars...> code) {
		std::string str;
		str += code;
		str += text;
		str += TextSingle<0>();
		return str;
	}

	std::string WrapWithSequence(const char* text, const Sequence& sequence) {
		std::string str;
		str += sequence;
		str += text;
		str += TextSingle<0>();
		return str;
	}
}

// Pre-Defined Attributes
namespace EasyLogger::Attrs {

	template<OpCode OP, int... Vars, template<OpCode, int...> class... Codes>
	constexpr Sequence FormSequence(Codes<OP, Vars>... attributes) {
		return Sequence(attributes...);
	}

	typedef Comp::TextSingle<0> Default;

	typedef Comp::TextSingle<1				> Bold;
	typedef Comp::TextSingle<22				> NoBold;
	typedef Comp::TextSingle<4				> Underline;
	typedef Comp::TextSingle<24				> NoUnderline;

	typedef Comp::Colour	< 255, 255, 255	> White		;
	typedef Comp::Colour	< 0, 0, 0		> Black		;
	typedef Comp::Colour	< 127, 127, 127	> Grey		;
	typedef Comp::Colour	< 255, 0, 255	> Magenta	;
	typedef Comp::Colour	< 255, 255, 0	> Yellow	;
	typedef Comp::Colour	< 0, 255, 255	> Cyan		;
	typedef Comp::Colour	< 255, 0, 0		> Red		;
	typedef Comp::Colour	< 0, 255, 0		> Green		;
	typedef Comp::Colour	< 0, 0, 255		> Blue		;
	typedef Comp::Colour	< 255, 120, 50	> Orange	;

}