#pragma once

namespace EasyLogger {

	// + Delimiters
	// - 
	// - [ColourFlag]				$colour(colour)			-> Sets colour flag [sets the base colour of the text]
	// - [ShortColourFlag]			$c(colour)				-> Shorthand of $colour(colour)
	// - 
	// - [Colour]					@colour<colour>(text)	-> Colours text
	// - [ShortColour]				@c<colour>(test)		-> Shorthand of @color<colour>(text)
	// - 
	// - [Variable]					@var(0)					-> Places variable in string at location
	// - [VariableColoured]			@var<colour>(0)			-> Places varialbe in string with colour
	// - [ShortVariable]			@v(0)					-> Shorthand of @var(0)
	// - [ShortVariableColoured]	@v<colour>(0)			-> Shorthand of @var<colour>(0)
	// - 
	// - [ColourVariable]			@colour({0})			-> Colours variable
	// - [ShortColourVariable]		@c({0})					-> Shorthand of @color({0})
	// - 
	// + Constants
	// -
	// - [White]					@White					-> Sets Colour to white   
	// - [Black]					@Black					-> Sets Colour to black	 
	// - [Grey]						@Grey					-> Sets Colour to grey	 
	// - [Magenta]					@Magenta				-> Sets Colour to magenta 
	// - [Yellow]					@Yellow					-> Sets Colour to yellow	 
	// - [Red]						@Red					-> Sets Colour to red	 
	// - [Cyan]						@Cyan					-> Sets Colour to cyan	 
	// - [Green]					@Green					-> Sets Colour to green	 
	// - [Blue]						@Blue					-> Sets Colour to blue	 
	// - [Orange]					@Orange					-> Sets Colour to orange	 
	// -
	// - [Underline]				@Underline				-> Underlines text
	// - [RUnderline]				@^Underline				-> Removes underline
	// - [Bold]						@Bold					-> Bolds text
	// - [RBold]					@^Bold					-> Removes bold
	// -

	enum class DelimiterType {
		None = 0,
		Variable,
		Colour,
		ColourVarialbe,
		ColourFlag,
		VariableColoured,
		ShortColour,
		ShortColourVarialbe,
		ShortColourFlag,
		ShortVariableColoured,

		White,
		Black,
		Grey,
		Magenta,
		Yellow,
		Red,
		Cyan,
		Green,
		Blue,
		Orange,

		Underline,
		RUnderline,
		Bold,
		RBold
	};

	struct DelimiterPosition {
		unsigned int SpecialCharacterPosition; // Position of the '@' or '$'
		unsigned int BracketStart; // Position of the encapsulating bracket '('
		unsigned int BracketEnd; // Position of the decapsulating bracket ')'
		DelimiterType Type; // Type of Delimiter, see comment above for types
	};

	class EasyParser {

	public:

		EasyParser() = default;

		const char* ParseText(const char* text) const;

		template<Parsable... Vars>
		const char* ParseText(const char* text, Vars&&... vars) const;

	private:

		std::vector<DelimiterPosition> GetDelimiterPositions(const char* text);

		template<Parsable T>
		const char* InsertVar(T& var, DelimiterPosition& position );

		const char* ColourText(const char* text, DelimiterPosition& position);
		
		template<Parsable T>
		const char* ColourVariable(T& var, DelimiterPosition& position);

	private:
		std::stringstream mStream;
	};
}

#include "EasyParser.inl"