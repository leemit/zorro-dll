
#pragma once

#include "enum.h"

namespace z {
template <typename EnumType, typename UnderlyingType = ZORRO_ENUM_UNDERLYING_TYPE(EnumType)>
class CBitfield
{
public:
	typedef CBitfield<EnumType, UnderlyingType> TThis;
	typedef EnumType TEnum;
	typedef UnderlyingType TUnderlyingType;

	CBitfield() : m_value() {}
	~CBitfield() {}

	CBitfield(TEnum value) : m_value( static_cast<TUnderlyingType>( value ) ) {}

	const TThis operator | ( const TThis& other ) const { return TThis( m_value | other.m_value ); }
	const TThis operator & ( const TThis& other ) const { return TThis( m_value & other.m_value ); }
	const TThis operator | ( const TEnum& other ) const { return TThis( m_value | static_cast<TUnderlyingType>( other ) ); }
	const TThis operator & ( const TEnum& other ) const { return TThis( m_value & static_cast<TUnderlyingType>( other ) ); }
	const TThis operator ~ () const                     { return TThis( ~m_value ); }

	const TThis& operator =  ( const TThis& other ) { m_value =  other.m_value; return *this; }
	const TThis& operator |= ( const TThis& other ) { m_value |= other.m_value; return *this; }
	const TThis& operator &= ( const TThis& other ) { m_value &= other.m_value; return *this; }

	const TThis& operator =  ( const TEnum& other ) { m_value =  static_cast<TUnderlyingType>( other ); return *this; }
	const TThis& operator |= ( const TEnum& other ) { m_value |= static_cast<TUnderlyingType>( other ); return *this; }
	const TThis& operator &= ( const TEnum& other ) { m_value &= static_cast<TUnderlyingType>( other ); return *this; }

	operator TUnderlyingType() const { return m_value; }
	operator bool() const { return m_value != 0; }

	const bool operator == ( const TThis& other ) const { return m_value == other.m_value; }
	const bool operator != ( const TThis& other ) const { return m_value != other.m_value; }
	const bool operator <  ( const TThis& other ) const { return m_value <  other.m_value; }
	const bool operator <= ( const TThis& other ) const { return m_value <= other.m_value; }
	const bool operator >  ( const TThis& other ) const { return m_value >  other.m_value; }
	const bool operator >= ( const TThis& other ) const { return m_value >= other.m_value; }

	const bool operator == ( const TEnum& other ) const { return m_value == static_cast<TUnderlyingType>( other ); }
	const bool operator != ( const TEnum& other ) const { return m_value != static_cast<TUnderlyingType>( other ); }
	const bool operator <  ( const TEnum& other ) const { return m_value <  static_cast<TUnderlyingType>( other ); }
	const bool operator <= ( const TEnum& other ) const { return m_value <= static_cast<TUnderlyingType>( other ); }
	const bool operator >  ( const TEnum& other ) const { return m_value >  static_cast<TUnderlyingType>( other ); }
	const bool operator >= ( const TEnum& other ) const { return m_value >= static_cast<TUnderlyingType>( other ); }

private:
	CBitfield(TUnderlyingType value) : m_value( value ) {}

	TUnderlyingType m_value;
};
} // namespace z
