//
//  Parameter.cpp
//  DistribDB
//
//  Basic type definition of a DistribDB system Parameter.
//
//  Created by Saagar Patel on 3/25/13.
//  Copyright (c) 2013 Saagar Patel. All rights reserved.
//

#include "Parameter.h"

using DistribDB::Parameter::Parameter;

// Update parameter value
void Parameter::set(ValueType what)
{
    value = what;
    notify();
}

Parameter::ValueType Parameter::get()
{
    return value;
}