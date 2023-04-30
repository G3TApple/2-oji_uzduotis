#ifndef STUDENTAS_H
#define STUDENTAS_H


class Studentas
{
    private:
        string vardas_, pavarde_;
        vector<int> paz_;
        int egz_;
        double gal_vid_, gal_med_;

    public:
        Studentas() : vardas_(""), pavarde_(""), egz_(0), gal_vid_(0), gal_med_(0) {}
        Studentas(string vardas, string pavarde, vector<int> paz, int egz, double gal_vid, double gal_med) : vardas_(vardas), pavarde_(pavarde), paz_(paz), egz_(egz), gal_vid_(gal_vid), gal_med_(gal_med) {}
        ~Studentas() { paz_.clear(); };

        void vardas(string vardas) { vardas_ = vardas; }
        void pavarde(string pavarde) { pavarde_ = pavarde; }
        void paz(vector<int> paz) { paz_ = paz; }
        void egz(int egz) { egz_ = egz; }
        void gal_med(double gal_med) { gal_med_ = gal_med; }
        void gal_vid(double gal_vid) { gal_vid_ = gal_vid; }

        string vardas() { return vardas_; }
        string pavarde() { return pavarde_; }
        vector<int> paz() { return paz_; }
        int egz() { return egz_; }
        double gal_med() { return gal_med_; }
        double gal_vid() { return gal_vid_; }


};

#endif // STUDENTAS_H
