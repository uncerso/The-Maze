#pragma once

class Color {
public:
	using uchar = unsigned char;
	constexpr Color(uchar r, uchar g, uchar b);
	~Color() = default;

	constexpr Color(Color &&) = default;
	constexpr Color(Color const &) = default;

	constexpr Color & operator = (Color &&) = default;
	constexpr Color & operator = (Color  const &) = default;

	constexpr float red() const noexcept;
	constexpr float green() const noexcept;
	constexpr float blue() const noexcept;

private:
	uchar r;
	uchar g;
	uchar b;

	static constexpr float maxUChar = 255.0f;
};

constexpr Color::Color(uchar r, uchar g, uchar b)
	: r(r)
	, g(g)
	, b(b)
{}

constexpr float Color::red() const noexcept {
	return r / maxUChar;
}

constexpr float Color::green() const noexcept {
	return g / maxUChar;
}

constexpr float Color::blue() const noexcept {
	return b / maxUChar;
}
