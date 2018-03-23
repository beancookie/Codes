import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.HashMap;
import java.util.Iterator;
import java.util.TreeSet;

class Main {
    static class Stu {
        String id, schoolName;
        double grade;

        public Stu(String id, double grade, String schoolName) {
            this.id = id;
            this.grade = grade;
            this.schoolName = schoolName;
        }
    }

    static class School implements Comparable<School> {
        String schoolName;
        Double totalGrade;
        Integer stuNum;

        public School(String schoolName, double totalGrade, int stuNum) {
            this.schoolName = schoolName;
            this.totalGrade = totalGrade;
            this.stuNum = stuNum;
        }

        @Override
        public int compareTo(School o) {    
            if (!totalGrade.equals(o.totalGrade))
                return o.totalGrade.compareTo(totalGrade);
            else if (!stuNum.equals(o.stuNum))
                return stuNum.compareTo(o.stuNum);
            else
                return schoolName.compareTo(o.schoolName);
        }

        @Override
        public boolean equals(Object obj) {
            School other = (School)obj;
            return schoolName.equals(other.schoolName);
        }

        @Override
        public int hashCode() {
            return schoolName.hashCode();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<String, School> map = new HashMap<String, School>();
        
        for (int i = 0; i < n; ++i)
        {
            double grade = 0;
            Stu stu = new Stu(sc.next(), sc.nextInt(), sc.next().toLowerCase());
            if (stu.id.charAt(0) == 'B')
                grade = stu.grade / 1.5;
            else if (stu.id.charAt(0) == 'A')
                grade = stu.grade;
            else 
                grade = stu.grade * 1.5;
            School tmp = map.get(stu.schoolName);
            if (tmp == null)
                map.put(stu.schoolName, new School(stu.schoolName, grade, 1));
            else 
            {
                tmp.totalGrade += grade;
                tmp.stuNum++;
                map.put(stu.schoolName, tmp);
            }
        }
        TreeSet<School> schools = new TreeSet<>();
        
        for (Stirng schoolName : map.keySet()) {
            School school = map.get(schoolName);
            schools.add(new School(school.schoolName, school.totalGrade, school.stuNum));
        }

        // Iterator it = map.entrySet().iterator();
        // while (it.hasNext()) {
        //     Map.Entry<String, School> entry = (Map.Entry<String, School>)it.next();
        //     schools.add(new School(entry.getKey(), entry.getValue().totalGrade, entry.getValue().stuNum));
        // }

        System.out.println(schools.size());
        int cnt = 1, i = 1;
        int befGrade = schools.first().totalGrade.intValue();
        for (School school : schools) {
            if (befGrade != school.totalGrade.intValue())
                cnt = i;
            befGrade = school.totalGrade.intValue();
            i++;
            System.out.println(cnt + " " + school.schoolName + " " + school.totalGrade.intValue() + " " + school.stuNum);
        }
    }
}