import java.util.*;
import java.util.List;

public class case_study implements case_study_interface{
    public static double jaccard(Set<Integer> a, Set<Integer> b) {
    // jaccard similarity
    Set<Integer> all = new HashSet<Integer>(a);
    all.addAll(b);
    double cnt = 0;
    for (int bi : b) {
        if (a.contains(bi)) {
            cnt++;
        }
    }
    return cnt / all.size();
    }

    public static double jaccard(List<Integer> ab, List<Integer> ae, List<Integer> bb, List<Integer> be) {
    // \para ab iterable a begin
    // \para ae iterable a end
    // \para bb iterable b begin
    // \para be iterable b end

    // jaccard similarity
    Set<Integer> a = new HashSet<Integer>(ab.subList(0, ae));
    Set<Integer> b = new HashSet<Integer>(bb.subList(0, be));
    return jaccard(a, b);
    }

public static double precision(List<Integer> gtb, List<Integer> gte, List<Integer> rb, List<Integer> re) {
    Set<Integer> gt = new HashSet<Integer>(gtb.subList(0, gte));
    Set<Integer> r = new HashSet<Integer>(rb.subList(0, re));
    return precision(gt, r);
}

public static double precision(Set<Integer> groundTruth, Set<Integer> result) {
    int TP = 0;
    for (int r : result) {
        if (groundTruth.contains(r)) {
            TP++;
        }
    }
    return (double) TP / result.size();
}

public static double recall(List<Integer> gtb, List<Integer> gte, List<Integer> rb, List<Integer> re) {
    Set<Integer> gt = new HashSet<Integer>(gtb.subList(0, gte));
    Set<Integer> r = new HashSet<Integer>(rb.subList(0, re));
    return recall(gt, r);
}

public static double recall(Set<Integer> groundTruth, Set<Integer> result) {
    int TP = 0;
    for (int r : result) {
        if (groundTruth.contains(r)) {
            TP++;
        }
    }
    return (double) TP / groundTruth.size();
}



public static int total_do_cnt(Map<Integer, Set<Integer>> do_id, List<Integer> test_this) {
    Set<Integer> s = new HashSet<>();
    for (int i : test_this) {
        Set<Integer> ids = do_id.get(i);
        if (ids != null) {
            for (int j : ids) {
                s.add(j);
            }
        }
    }
    return s.size();
}




public List<Integer> OSS_skyline(int objCnt, int r, Rtree rtree, float[][] PointSet, int dim) {
    List<Long> one_skyband = new ArrayList<>();
    kskyband(dim, rtree, one_skyband, PointSet, 1);

    // build dominate relations
    Map<Integer, Set<Integer>> do_id = new HashMap<>();
    for (long id : one_skyband) {
        do_id.put((int)id, new HashSet<>());
    }
    for (long id : one_skyband) {
        for (int i = 1; i <= objCnt; ++i) {
            if (i == id) {
                continue;
            }
            if (v1_dominate_v2(PointSet[(int)id], PointSet[i], dim)) {
                do_id.get((int)id).add(i);
            }
        }
    }

    // select r from n do combination and check total dominate cnt (TDC)
    // return the combination with maximal TDC
    // This will generate correct result for OSS-skyline, but a brute force solution
    // This is practical fast since 1-skyline is small when d is small
    int n = one_skyband.size();
    boolean[] v = new boolean[n];
    Arrays.fill(v, 0, r, true);

    int max_tdo = 0;
    ArrayList<Integer> best_cb = new ArrayList<>();
    do {
        ArrayList<Integer> one_cb = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (v[i]) {
                one_cb.add((int)one_skyband.get(i));
            }
        }
        int cur = total_do_cnt(do_id, one_cb);
        if (cur > max_tdo) {
            max_tdo = cur;
            best_cb = one_cb;
        }
    } while (prev_permutation(v));

    return best_cb;
}

public static boolean prev_permutation(boolean[] array) {
    int i = array.length - 1;
    while (i > 0 && !array[i - 1] && array[i]) {
        --i;
    }

    if (i <= 0) {
        return false;
    }

    int j = array.length - 1;
    while (j >= i && !array[j]) {
        --j;
    }

    boolean tmp = array[i - 1];
    array[i - 1] = array[j];
    array[j] = tmp;

    j = array.length - 1;
    while (i < j) {
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
        ++i;
        --j;
    }

    return true;
}

}