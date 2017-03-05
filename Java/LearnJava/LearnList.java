import java.util.*;
import java.util.logging.Logger;
/**
 * LearnList
 */
public class LearnList {
    public static Logger logger = Logger.getLogger(LearnList.class.getName());
    public static void main(String[] args) {
        // 1.array
        int array1[] = new int[10];
        int array2[] = new int[] {1, 2, 3};
        int array3[] = {2, 3, 4};
        logger.info(array1.length + "");
        logger.info(array2.length + "");
        logger.info(array3.length + "");

        // List list = new ArrayList<Integer>();
        // list.add(1);

    }
}