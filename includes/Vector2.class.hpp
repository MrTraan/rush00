#pragma once

class Vector2 {
   public:
	Vector2(void);
	Vector2(int x, int y);
	Vector2(const Vector2& src);
	~Vector2(void);

	Vector2& operator=(const Vector2& rhs);

	int x;
	int y;
};
