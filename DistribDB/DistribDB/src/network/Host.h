//
//  Host.h
//  DistribDB
//
//  Created by Saagar Patel on 3/25/13.
//  Copyright (c) 2013 Saagar Patel. All rights reserved.
//

#ifndef DistribDB_Host_h
#define DistribDB_Host_h

#include <limits.h>

namespace DistribDB
{
    namespace Network
    {
        class Host
        {
        public:
            typedef unsigned long long Identifier;
            static const Identifier INVALID = ULLONG_MAX;
        };
    }
}

#endif
