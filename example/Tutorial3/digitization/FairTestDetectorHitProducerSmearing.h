#ifndef PNDTORINODETECTORHITPRODUCERSMEARING_H
#define PNDTORINODETECTORHITPRODUCERSMEARING_H

#include "FairTask.h"

class TClonesArray;

class FairTestDetectorHitProducerSmearing : public FairTask
{
  public:

    /** Default constructor **/
    FairTestDetectorHitProducerSmearing();

    /** Destructor **/
    ~FairTestDetectorHitProducerSmearing();

    /** Initiliazation of task at the beginning of a run **/
    virtual InitStatus Init();

    /** ReInitiliazation of task when the runID changes **/
    virtual InitStatus ReInit();


    /** Executed for each event. **/
    virtual void Exec(Option_t* opt);

    /** Load the parameter container from the runtime database **/
    virtual void SetParContainers();

    /** Finish task called at the end of the run **/
    virtual void Finish();

  private:

    /** Input array from previous already existing data level **/
    TClonesArray* fPointsArray;

    /** Output array to  new data level**/
    TClonesArray* fHitsArray;

    FairTestDetectorHitProducerSmearing(const FairTestDetectorHitProducerSmearing&);
    FairTestDetectorHitProducerSmearing operator=(const FairTestDetectorHitProducerSmearing&);

    ClassDef(FairTestDetectorHitProducerSmearing,1);
};

#endif