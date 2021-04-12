//
// Created by Алмаз Хайруллин on 23.03.2021.
//

#ifndef PRE_TEST__EARTHQUAKE_H
#define PRE_TEST__EARTHQUAKE_H

using namespace std;

struct Earthquake {
    double lat;
    double lon;
    double depth;
    double magnitude;
    string location;

};

ostream &operator<<(ostream &out, const Earthquake &ek) {
    out << "lat=" << ek.lat << " lon=" << ek.lon << " depth=" << ek.depth << " magnitude=" << ek.magnitude
        << " location=" << ek.location;
    return out;
}

#endif //PRE_TEST__EARTHQUAKE_H
