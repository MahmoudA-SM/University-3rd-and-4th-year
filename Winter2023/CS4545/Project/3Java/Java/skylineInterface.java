import java.util.*;

public interface skylineInteface {

    float minDist(float[] p1, float[] p2, int dimen);

    void aggregateRecords(Rtree a_rtree);

    int countRecords(Rtree a_rtree, int pageID);

    boolean dominatedByK(int dimen, float[] pt, ArrayList<Long> kskyband, float[][] PG, int k);

    boolean dominatedByK_noSL(int dimen, float[] pt, ArrayList<Long> kskyband, float[][] PG, int k);

    void kskyband(int dimen, Rtree a_rtree, ArrayList<Long> kskyband, float[][] PG, int k);

    void rtreeRAM(Rtree rt, HashMap<Long, RtreeNode> ramTree);
}
