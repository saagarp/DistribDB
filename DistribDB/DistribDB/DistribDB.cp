/*
 *  DistribDB.cp
 *  DistribDB
 *
 *  Created by Saagar Patel on 3/25/13.
 *  Copyright (c) 2013 Saagar Patel. All rights reserved.
 *
 */

#include <iostream>
#include "DistribDB.h"
#include "DistribDBPriv.h"

void DistribDB::HelloWorld(const char * s)
{
	 DistribDBPriv *theObj = new DistribDBPriv;
	 theObj->HelloWorldPriv(s);
	 delete theObj;
};

void DistribDBPriv::HelloWorldPriv(const char * s) 
{
	std::cout << s << std::endl;
};

