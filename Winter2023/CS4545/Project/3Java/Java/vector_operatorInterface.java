import java.util.*;

public abstract class vector_operatorInterface {

    public static <T extends Number, U extends Number> List<T> add(List<T> v1, List<U> v2) {
        assert v1.size() == v2.size();
        List<T> ret = new ArrayList<>(v1);
        for (int i = 0; i < ret.size(); ++i) {
            ret.set(i, (T)(Number)(ret.get(i).doubleValue() + v2.get(i).doubleValue()));
        }
        return ret;
    }

    public static <T extends Number> List<T> add(List<T> v1, List<T> v2) {
        return add(v1, v2);
    }

    public static <T extends Number> List<T> subtract(List<T> v1, List<T> v2) {
        assert v1.size() == v2.size();
        List<T> ret = new ArrayList<>(v1);
        for (int i = 0; i < ret.size(); ++i) {
            ret.set(i, (T)(Number)(ret.get(i).doubleValue() - v2.get(i).doubleValue()));
        }
        return ret;
    }

    public static <T extends Number> T dotProduct(List<T> v1, List<T> v2) {
        assert v1.size() == v2.size();
        double ret = 0.0;
        for (int i = 0; i < v1.size(); ++i) {
            ret += v1.get(i).doubleValue() * v2.get(i).doubleValue();
        }
        return (T)(Number)ret;
    }

    public static <T extends Number> List<T> multiply(T num, List<T> v) {
        List<T> ret = new ArrayList<>(v.size());
        for (int i = 0; i < v.size(); ++i) {
            ret.add((T)(Number)(num.doubleValue() * v.get(i).doubleValue()));
        }
        return ret;
    }

    public static <T extends Number> List<T> multiply(List<T> v, T num) {
        return multiply(num, v);
    }

    public static <T extends Number> List<T> divide(List<T> v, T num) {
        List<T> ret = new ArrayList<>(v.size());
        for (int i = 0; i < v.size(); ++i) {
            ret.add((T)(Number)(v.get(i).doubleValue() / num.doubleValue()));
        }
        return ret;
    }

    public static <T extends Number> void printList(List<T> v) {
        if (v.isEmpty()) {
            return;
        }
        System.out.print(v.get(0));
        for (int i = 1; i < v.size(); ++i) {
            System.out.print(", " + v.get(i));
        }
        System.out.println();
    }

}

