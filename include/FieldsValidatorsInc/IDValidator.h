#pragma once 
#include "FieldsValidatorsInc/BaseFieldValidators.h"
#include <string>
#include <cstdint> // for uint32_t

class IDValidator : public BaseFieldValidators<uint32_t>
{
public:
	IDValidator() : BaseFieldValidators("Wrong control digit\n") {}
	bool validate(const uint32_t&)const;
};