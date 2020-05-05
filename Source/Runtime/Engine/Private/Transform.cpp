
#include "Precompiled.h"
#include "Transform.h"

Matrix3x3 Transform::GetModelingMatrix() const
{
	Matrix3x3 T = Matrix3x3(Vector3::UnitX, Vector3::UnitY, Vector3(Position,true));
	Matrix3x3 R = Matrix3x3(Vector3(Right, false), Vector3(Up, false), Vector3::UnitZ);
	Matrix3x3 S = Matrix3x3(Vector3(Scale._X, 0, 0), Vector3(0, Scale._Y, 0), Vector3::UnitZ);

	return T*R*S;
}

void Transform::CalculateLocalAxis()
{
	float rotationRadian =  Math::Deg2Rad(Rotation);
	float sin = sinf(rotationRadian);
	float cos = cosf(rotationRadian);

	Right = Vector2(cos, sin);
	Up = Vector2(-sin, cos);
}
