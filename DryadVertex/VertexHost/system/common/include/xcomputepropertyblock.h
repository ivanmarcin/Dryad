/*
Copyright (c) Microsoft Corporation

All rights reserved.

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in 
compliance with the License.  You may obtain a copy of the License 
at http://www.apache.org/licenses/LICENSE-2.0   


THIS CODE IS PROVIDED *AS IS* BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, EITHER 
EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF 
TITLE, FITNESS FOR A PARTICULAR PURPOSE, MERCHANTABLITY OR NON-INFRINGEMENT.  


See the Apache Version 2.0 License for specific language governing permissions and 
limitations under the License. 

*/

#pragma once

#include <dvertexcommand.h>
#include <XComputeTypes.h>

class DryadXComputePnProcessPropertyRequest :
    public DryadPnProcessPropertyRequest
{
public:
    DryadXComputePnProcessPropertyRequest();

    void SetPropertyLabel(const char* label, const char* controlLabel);
    void SetPropertyString(const char* string);
    DrMemoryBuffer* GetPropertyBlock();

protected:
    DrStr64                          m_label;
    DrStr64                          m_controlLabel;
    DrStr64                          m_string;
    DrRef<DrSimpleHeapBuffer>  m_block;
};

class DryadXComputePnProcessPropertyResponse :
    public DryadPnProcessPropertyResponse
{
public:
    DryadXComputePnProcessPropertyResponse(PXC_PROCESS_INFO response);

    void RetrievePropertyLabel(const char* label);
    DrMemoryBuffer* GetPropertyBlock();

private:
    PXC_PROCESS_INFO                  m_processInfo;
    PXC_PROCESSPROPERTY_INFO          m_propertyInfo;
    DrRef<DrFixedMemoryBuffer>  m_block;
};

