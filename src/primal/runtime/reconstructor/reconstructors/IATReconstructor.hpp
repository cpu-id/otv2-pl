#pragma once

#include "../Reconstructor.hpp"

class IATReconstructor : public Reconstructor {

public:

    IATReconstructor (Segment& segment) : Reconstructor (segment) {};

    //Override handle.
    virtual void ReconstructNative () override;

    /**
     *
     * @point - Calculate absolute address for ImportType type.
     *
     * @args  - Type: ImportType for RVA. Function: Function address. RVA: Relocation to function-dependency in segment.
     *
     **/

    int GetImportAbsoluteAddress (AdditionalRuntime::ImportType type, int function, int rva);

private:

    //Getters.

    std::map <std::string, std::vector <AdditionalRuntime::ImportDefinition>>* GetImportsInfo () {
        return GetSegment().GetReconstructProcessorDefinition().m_iat;
    }

};