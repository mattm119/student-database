class database
{
private:
    char studentName[];
    char studentID[];
    char year[];
    char department[];
    double midterm;
    double finalgrade;
    double examAVG;
    double hw1;
    double hw2;
    double hw3;
    double hwAVG;
    double attendance;
    double project;
    double overallGrade;
    std::string letterGrade;
    
public:
    database();
    ~database();
    void fileCreate(char fileName[]);
    void add(char fileName[]);
    void search(char filename[], std::string key);
    double averageExam(double x, double y);
    double averageHW(double x, double y, double z);
    double overall(double a, double b, double c, double d);
    std::string lettergrade(double myoverallgrade);
};