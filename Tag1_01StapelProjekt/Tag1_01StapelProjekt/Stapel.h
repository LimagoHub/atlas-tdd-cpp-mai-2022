#pragma once
class Stapel
{
	
	int data[10];
	int index;
public:
	Stapel();

	void push(int value);
	int pop();

	bool is_empty()  const;
	bool is_full() const;
};

