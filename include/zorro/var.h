
#ifndef ZORRO_VAR_H_
#define ZORRO_VAR_H_

namespace z
{
template <class VariableDef>
class CVariable : public VariableDef
{
	typedef VariableDef TVariableDef;

	inline CVariable(const CVariable&) {}
	inline CVariable& operator=(const CVariable&) {}

public:
	typedef typename VariableDef::TType TType;

	inline CVariable() {}
	inline operator TType&() const { return TVariableDef::get(); }
	inline TType* operator&() const { return &TVariableDef::get(); }
	inline CVariable& operator=(const TType& value) { TVariableDef::set(value); return *this; }
};

template <class VariableDef>
class CExpression : public VariableDef
{
	typedef VariableDef TVariableDef;

	inline CExpression(const CExpression&) {}
	inline CExpression& operator=(const CExpression&) {}

public:
	typedef typename VariableDef::TType TType;

	inline CExpression() {}
	inline operator TType() const { return TVariableDef::get(); }
};

template <class VariableDef>
class CVarPointer : public VariableDef
{
	typedef VariableDef TVariableDef;

	inline CVarPointer(const CVarPointer&) {}
	inline CVarPointer& operator=(const CVarPointer&) {}

public:
	typedef typename VariableDef::TType TType;

	inline CVarPointer() {}
	inline TType operator->() const { return TVariableDef::get(); }
	inline operator TType() const { return TVariableDef::get(); }
};

template<typename VariableType>
struct SVariableBaseDef
{
	typedef VariableType TType;
};
} // namespace z

#endif ZORRO_VAR_H_
