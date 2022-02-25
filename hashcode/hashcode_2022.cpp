#include <bits/stdc++.h>
#define INPUT_FILE "a_an_example.in.txt"
#define OUTPUT_FILE "a_an_example.out.txt"
using namespace std;

class Contributor {
   public:
    string name;
    int nos;
    unordered_map<string, int> skills;
    Contributor(string name, int nos) {
        this->name = name;
        this->nos = nos;
    }
    void add_skill(string skill, int level) { skills[skill] = level; }
};

class Project {
   public:
    string name;
    int D;  // the number of days it takes to complete the project,
    int S;  // the score awarded for project’s completion,
    int B;  // the “best before” day for the project,
    int R;  // the number of roles in the project.

    unordered_map<string, int> roles;
    Project(string name, int D, int S, int B, int R) {
        this->name = name;
        this->D = D;
        this->S = S;
        this->B = B;
        this->R = R;
    }
    void add_role(string role, int level) { roles[role] = level; }
};

void calculate_score(Contributor con, Project pro, int c, int p) {}

int main() {
    ifstream infile(INPUT_FILE);
    ofstream outfile(OUTPUT_FILE);
    int C, P;
    infile >> C >> P;
    vector<Contributor> contributers;
    vector<Project> projects;

    for (int i = 0; i < C; i++) {
        string name;
        int nos;
        infile >> name >> nos;
        Contributor contributer(name, nos);
        for (int j = 0; j < nos; j++) {
            string skill;
            int level;
            infile >> skill >> level;
            contributer.add_skill(skill, level);
        }

        contributers.push_back(contributer);
    }

    for (int i = 0; i < P; i++) {
        string name;
        int D;
        int S;
        int B;
        int R;
        infile >> name >> D >> S >> B >> R;
        Project project(name, D, S, B, R);
        for (int j = 0; j < R; j++) {
            string role;
            int level;
            infile >> role >> level;
            project.add_role(role, level);
        }

        projects.push_back(project);
    }

    outfile << C << " " << contributers.size() << " " << P << " "
            << projects.size() << endl;
    return 0;
}
