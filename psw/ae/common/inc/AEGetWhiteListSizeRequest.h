/*
 * Copyright (C) 2011-2016 Intel Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of Intel Corporation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#ifndef __AE_GET_WHITE_LIST_SIZE_REQUEST_H
#define __AE_GET_WHITE_LIST_SIZE_REQUEST_H

#include <IAERequest.h>
class IAESMLogic;

class AEGetWhiteListSizeRequest : public IAERequest{
    public:
        AEGetWhiteListSizeRequest(uint32_t timeout = 0);
        AEGetWhiteListSizeRequest(const AEGetWhiteListSizeRequest& other);
        ~AEGetWhiteListSizeRequest();

        void ReleaseMemory();

        AEMessage*  serialize(ISerializer* serializer);

        //inflater -> empty for now ... but soon
        void inflateValues(uint32_t timeout = 0);

        //checks
        bool check() {return true;} // no special check for this object. Maybe later
        virtual IAEResponse* execute(IAESMLogic*);

        //used to determin in which queue to be placed
        virtual RequestClass getRequestClass();
        bool operator==(const AEGetWhiteListSizeRequest& other) const;
        AEGetWhiteListSizeRequest& operator=(const AEGetWhiteListSizeRequest& other);
        void visit(IAERequestVisitor& visitor);
        void CopyFields(uint32_t timeout);
};

#endif
