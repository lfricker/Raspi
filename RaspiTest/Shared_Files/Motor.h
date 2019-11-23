#pragma once
class Motor
{
public:
	virtual void setPower(double power) = 0;
	virtual double getPower() = 0;
	virtual ~Motor() {};
};

