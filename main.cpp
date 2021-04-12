#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include "Time.h"
#include "Earthquake.h"


void fillMap(multimap<Time, Earthquake> &m) {
    stringstream ss;

    string str;
    string buffer;

    ifstream in("../earthquakes.csv");
    getline(in, str);
    while (getline(in, buffer)) {
        stringstream info;
        string res;

        Time tim;
        Earthquake earth;

        info << buffer;

        getline(info, res, ',');

        tim.hours = stoi(res.substr(0, 2));
        tim.mins = stoi(res.substr(3, 5));
        tim.seconds = stoi(res.substr(6, 8));

        getline(info, res, ',');
        earth.lat = stod(res);

        getline(info, res, ',');
        earth.lon = stod(res);

        getline(info, res, ',');
        earth.depth = stod(res);

        getline(info, res, ',');
        earth.magnitude = stod(res);

        getline(info, res);
        earth.location = res;

        m.insert({tim, earth});
    }
}

void queryEarthquakes(multimap<Time, Earthquake> &m, const Time &tstart, const Time &tend, string &x) {
    multimap<Time, Earthquake>::iterator low = m.lower_bound(tstart);
    multimap<Time, Earthquake>::iterator up = m.upper_bound(tend);

    int check{0};

    for (multimap<Time, Earthquake>::iterator it = low; it != up; ++it) {
        if (it->second.location.find(x) != string::npos) {
            cout << it->second << endl;
            ++
                    check;
        }
    }
    if (check == 0) {
        cout << "No matches.";
    }
}


int main() {
    multimap<Time, Earthquake> m;
    fillMap(m);

    Time l;
    Time u;

    string country;
    cin >> l;
    cin >> u;
    cin >> country;

    queryEarthquakes(m, l, u, country);

}
