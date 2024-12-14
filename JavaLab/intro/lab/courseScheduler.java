public class CourseScheduler {
    public static int maxNonOverlappingCourses(int[][] courses) {
        for (int i = 0; i < courses.length - 1; i++) {
            for (int j = i + 1; j < courses.length; j++) {
                if (courses[i][1] > courses[j][1]) {
                    int[] temp = courses[i];
                    courses[i] = courses[j];
                    courses[j] = temp;
                }
            }
        }
        
        int count = 0;
        int lastEndTime = -1;

        for (int i = 0; i < courses.length; i++) {
            int start = courses[i][0];
            int end = courses[i][1];
            
            if (start >= lastEndTime) {
                count++;
                lastEndTime = end;
            }
        }

        return count;
    }
}
