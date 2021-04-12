//
// Created by Алмаз Хайруллин on 22.03.2021.
//

#ifndef PRE_TEST__TIME_H
#define PRE_TEST__TIME_H

using namespace std;

struct Time {
    int hours;
    int mins;
    int seconds;

    int toSeconds() const {
        return hours * 3600 + mins * 60 + seconds;
    }

    bool operator<(const Time &t2) const {
        return toSeconds() < t2.toSeconds();
    }

};

istream &operator>>(istream &in, Time &t) {
    string s;
    stringstream ss;
    getline(in, s, ':');
    ss << s;
    int hours;
    ss >> hours;
    t.hours = hours;
    s.clear();
    ss.clear();
    getline(in, s, ':');
    ss << s;
    int mins;
    ss >> mins;
    t.mins = mins;
    s.clear();
    ss.clear();
    getline(in, s);
    ss << s;
    int sec;
    ss >> sec;
    t.seconds = sec;
    return in;
}

ostream &operator<<(ostream &out, const Time &t) {
    out << t.hours << ":" << t.mins << ":" << t.seconds;
    return out;
}


#endif //PRE_TEST__TIME_H
