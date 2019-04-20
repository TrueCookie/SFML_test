#pragma once
#include <SFML/Graphics.hpp>

class Vector2fPro : public Vector2{
public:
	Vector2fPro();
	~Vector2fPro();

	Vector2f::Vector2<T> &operator< (Vector2<T> &left, const Vector2<T> &right);
};

