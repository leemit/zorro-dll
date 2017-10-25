
#pragma once

namespace z
{
template <class VariableDef>
class CVariable : public VariableDef
{
	typedef CVariable<VariableDef> TThis;
	typedef VariableDef TVariableDef;

	inline CVariable() {}
	inline CVariable(const TThis&) {}
	inline TThis& operator=(const TThis&) {}

public:
	typedef typename VariableDef::TType TType;

	inline operator TType&() const { return VariableDef::get(); }
	inline TType* operator&() const { return &VariableDef::get(); }
	inline TThis& operator=(const TType& value) { VariableDef::set(value); return *this; }
	static TThis& getInstance() { static TThis instance; return instance; }
};

template <class VariableDef>
class CExpression : public VariableDef
{
	typedef CExpression<VariableDef> TThis;
	typedef VariableDef TVariableDef;

	inline CExpression() {}
	inline CExpression(const TThis&) {}
	inline TThis& operator=(const TThis&) {}

public:
	typedef typename VariableDef::TType TType;

	inline operator TType() const { return VariableDef::get(); }
	static TThis& getInstance() { static TThis instance; return instance; }
};

template <class VariableDef>
class CVarPointer : public VariableDef
{
	typedef CVarPointer<VariableDef> TThis;
	typedef VariableDef TVariableDef;

	inline CVarPointer() {}
	inline CVarPointer(const TThis&) {}
	inline TThis& operator=(const TThis&) {}

public:
	typedef typename VariableDef::TType TType;

	inline TType operator ->() const { return VariableDef::get(); }
	inline operator TType() const { return VariableDef::get(); }
	static TThis& getInstance() { static TThis instance; return instance; }
};

template<typename T>
struct SVariableBaseDef
{
	typedef T TType;
};
} // namespace z
