#ifndef SIMU_TUPLE_H
#define SIMU_TUPLE_H

#include <string>
#include <memory>

#include "TFile.h"
#include "TTree.h"
#include "TVector3.h"

class simu_tuple {
    public:
        simu_tuple(std::string name="fermilike_dampe_simu", std::string desc="Fermi-Like Simulation Tree");
        ~simu_tuple() {};
        
        void SetPosition(const std::vector<double> simu_position);
        void SetDirCosine(const std::vector<double> simu_dir_cosine);
        void SetThetaPhi(const double simu_theta, const double simu_phi);
        void SetR(const std::vector<double> simu_R);
        void Fill() {simu_tree->Fill();};
        void Write(TFile* outfile);

    private:
        void branch();

        std::shared_ptr<TTree> simu_tree;
        TVector3 position {0, 0, 0};
        TVector3 dir_cosine {0, 0, 0};
        TVector3 R {0, 0, 0};
        double theta{0}, phi{0};
};

#endif