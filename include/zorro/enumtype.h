
#pragma once

template<typename EnumDef, typename UnderlyingType = typename EnumDef::TUnderlyingType>
class CEnumType : public EnumDef
{
public:
	typedef UnderlyingType TUnderlyingType;
	typedef CEnumType<EnumDef, UnderlyingType> TThis;

	CEnumType() {}
	CEnumType(TUnderlyingType v) : m_value(v) {}

	explicit operator TUnderlyingType() const { return m_value; }

	friend bool operator == (const TThis& left, const TThis& right) { return left.m_value == right.m_value; }
	friend bool operator != (const TThis& left, const TThis& right) { return left.m_value != right.m_value; }
	friend bool operator <  (const TThis& left, const TThis& right) { return left.m_value <  right.m_value; }
	friend bool operator <= (const TThis& left, const TThis& right) { return left.m_value <= right.m_value; }
	friend bool operator >  (const TThis& left, const TThis& right) { return left.m_value >  right.m_value; }
	friend bool operator >= (const TThis& left, const TThis& right) { return left.m_value >= right.m_value; }

private:
	TUnderlyingType m_value;
};

template<typename UnderlyingType>
struct SEnumBaseDef
{
	typedef UnderlyingType TUnderlyingType;
};
