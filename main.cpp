#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 学生结构体
struct Student {
    string id;
    string name;
    string course;
    double score;
};

// 学生信息管理类
class StudentManager {
        public:
        // 添加学生信息
        void addStudent() {
            Student s;
            cout << "请输入学生信息：" << endl;
            cout << "学号：";
            cin >> s.id;
            cout << "姓名：";
            cin >> s.name;
            cout << "课程名：";
            cin >> s.course;
            cout << "成绩：";
            cin >> s.score;
            students.push_back(s);
        }

        // 查询学生信息
        void queryStudent() {
            string id;
            cout << "请输入要查询的学生学号：";
            cin >> id;
            auto it = find_if(students.begin(), students.end(), [&id](const Student& s) {return s.id == id; });
            if (it != students.end()) {
                cout << "学号\t姓名\t课程名\t成绩" << endl;
                cout << it->id << "\t" << it->name << "\t" << it->course << "\t" << it->score << endl;
            }
            else {
                cout << "未找到该学生信息。" << endl;
            }
        }

        // 保存学生信息到文件
        void saveToFile() {
            ofstream ofs("students.txt");
            for (auto& s : students) {
                ofs << s.id << "," << s.name << "," << s.course << "," << s.score << endl;
            }
            ofs.close();
        }

        // 从文件中读取学生信息
        void readFromFile() {
            ifstream ifs("students.txt");
            string line;
            while (getline(ifs, line)) {
                Student s;
                int pos = line.find(",");
                s.id = line.substr(0, pos);
                line = line.substr(pos + 1);
                pos = line.find(",");
                s.name = line.substr(0, pos);
                line = line.substr(pos + 1);
                pos = line.find(",");
                s.course = line.substr(0, pos);
                line = line.substr(pos + 1);
                s.score = stod(line);
                students.push_back(s);
            }
            ifs.close();
        }

        private:
        vector<Student> students; // 学生信息容器
};

int main() {
    StudentManager sm;
    sm.readFromFile(); // 从文件中读取学生信息
    while (true) {
        cout << "学生成绩管理系统" << endl;
        cout << "1. 添加学生信息" << endl;
        cout << "2. 查询学生信息" << endl;
        cout << "3. 保存学生信息到文件" << endl;
        cout << "4. 退出程序" << endl;
        int choice;
        cout << "请选择操作：";
        cin >> choice;
        switch (choice) {
            case 1:
                sm.addStudent();
                break;
            case 2:
                sm.queryStudent();
                break;
            case 3:
                sm.saveToFile();
                break;
            case 4:
                sm.saveToFile(); // 退出程序前保存学生信息到文件
        }
        // 删除学生成绩信息
    void deleteScore(vector <Score>&scores) {
        string id;
        cout << "请输入要删除学生成绩的学号：";
        cin >> id;
        bool found = false;
        for (auto it = scores.begin();
        it != scores.end();
        it++) {
            if (it->id == id) {
                found = true;
                scores.erase(it);
                break;
            }
        }
        if (found) {
            cout << "删除成功！" << endl;
        } else {
            cout << "未找到该学号的学生成绩！" << endl;
        }
    }

// 查询学生成绩信息
    void queryScore(const vector <Score>&scores) {
        string id;
        cout << "请输入要查询学生成绩的学号：";
        cin >> id;
        bool found = false;
        for (auto it = scores.begin();
        it != scores.end();
        it++) {
            if (it->id == id) {
                found = true;
                cout << "学号\t姓名\t课程\t平时成绩\t期末成绩\t总评成绩" << endl;
                cout << it->id << "\t" << it->name << "\t" << it->course << "\t" << it->usualScore << "\t"
                     << it->examScore << "\t" << it->finalScore << endl;
                break;
            }
        }
        if (!found) {
            cout << "未找到该学号的学生成绩！" << endl;
        }
    }

// 保存学生成绩信息到文件
    void saveScoreToFile(const vector <Score>
    &scores) {
        ofstream
        outfile("score.txt");
        if (!outfile.is_open()) {
            cout << "打开文件失败！" << endl;
            return;
        }
        for (auto it = scores.begin();
        it != scores.end();
        it++) {
            outfile << it->id << " " << it->name << " " << it->course << " " << it->usualScore << " " << it->examScore
                    << " " << it->finalScore << endl;
        }
        outfile.close();
        cout << "保存成功！" << endl;
    }
    int main() {
        vector <Score> scores;
        loadScoreFromFile(scores);
        int choice;
        do {
            cout << "-------------------------" << endl;
            cout << "学生成绩管理系统" << endl;
            cout << "1. 录入学生成绩" << endl;
            cout << "2. 删除学生成绩" << endl;
            cout << "3. 浏览学生成绩" << endl;
            cout << "4. 查询学生成绩" << endl;
            cout << "5. 保存学生成绩到文件" << endl;
            cout << "6. 退出系统" << endl;
            cout << "请输入你的选择（1-6）：";
            cin >> choice;
            switch (choice) {
                case 1:
                    addScore(scores);
                    break;
                case 2:
                    deleteScore(scores);
                    break;
                case 3:
                    listScore(scores);
                    break;
                case 4:
                    queryScore(scores);
                    break;
                case 5:
                    saveScoreToFile(scores);
                    break;
                case 6:
                    cout << "谢谢使用！" << endl;
                    break;
            }
        }
    }
}