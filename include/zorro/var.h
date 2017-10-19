
#pragma once

ZORRO_NAMESPACE_OPEN

template <typename VariableDef>
class CVariable : public VariableDef
{
	typedef CVariable<VariableDef> TThis;

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

template <typename VariableDef>
class CExpression : public VariableDef
{
	typedef CExpression<VariableDef> TThis;

	inline CExpression() {}
	inline CExpression(const TThis&) {}
	inline TThis& operator=(const TThis&) {}

public:
	typedef typename VariableDef::TType TType;

	inline operator TType() const { return VariableDef::get(); }
	static TThis& getInstance() { static TThis instance; return instance; }
};

template<typename T>
struct SVariableBaseDef
{
	typedef T TType;
};

ZORRO_NAMESPACE_CLOSE
