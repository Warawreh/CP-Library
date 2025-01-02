// vim:ts=4:sts=4:sw=4:et
// MOSCOW IPT JINOTEGA
// Table #14
#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;
typedef long long i64;


struct Score {
    int tasks, time, last;
    string name;

    Score() {}

    explicit Score(string name):
        tasks(0),
        time(0),
        last(0),
        name(name) {}

    void add(int at, int a) {
        tasks++;
        time += at + 20 * (a - 1);
        last = max(last, at);
    }

    bool operator<(const Score &other) const {
        if (tasks != other.tasks)
            return tasks > other.tasks;
        if (time != other.time)
            return time < other.time;
        if (last != other.last)
            return last < other.last;
        if (name != other.name)
            return name < other.name;
        return false;
    }
};

ostream& operator<<(ostream& out, const Score &score) {
    return out << score.name << " " << score.tasks << " " << score.time << " " << score.last;
}

int n, m, k;

map<string, Score> mx, mn;
vector<pair<int, int>> last_hour;
string name;
set<string> pool;

Score ReadLine() {
    cin >> name;

    Score score(name);

    last_hour.clear();

    for (int j = 0; j < n; ++j) {
        char c;
        int a, t;

        cin >> c >> a >> t;
        if (c == '+') {
            score.add(t, a);
        } else {
            last_hour.emplace_back(240, a + 1);
        }
    }

    
    return score;
}

void read() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {

        Score score = ReadLine();


        mn[name] = score;

        cerr << score;
        cerr << endl;

        for (auto task : last_hour) {
            score.add(task.first, task.second);
        }

        mx[name] = score;

        cerr << score;

        cerr << endl;
        cerr << endl;

        pool.insert(name);
    }

    vector<Score> segment;
    set<string> names;



    for (int i = 0; i < k; ++i) {
        Score score = ReadLine();
        segment.push_back(score);
        names.insert(name);
    }

    for (string team : pool){
        if (names.find(team) == names.end()) {
            bool up = true, down = true;
            for (Score score : segment) {
		    	// cout << mx[team] << ' ' << score << '\n';
                up &= mx[team] < score;
                down &= score < mn[team];
            }

            if (!up && !down) {
                cout << "Fake\n";
                exit(0);
            }
        }
    }

    cout << "Leaked\n";
}

int main() {


    read();

    return 0;
}

